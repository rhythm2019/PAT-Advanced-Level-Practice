#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 400
//1103 Integer Factorization (30分)
//DATE:20200820
int VALUE[MAXSIZE][8];
void Factor(int N, int K, int P, int begin, int *lst01, int *result, int *Flag)
{
    static int MAXSUM = 0;
    int i, MAXele = 0, cmp = 0;
    int newN, newK;    
    if (K < 0 || begin > N || K * VALUE[begin][P] > N)
        return;
    else if (K * VALUE[begin][P] == N)
    {
        *Flag = 1;
        lst01[begin] = K;
        for (i = 1; i <= MAXSIZE; i++)
        {
            MAXele += lst01[i] * i;
            if (cmp == 0 && lst01[i] < result[i])
                cmp = 1;
            else if (cmp == 0 && lst01[i] > result[i])
                cmp = -1;
        }
        if (MAXele > MAXSUM || (MAXele == MAXSUM && cmp == 1))
        {
            MAXSUM = MAXele;
            for (i = 0; i <= MAXSIZE; i++)
                result[i] = lst01[i];
        }
    }
    else
        for (i = K; i >= 0; i--)
        {
            newN = N - i * VALUE[begin][P];
            newK = K - i;
            lst01[begin] = i;
            Factor(newN, newK, P, begin + 1, lst01, result, Flag);
        }
    return;
}
int main()
{
    int i, j, kk;
    int N, K, P, lst01[MAXSIZE + 1] = {0}, result[MAXSIZE + 1] = {0};
    int Flag = 0;
    scanf("%d %d %d", &N, &K, &P);
    for (i = 1; i < N + 1; i++)
        VALUE[i][0] = 1;
    for (i = 1; i < N + 1; i++)
        for (j = 1; j < P + 1; j++)
            VALUE[i][j] = VALUE[i][j - 1] * i;
    Factor(N, K, P, 1, lst01, result, &Flag);
    if (Flag == 0)
        printf("Impossible");
    else
    {
        printf("%d = ", N);
        i = 0;
        j = N;
        while (i < K && j > 0)
        {
            for (kk = result[j]; kk > 0; kk--)
            {
                if (i < K - 1)
                    printf("%d^%d + ", j, P);
                else
                    printf("%d^%d", j, P);
                i++;
            }
            j--;
        }
    }
    return (0);
}