//1135 Is It A Red-Black Tree (30分)
//DATE:20201025
#include <stdio.h>
#include <stdlib.h>
struct treeNode
{
    int num;
    struct treeNode *left;
    struct treeNode *right;
    int count_black;
};
void createTree(struct treeNode *root, int NODE[], int begin, int end)
{
    int left, right;
    root->num = NODE[begin];
    if (begin == end)
    {
        root->left = NULL;
        root->right = NULL;
        return;
    }
    if (abs(NODE[begin + 1]) > abs(NODE[begin]))
    {
        root->left = NULL;
        root->right = (struct treeNode *)malloc(sizeof(struct treeNode));
        createTree(root->right, NODE, begin + 1, end);
        return;
    }
    else
    {
        left = begin + 1;
        right = left + 1;
        while (right <= end && (abs(NODE[begin]) > abs(NODE[right])))
            right++;
        root->left = (struct treeNode *)malloc(sizeof(struct treeNode));
        createTree(root->left, NODE, left, right - 1);
        if (right <= end)
        {
            root->right = (struct treeNode *)malloc(sizeof(struct treeNode));
            createTree(root->right, NODE, right, end);
        }
        else
            root->right = NULL;
        return;
    }
}
void destroyTree(struct treeNode *root)
{
    if (root)
    {
        destroyTree(root->left);
        destroyTree(root->right);
        free(root);
    }
    return;
}
void check(struct treeNode *root, int *lastnum, int *flag)
{
    short int i, j;
    if (*flag == 0 || root == NULL)
        return;
    if (root->left == NULL || root->right == NULL)
    {
        if (*lastnum == 0)
            *lastnum = root->count_black + 1;
        else if (root->count_black + 1 != *lastnum)
        {
            *flag = 0;
            return;
        }
    }
    if (root->left)
    {
        if (root->left->num > 0)
            root->left->count_black = root->count_black + 1;
        else
            root->left->count_black = root->count_black;
        if (root->num < 0 && root->left->num < 0)
        {
            *flag = 0;
            return;
        }
        check(root->left, lastnum, flag);
    }
    if (root->right)
    {
        if (root->right->num > 0)
            root->right->count_black = root->count_black + 1;
        else
            root->right->count_black = root->count_black;
        if (root->num < 0 && root->right->num < 0)
        {
            *flag = 0;
            return;
        }
        check(root->right, lastnum, flag);
    }
    return;
}
int main()
{
    int i, j, lastnum, flag, K, N, NODE[30];
    struct treeNode *root;
    scanf("%d", &K);
    for (i = 0; i < K; i++)
    {
        scanf("%d", &N);
        for (j = 0; j < N; j++)
            scanf("%d", NODE + j);
        if (NODE[0] < 0)
        {
            printf("No\n");
            continue;
        }
        //create tree
        root = (struct treeNode *)malloc(sizeof(struct treeNode));
        root->count_black = 1;
        createTree(root, NODE, 0, N - 1);
        //check
        flag = 1;
        lastnum = 0;
        check(root, &lastnum, &flag);
        if (flag)
            printf("Yes\n");
        else
            printf("No\n");
        //destroy tree
        destroyTree(root);
    }
    return 0;
}