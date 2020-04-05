#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//must double
//写的复杂
struct chain
{
    int NUM;
    int *NO;
    int layer;
};
int bfs(int node, chain *CHAIN, int visit[], int N)
{
    int i, next, layer, index_i = 0, index_j = 0;
    int *Queue = (int *)malloc(N * sizeof(int));
    Queue[0] = node;
    while (index_j < N and index_i <= index_j)
    {
        node = Queue[index_i];
        layer = CHAIN[node].layer + 1;
        for (i = 0; i < CHAIN[node].NUM; i++)
        {
            next = CHAIN[node].NO[i];
            if (visit[next] == 0)
            {
                visit[next] = 1;
                CHAIN[next].layer = layer;
                if (CHAIN[next].NUM)
                {
                    index_j++;
                    Queue[index_j] = next;
                }
            }
        }
        index_i++;
    }
    return 1;
}
int main()
{
    int i, j, count, N;
    int *visit;
    double P, R;
    chain *CHAIN;
    scanf("%d %lf %lf", &N, &P, &R);
    CHAIN = (chain *)malloc(N * sizeof(chain));
    visit = (int *)malloc(N * sizeof(int));
    for (i = 0; i < N; i++)
    {
        scanf("%d", &CHAIN[i].NUM);
        if (CHAIN[i].NUM)
        {
            CHAIN[i].NO = (int *)malloc(CHAIN[i].NUM * sizeof(int));
            for (j = 0; j < CHAIN[i].NUM; j++)
                scanf("%d", &CHAIN[i].NO[j]);
        }
        CHAIN[i].layer = N + 2;
        visit[i] = 0;
    }
    //SOLVE
    visit[0] = 1;
    CHAIN[0].layer = 1;
    bfs(0, CHAIN, visit, N);
    j = N + 1; //min
    count = 0;
    for (i = 0; i < N; i++)
    {

        if (CHAIN[i].NUM == 0 && CHAIN[i].layer < j)
        {
            j = CHAIN[i].layer;
            count = 1;
        }
        else if (CHAIN[i].NUM == 0 && CHAIN[i].layer == j)
            count++;
    }
    printf("%.4lf %d", P * pow((1 + R / 100), (j - 1)), count);
    return 0;
}