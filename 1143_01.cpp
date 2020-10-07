#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAXSIZE 10000
//1143 Lowest Common Ancestor (30分)
//DATE:20201007
// 超时？？？
struct HASHTABLE
{
    int SIZE;
    int *key;
    int *index;
};
typedef struct HASHTABLE *pHash;
pHash create_Hash(int size)
{
    int i, Flag = 0;
    pHash h1 = (pHash)malloc(sizeof(struct HASHTABLE));
    if (size % 2 == 0)
        size++;
    while (Flag == 0)
    {
        Flag = 1;
        for (i = 3; i < (int)sqrt(size) + 1; i += 2)
            if (size % i == 0)
            {
                size += 2;
                Flag = 0;
                break;
            }
    }
    h1->SIZE = size;
    h1->key = (int *)malloc(size * sizeof(int));
    h1->index = (int *)malloc(size * sizeof(int));
    for (i = 0; i < size; i++)
    {
        h1->key[i] = 0;
        h1->index[i] = -1;
    }
    return h1;
}
int get_pos(pHash H1, int key)
// get hash pos
{
    long long i = 0, pos, newpos;
    pos = key % H1->SIZE;
    if (pos < 0)
        pos = pos + H1->SIZE;
    newpos = pos;
    while (i < H1->SIZE)
    {
        if (H1->index[newpos] != -1 && H1->key[newpos] == key)
            return ((int)newpos);
        newpos += 2 * i + 1;
        i++;
        newpos = newpos % H1->SIZE;
    }
    return (-1);
}

bool insertHash(pHash H1, int key, int index)
{
    long long i = 0, pos, newpos;
    pos = key % H1->SIZE;
    if (pos < 0)
        pos = pos + H1->SIZE;
    newpos = pos;
    while (i < H1->SIZE && H1->index[newpos] != -1)
    {
        newpos = newpos + 2 * i + 1;
        i++;
        newpos = newpos % H1->SIZE;
    }
    H1->key[newpos] = key;
    H1->index[newpos] = index;
    return true;
}
int findIndex(pHash h1, int key)
//get inorder index
{
    int pos = get_pos(h1, key);
    if (pos == -1)
        return (-1);
    else
        return (h1->index[pos]);
}
void findLCA(int *pre, pHash h1, int a, int b)
{
    int root = 0;
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
            root = findIndex(h1, pre[root]) + 1;
}
int cmpfunc(const void *a, const void *b)
{
    if (*(int *)a < *(int *)b)
        return (-1);
    else if (*(int *)a > *(int *)b)
        return (1);
    else
        return (0);
}
int main()
{
    int i, j, M, N, a, b, na, nb;
    int INORDER[MAXSIZE], PREORDER[MAXSIZE];
    pHash H1 = create_Hash(2 * MAXSIZE + 1);
    scanf("%d %d", &M, &N);
    for (i = 0; i < N; i++)
    {
        scanf("%d", PREORDER + i);
        INORDER[i] = PREORDER[i];
    }
    qsort(INORDER, N, sizeof(int), cmpfunc);
    for (i = 0; i < N; i++)
        insertHash(H1, INORDER[i], i);
    for (j = 0; j < M; j++)
    {
        scanf("%d %d", &a, &b);
        na = findIndex(H1, a);
        nb = findIndex(H1, b);
        if (na == -1 && nb == -1)
            printf("ERROR: %d and %d are not found.\n", a, b);
        else if (na == -1)
            printf("ERROR: %d is not found.\n", a);
        else if (nb == -1)
            printf("ERROR: %d is not found.\n", b);
        else if (a == b)
            printf("%d is an ancestor of %d.\n", a, b);
        else
            findLCA(PREORDER, H1, a, b);
    }
    return (0);
}