#include <stdio.h>
#include <stdlib.h>
//1113 Integer Set Partition (25分)
//DATE:20200813
int cmpfunc(const void *a, const void *b)
{
    return (*(int *)b - *(int *)a);
}
int main()
{
    int A[100000], N, i;
    int S1 = 0, S2 = 0;
    scanf("%d", &N);
    for (i = 0; i < N; i++)
        scanf("%d", &A[i]);
    qsort(A, N, sizeof(int), cmpfunc);
    for (i = 0; i <= (N - 1) / 2; i++)
        S1 += A[i];
    for (i = (N - 1) / 2 + 1; i < N; i++)
        S2 += A[i];
    printf("%d %d", N % 2 ? 1 : 0, S1 - S2);
    return 0;
}