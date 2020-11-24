//1154 1154 Vertex Coloring (25分)
//DATE:20201124
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 10000
int cmpfunc(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}
int EDGE[MAXSIZE][2], VERTEX[MAXSIZE];
int main()
{
    int i, j, flag, N, M, K, COUNT, n1, n2;
    scanf("%d %d", &N, &M);
    for (i = 0; i < M; i++)
        scanf("%d %d", &EDGE[i][0], &EDGE[i][1]);
    scanf("%d", &K);
    for (i = 0; i < K; i++)
    {
        //init
        for (j = 0; j < N; j++)
            scanf("%d", VERTEX + j);
        //judge
        flag = 0;
        for (j = 0; j < M; j++)
        {
            n1 = EDGE[j][0];
            n2 = EDGE[j][1];
            if (VERTEX[n1] == VERTEX[n2])
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            qsort(VERTEX, N, sizeof(int), cmpfunc);
            COUNT = 1;
            for (j = 1; j < N; j++)
            {
                if (VERTEX[j] != VERTEX[j - 1])
                    COUNT++;
            }
            printf("%d-coloring\n", COUNT);
        }
        else
            printf("No\n", COUNT);
    }
    return 0;
}