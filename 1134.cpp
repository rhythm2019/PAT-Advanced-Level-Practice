#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 10005
#define SIZE 10
//1134 Vertex Cover (25分)
//DATE:20201007
struct VERTEX
{
    int Edge[SIZE];
    struct VERTEX *next;
};
int V_EDGE_NUM[MAXSIZE] = {0};
struct VERTEX vertex[MAXSIZE];
int visit[MAXSIZE] = {0};
void push_edge(int v1, int i)
{
    struct VERTEX *cur = &(vertex[v1]);
    while (cur->next)
        cur = cur->next;
    if (V_EDGE_NUM[v1] && V_EDGE_NUM[v1] % SIZE == 0)
    {
        cur->next = (struct VERTEX *)malloc(sizeof(struct VERTEX));
        cur->next->next = NULL;
        cur->next->Edge[0] = i;
    }
    else
        cur->Edge[V_EDGE_NUM[v1] % SIZE] = i;
    (V_EDGE_NUM[v1])++;
    return;
}

int main()
{
    int i, j, k, M, N, KK, n1, n2, count;
    struct VERTEX *cur;
    scanf("%d %d", &N, &M);
    for (i = 0; i < N; i++)
        vertex[i].next = NULL;
    for (i = 0; i < M; i++)
    {
        scanf("%d", &n1);
        push_edge(n1, i);
        scanf("%d", &n1);
        push_edge(n1, i);
    }
    scanf("%d", &KK); //query
    //solve
    for (i = 0; i < KK; i++)
    {
        count = 0;
        for (j = 0; j < M; j++)
            visit[j] = 0;
        scanf("%d", &j);
        while (j > 0)
        {
            j--;
            scanf("%d", &n1);
            cur = vertex + n1;
            for (k = 0; k < V_EDGE_NUM[n1]; k++)
            {
                if (k && k % SIZE == 0)
                    cur = cur->next;
                n2 = cur->Edge[k % SIZE];
                if (visit[n2] == 0)
                {
                    visit[n2] = 1;
                    count++;
                }
            }
        }
        if (count < M)
            printf("No\n");
        else
            printf("Yes\n");
    }
    return (0);
}