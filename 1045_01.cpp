//1045 Favorite Color Stripe (30分)
//DATE:20200903
//需要DP
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 200
int main()
{
    int i, j, NNode, M, L, MaxL = 0, Level[MAXSIZE + 1] = {0}, A[10000], DP[10000] = {0};
    scanf("%d", &NNode);
    scanf("%d", &M);
    for (i = 0; i < M; i++)
    {
        scanf("%d", &j);
        Level[j] = i + 1;
    }
    scanf("%d", &j);
    L = 0;
    for (i = 0; i < j; i++)
    {
        scanf("%d", A + L);
        if (Level[A[L]])
        {
            A[L] = Level[A[L]];
            L++;
        }
    }
    for (i = 0; i < L; i++)
    {
        DP[i] = 1;
        for (j = 0; j < i; j++)
        {
            if (A[i] >= A[j] && DP[j] + 1 > DP[i])
                DP[i] = DP[j] + 1;
        }
        if (DP[i] > MaxL)
            MaxL = DP[i];
    }
    printf("%d", MaxL);
    return 0;
}