#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 50000
#define KMAX 10
//1129 Recommendation System (25分)
//DATE:20201007
int main()
{
    int i, j, kk, data, end, N, K, IN[MAXSIZE], A[MAXSIZE + 1] = {0}, MAXrecomm[KMAX] = {0};
    scanf("%d %d", &N, &K);
    for (i = 0; i < N; i++)
        scanf("%d", IN + i);
    A[IN[0]] = 1;
    MAXrecomm[0] = IN[0];
    for (i = 1; i < N; i++)
    {
        data = IN[i];
        printf("%d: %d", data, MAXrecomm[0]);
        for (j = 1; j < K; j++)
        {
            if (MAXrecomm[j] == 0)
                break;
            printf(" %d", MAXrecomm[j]);
        }
        printf("\n");
        //solve
        A[data]++;
        end = K - 1;
        for (j = end; j >= 0; j--)
        {
            if (A[data] < A[MAXrecomm[j]] || (A[data] == A[MAXrecomm[j]] && data > MAXrecomm[j]))
                break;
            if (data == MAXrecomm[j])
                end = j;
        }
        for (kk = end; kk > j + 1; kk--)
            MAXrecomm[kk] = MAXrecomm[kk - 1];
        if (j < end)
            MAXrecomm[j + 1] = data;
    }
    return (0);
}