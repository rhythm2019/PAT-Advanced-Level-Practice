#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100000
//1085 Perfect Sequence (25分)
//DATE:20201008
int cmpfunc(const void *a, const void *b)
{
    return *(long long *)a - *(long long *)b;
}
int main()
{
    long long i, j, N, p, begin, A[MAXSIZE];
    long long MaxL = 0;
    scanf("%lld %lld", &N, &p);
    for (i = 0; i < N; i++)
        scanf("%lld", A + i);
    qsort(A, N, sizeof(long long), cmpfunc);
    if (A[0] * p >= A[N - 1])
    {
        printf("%lld", N);
        return (0);
    }
    //solve
    begin = N - 1;
    while (A[begin] > A[0] * p)
        begin--;
    MaxL = begin + 1;
    for (i = 1; i < N && begin < N; i++)
    {
        while (begin < N && A[begin] <= A[i] * p)
            begin++;
        if (begin - i > MaxL)
            MaxL = begin - i;
    }
    printf("%lld", MaxL);
    return (0);
}