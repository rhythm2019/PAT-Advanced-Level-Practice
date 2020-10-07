#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAXSIZE 100000
//1133 Splitting A Linked List (25分)
//DATE:20200821
struct node
{
    int data;
    int next;
};
int main()
{
    int i, j, root, N, K;
    int cur, data, next;
    struct node TreeNode[MAXSIZE + 1];
    int KK[3][2];
    scanf("%d %d %d", &root, &N, &K);
    for (i = 0; i < N; i++)
    {
        scanf("%d %d %d", &j, &data, &next);
        TreeNode[j].data = data;
        TreeNode[j].next = next;
    }
    for (i = 0; i < 3; i++)
    {
        //head and tail
        KK[i][0] = -1;
        KK[i][1] = -1;
    }
    //SOLVE
    cur = root;
    while (cur != -1)
    {
        data = TreeNode[cur].data;
        if (data < 0)
        {
            if (KK[0][1] != -1)
            {
                TreeNode[KK[0][1]].next = cur;
                KK[0][1] = cur;
            }
            else
            {
                KK[0][0] = cur;
                KK[0][1] = cur;
            }
        }
        else if (data <= K)
        {
            if (KK[1][1] != -1)
            {
                TreeNode[KK[1][1]].next = cur;
                KK[1][1] = cur;
            }
            else
            {
                KK[1][0] = cur;
                KK[1][1] = cur;
            }
        }
        else
        {
            if (KK[2][1] != -1)
            {
                TreeNode[KK[2][1]].next = cur;
                KK[2][1] = cur;
            }
            else
            {
                KK[2][0] = cur;
                KK[2][1] = cur;
            }
        }
        cur = TreeNode[cur].next;
    }
    if (KK[2][1] != -1)
        TreeNode[KK[2][1]].next = -1;
    if (KK[1][0] != -1)
        TreeNode[KK[1][1]].next = KK[2][0];
    if (KK[0][0] != -1)
    {
        if (KK[1][0] != -1)
            TreeNode[KK[0][1]].next = KK[1][0];
        else
            TreeNode[KK[0][1]].next = KK[2][0];
    }
    if (KK[0][0] != -1)
        root = KK[0][0];
    else if (KK[1][0] != -1)
        root = KK[1][0];
    else
        root = KK[2][0];
    cur = root;
    while (cur != -1)
    {
        if (TreeNode[cur].next != -1)
            printf("%05d %d %05d\n", cur, TreeNode[cur].data, TreeNode[cur].next);
        else
            printf("%05d %d -1\n", cur, TreeNode[cur].data);
        cur = TreeNode[cur].next;
    }
    return 0;
}