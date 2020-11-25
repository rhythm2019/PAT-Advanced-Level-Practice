//1122 Hamiltonian Cycle (25分)
//DATE:20200824
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 200
int main()
{
    int i, j, n1, n2, N, M, Q, K, Flag;
    int G[MAXSIZE][MAXSIZE] = {0}, A[MAXSIZE + 1], visit[MAXSIZE];
    scanf("%d %d", &N, &M);
    for (i = 0; i < M; i++)
    {
        scanf("%d %d", &n1, &n2);
        G[n1 - 1][n2 - 1] = 1;
        G[n2 - 1][n1 - 1] = 1;
    }
    scanf("%d", &Q);
    for (i = 0; i < Q; i++)
    {
        Flag = 1;
        scanf("%d", &K);
        if (K == N + 1)
        {
            for (j = 0; j < N; j++)
                visit[j] = 0;
            for (j = 0; j < K; j++)
            {
                scanf("%d", A + j);
                visit[A[j] - 1] = 1;
            }
        }
        else
        {
            for (j = 0; j < K; j++)
                scanf("%d", &n1);
            Flag = 0;
        }
        if (Flag && A[0] != A[N])
            Flag = 0;
        if (Flag)
            for (j = 0; j < N; j++)
                if (visit[j] == 0)
                {
                    Flag = 0;
                    break;
                }
        if (Flag)
            for (j = 0; j < K - 1; j++)
                if (G[A[j] - 1][A[j + 1] - 1] == 0)
                {
                    Flag = 0;
                    break;
                }
        if (Flag)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}