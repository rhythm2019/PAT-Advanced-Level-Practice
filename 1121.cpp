#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <string.h>

//1121
int cmpfunc(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}
int main()
{
    int COUP[100000] = {-1}, arrival[100000] = {0};
    int N, i, j, count = 0, *arr;
    int g1, g2;
    scanf("%d", &N);
    for (i = 0; i < N; i++)
    {
        scanf("%d %d", &g1, &g2);
        COUP[g1] = g2;
        COUP[g2] = g1;
    }
    scanf("%d", &N);
    arr = (int *)malloc(N * sizeof(int));
    for (i = 0; i < N; i++)
    {
        scanf("%d", &g1);
        arrival[g1] = 1;
        arr[i] = g1;
    }
    i = 0;
    while (i < N)
    {
        if (COUP[arr[i]] != -1 and arrival[COUP[arr[i]]])
        {
            for (j = i; j < N - 1; j++)
                arr[j] = arr[j + 1];
            N--;
        }
        else
        {
            i++;
            count++;
        }
    }
    qsort(arr, count, sizeof(int), cmpfunc);
    printf("%d\n", count);
    if (count)
    {
        for (i = 0; i < count - 1; i++)
            printf("%05d ", arr[i]);
        printf("%05d", arr[i]);
    }
    return 0;
}
