#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 10000
//1151 LCA in a Binary Tree (30分)
//DATE:20201005
struct POS
{
    int key;
    int pos;
};
int findPos(struct POS *SORT, int N, int a)
{
    //二分查找；
    int left = 0, mid, right = N - 1;
    if (N < 0 || a < SORT[left].key || a > SORT[right].key)
        return -1;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (SORT[mid].key == a)
            return (SORT[mid].pos);
        if (SORT[mid].key > a)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return (-1);
}
void findLCA(int *pre, int *inorder, int root, int na, int nb, struct POS *SORT, int NN)
{
    int n0 = findPos(SORT, NN, pre[root]);
    if (n0 == na)
        printf("%d is an ancestor of %d.\n", inorder[na], inorder[nb]);
    else if (n0 == nb)
        printf("%d is an ancestor of %d.\n", inorder[nb], inorder[na]);
    else
    {
        if ((na < n0 && nb > n0) || (nb < n0 && na > n0))
            printf("LCA of %d and %d is %d.\n", inorder[na], inorder[nb], pre[root]);
        else if (na < n0 && nb < n0)
            findLCA(pre, inorder, root + 1, na, nb, SORT, NN);
        else
            findLCA(pre, inorder, n0 + 1, na, nb, SORT, NN);
    }
    return;
}
int cmpfunc(const void *a, const void *b)
{
    struct POS *p1 = (struct POS *)a;
    struct POS *p2 = (struct POS *)b;
    return p1->key - p2->key;
}
int main()
{
    int i, j, M, N, a, b, na, nb;
    int INORDER[MAXSIZE], PREORDER[MAXSIZE];
    struct POS *SORT;
    scanf("%d %d", &M, &N);
    SORT = (struct POS *)malloc(N * sizeof(struct POS));
    for (i = 0; i < N; i++)
    {
        scanf("%d", INORDER + i);
        SORT[i].key = INORDER[i];
        SORT[i].pos = i;
    }
    for (i = 0; i < N; i++)
        scanf("%d", PREORDER + i);
    qsort(SORT, N, sizeof(struct POS), cmpfunc);
    for (j = 0; j < M; j++)
    {
        scanf("%d %d", &a, &b);
        na = findPos(SORT, N, a);
        nb = findPos(SORT, N, b);
        if (na == -1 && nb == -1)
            printf("ERROR: %d and %d are not found.\n", a, b);
        else if (na == -1)
            printf("ERROR: %d is not found.\n", a);
        else if (nb == -1)
            printf("ERROR: %d is not found.\n", b);
        else if (a == b)
            printf("%d is an ancestor of %d.\n", a, b);
        else
            findLCA(PREORDER, INORDER, 0, na, nb, SORT, N);
    }
    return (0);
}