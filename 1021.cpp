#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
//1021 Deepest Root
//DATE:20200825
struct VERTEX
{
    int node;
    struct VERTEX *next;
};
void dfs(int node, struct VERTEX *Graph, int *visit, int layer, struct VERTEX *D1, int *max_layer)
{
    visit[node] = 1;
    struct VERTEX *cur = Graph[node].next, *curD, *tmp;
    if (cur == NULL)
        return;
    layer++;
    while (cur)
    {
        if (visit[cur->node] == 0)
        {
            visit[cur->node] = 1;
            if (layer > *max_layer)
            {
                *max_layer = layer;
                D1->node = cur->node;
                curD = D1->next;
                while (curD)
                {
                    tmp = curD->next;
                    free(curD);
                    curD = tmp;
                }
                D1->next = NULL;
            }
            else if (layer == *max_layer)
            {
                curD = D1;
                while (curD->next)
                    curD = curD->next;
                curD->next = (struct VERTEX *)malloc(sizeof(struct VERTEX));
                curD = curD->next;
                curD->node = cur->node;
                curD->next = NULL;
            }
            dfs(cur->node, Graph, visit, layer, D1, max_layer);
        }
        cur = cur->next;
    }
    layer--;
    return;
}
int insertNode(int c1, int c2, struct VERTEX *Graph)
{
    struct VERTEX *cur = (struct VERTEX *)malloc(sizeof(struct VERTEX));
    cur->node = c2;
    cur->next = Graph[c1].next;
    Graph[c1].next = cur;
    return 1;
}
int main()
{
    int i, N, c1, c2, max_layer;
    int count = 0, *visit;
    struct VERTEX *Graph, D1 = {-1, NULL}, D2 = {-1, NULL}, *curD1, *curD2;
    scanf("%d", &N);
    if (N == 1)
    {
        printf("1\n");
        return (0);
    }
    //create Graph
    Graph = (struct VERTEX *)malloc((N + 1) * sizeof(struct VERTEX));
    visit = (int *)malloc((N + 1) * sizeof(int));
    for (i = 0; i < N + 1; i++)
    {
        Graph[i].node = -1;
        Graph[i].next = NULL;
        visit[i] = 0;
    }
    for (i = 0; i < N - 1; i++)
    {
        scanf("%d %d", &c1, &c2);
        insertNode(c1, c2, Graph);
        insertNode(c2, c1, Graph);
    }
    //dfs and SOLVE
    max_layer = -1;
    for (i = 1; i < N + 1; i++)
        if (visit[i] == 0)
        {
            count++;
            dfs(i, Graph, visit, 0, &D1, &max_layer);
        }
    //search
    if (count != 1)
    {
        printf("Error: %d components", count);
        return (0);
    }
    else
    {
        for (i = 0; i < N + 1; i++)
            visit[i] = 0;
        max_layer--;
        dfs(D1.node, Graph, visit, 0, &D2, &max_layer);
        curD1 = &D1;
        curD2 = &D2;
        for (i = 0; i < N + 1; i++)
            visit[i] = 0;
        while (curD1 && curD1->node != -1)
        {
            visit[curD1->node] = 1;
            curD1 = curD1->next;
        }
        while (curD2 && curD2->node != -1)
        {
            visit[curD2->node] = 1;
            curD2 = curD2->next;
        }
        count = 0;
        for (i = 1; i < N + 1; i++)
            if (visit[i] && count++ == 0)
                printf("%d", i);
            else if (visit[i])
                printf("\n%d", i);
        return (0);
    }
}