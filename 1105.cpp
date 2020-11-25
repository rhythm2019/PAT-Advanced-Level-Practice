#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//1105 Spiral Matrix (25分)
//DATE:20200820
int cmpfunc(const void *a, const void *b)
{
    return (*(int *)b - *(int *)a);
}
int main()
{
    int i, j = 0, k = -1, m, n, ii;
    int N, *lst01, **lst02;
    int row, column;
    scanf("%d", &N);
    lst01 = (int *)malloc(N * sizeof(int));
    for (i = 0; i < N; i++)
        scanf("%d", lst01 + i);
    qsort(lst01, N, sizeof(int), cmpfunc);
    column = int(pow(N, 0.5));
    while (column > 0)
    {
        if (N % column == 0)
        {
            row = N / column;
            break;
        }
        column--;
    }
    lst02 = (int **)malloc(row * sizeof(int *));
    for (i = 0; i < row; i++)
        lst02[i] = (int *)malloc(column * sizeof(int));
    //direction
    m = row;
    n = column;
    i = 0;
    while (i < N && m && n)
    {
        for (ii = 0; ii < n; ii++)
            lst02[j][++k] = lst01[i++];
        for (ii = 0; ii < m - 1; ii++)
            lst02[++j][k] = lst01[i++];
        for (ii = 0; ii < n - 1; ii++)
            lst02[j][--k] = lst01[i++];
        for (ii = 0; ii < m - 2 && i < N; ii++)//存在特例,3X1
            lst02[--j][k] = lst01[i++];
        m = m - 2;
        n = n - 2;
    }
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < column - 1; j++)
            printf("%d ", lst02[i][j]);
        printf("%d\n", lst02[i][j]);
    }
    return (0);
}