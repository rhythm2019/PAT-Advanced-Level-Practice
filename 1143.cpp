#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 10000
//1143 Lowest Common Ancestor (30分)
//DATE:20201007
int findPos(int *SORT, int a, int left, int right)
{
    //二分查找；
    int mid;
    if (a < SORT[left] || a > SORT[right])
        return (-1);
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (SORT[mid] == a)
            return (mid);
        if (SORT[mid] > a)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return (-1);
}
void findLCA(int *pre, int *inorder, int root, int a, int b, int NN, int na, int nb)
{
    if (na > nb)
        na = nb;
    while (1)
        if (pre[root] == a)
        {
            printf("%d is an ancestor of %d.\n", a, b);
            return;
        }
        else if (pre[root] == b)
        {
            printf("%d is an ancestor of %d.\n", b, a);
            return;
        }
        else if ((a < pre[root] && b > pre[root]) || (b < pre[root] && a > pre[root]))
        {
            printf("LCA of %d and %d is %d.\n", a, b, pre[root]);
            return;
        }
        else if (a < pre[root] && b < pre[root])
            root++;
        else
            root = findPos(inorder, pre[root], root, na) + 1;
}
int cmpfunc(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}
int main()
{
    int i, j, M, N, a, b, na, nb;
    int INORDER[MAXSIZE], PREORDER[MAXSIZE];
    scanf("%d %d", &M, &N);
    for (i = 0; i < N; i++)
    {
        scanf("%d", PREORDER + i);
        INORDER[i] = PREORDER[i];
    }
    qsort(INORDER, N, sizeof(int), cmpfunc);
    for (j = 0; j < M; j++)
    {
        scanf("%d %d", &a, &b);
        na = findPos(INORDER, a, 0, N - 1);
        nb = findPos(INORDER, b, 0, N - 1);
        if (na == -1 && nb == -1)
            printf("ERROR: %d and %d are not found.\n", a, b);
        else if (na == -1)
            printf("ERROR: %d is not found.\n", a);
        else if (nb == -1)
            printf("ERROR: %d is not found.\n", b);
        else if (a == b)
            printf("%d is an ancestor of %d.\n", a, b);
        else
            findLCA(PREORDER, INORDER, 0, a, b, N, na, nb);
    }
    return (0);
}