//1111 Online Map (30分)
//DATE:20201015
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 500
typedef struct NODE *node;
struct NODE
{
    int NO;
    int distance;
    int time;
    node next;
};
struct GRAPH
{
    int N;
    struct NODE *GG;
};
void init_Graph(struct GRAPH *G)
{
    int i;
    if (G->N > 0)
    {
        G->GG = (struct NODE *)malloc(G->N * sizeof(struct NODE));
        for (i = 0; i < G->N; i++)
            G->GG[i] = {0, 0, 0, NULL};
    }
    return;
}
void Dik(int n1, int n2, struct GRAPH G, int *visit, int *value, int *shortdis, int *path)
{
    int i, curnode, nextnode, minindex, lay = 0, layer[MAXSIZE] = {0};
    node cur;
    struct PATH *tmp1;
    for (i = 0; i < G.N; i++)
    {
        shortdis[i] = 0;
        visit[i] = 0;
        value[i] = 0;
        path[i] = -1;
    }
    shortdis[n1] = 0;
    curnode = n1;
    while (1)
    {
        visit[curnode] = 1;
        if (curnode == n2)
            break;
        cur = G.GG[curnode].next;
        while (cur)
        {

            nextnode = cur->NO;
            if (shortdis[nextnode] == 0 || shortdis[nextnode] > shortdis[curnode] + cur->distance)
            {
                shortdis[nextnode] = shortdis[curnode] + cur->distance;
                path[nextnode] = curnode;
                value[nextnode] = value[curnode] + cur->time;
                layer[nextnode] = layer[curnode] + 1;
            }
            else if (shortdis[nextnode] == shortdis[curnode] + cur->distance && value[nextnode] > value[curnode] + cur->time)
            {
                path[nextnode] = curnode;
                value[nextnode] = value[curnode] + cur->time;
                layer[nextnode] = layer[curnode] + 1;
            }
            else if (shortdis[nextnode] == shortdis[curnode] + cur->distance && value[nextnode] == value[curnode] + cur->time && layer[nextnode] > layer[curnode] + 1)
            {
                path[nextnode] = curnode;
                value[nextnode] = value[curnode] + cur->time;
                layer[nextnode] = layer[curnode] + 1;
            }
            cur = cur->next;
        }
        // find min distance
        minindex = -1;
        for (i = 0; i < G.N; i++)
        {
            if (visit[i] == 0 && shortdis[i])
                if (minindex == -1 || shortdis[i] < shortdis[minindex])
                    minindex = i;
        }
        curnode = minindex;
    }
    return;
}
int main()
{
    int i, j, j1, j2, r1, r2, k, n1, n2, oneway, dis, t, N, M;
    int visit[MAXSIZE], shortdis[MAXSIZE], value[MAXSIZE], result01[MAXSIZE], result02[MAXSIZE], path[MAXSIZE];
    struct GRAPH G;
    node cur;
    scanf("%d %d", &N, &M);
    G.N = N;
    init_Graph(&G);
    for (i = 0; i < M; i++)
    {
        scanf("%d %d %d %d %d", &n1, &n2, &oneway, &dis, &t);
        cur = (node)malloc(sizeof(struct NODE));
        cur->NO = n2;
        cur->distance = dis;
        cur->time = t;
        cur->next = G.GG[n1].next;
        G.GG[n1].next = cur;
        if (oneway == 0)
        {
            cur = (node)malloc(sizeof(struct NODE));
            cur->NO = n1;
            cur->distance = dis;
            cur->time = t;
            cur->next = G.GG[n2].next;
            G.GG[n2].next = cur;
        }
    }
    scanf("%d %d", &n1, &n2);
    //solve
    Dik(n1, n2, G, visit, value, shortdis, path);
    i = n2;
    j1 = 0;
    r1 = shortdis[n2];
    while (i != n1)
    {
        result01[j1++] = i;
        i = path[i];
    }
    result01[j1++] = n1;
    //**********
    for (i = 0; i < G.N; i++)
    {
        cur = G.GG[i].next;
        while (cur)
        {
            cur->distance = cur->time;
            cur->time = 0;
            cur = cur->next;
        }
    }
    Dik(n1, n2, G, visit, value, shortdis, path);
    i = n2;
    j2 = 0;
    r2 = shortdis[n2];
    while (i != n1)
    {
        result02[j2++] = i;
        i = path[i];
    }
    result02[j2++] = n1;
    //print
    k = 1;
    if (j1 == j2)
    {
        for (i = 0; i < j1; i++)
            if (result01[i] != result02[i])
            {
                k = 0;
                break;
            }
    }
    else
        k = 0;

    if (k == 0)
    {
        printf("Distance = %d: %d", r1, n1);
        for (i = j1 - 2; i >= 0; i--)
            printf(" -> %d", result01[i]);
        printf("\n");
        printf("Time = %d: %d", r2, n1);
        for (i = j2 - 2; i >= 0; i--)
            printf(" -> %d", result02[i]);
    }
    else
    {
        printf("Distance = %d; Time = %d: %d", r1, r2, n1);
        for (i = j1 - 2; i >= 0; i--)
            printf(" -> %d", result01[i]);
    }
    return 0;
}