//1045 Favorite Color Stripe (30分)
//DATE:20200901
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 200
int judge(int A[], int n1, int n2, int level, int LEVEL[])
{
    int m1, m2;
    if (n1 > n2)
        return (0);
    if (LEVEL[A[n1]] < level)
        return (judge(A, n1 + 1, n2, level, LEVEL));
    else if (LEVEL[A[n1]] > level)
    {
        m1 = 1 + judge(A, n1 + 1, n2, LEVEL[A[n1]], LEVEL);
        m2 = judge(A, n1 + 1, n2, level, LEVEL);
        if (m1 > m2)
            return (m1);
        else
            return (m2);
    }
    else
        return (1 + judge(A, n1 + 1, n2, level, LEVEL));
}
int main()
{
    int i, j, NNode, M, L, MAXsolu;
    int Level[MAXSIZE + 1] = {0}, A[10000];
    scanf("%d", &NNode);
    scanf("%d", &M);
    for (i = 0; i < M; i++)
    {
        scanf("%d", &j);
        Level[j] = i + 1;
    }
    scanf("%d", &L);
    j = 0;
    for (i = 0; i < L; i++)
    {
        scanf("%d", A + j);
        if (Level[A[j]])
            j++;
    }
    MAXsolu = judge(A, 0, j - 1, 1, Level);
    printf("%d", MAXsolu);
    return 0;
}