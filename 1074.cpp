//1074
#include <iostream>
#include <stdio.h>
#include <malloc.h>
#include <string.h>
struct Node
{
    int ID;
    int data;
    int next;
};

int inverse_LList(int root, int K, Node *node, int len)
{
    int i = 0, j = 0;
    int cur, pre, next;
    if (len < K)
        return (root);
    pre = root;
    cur = node[pre].next;
    for (i = 0; i < K - 1; i++)
    {
        next = node[cur].next;
        node[cur].next = pre;
        pre = cur;
        cur = next;
    }

    j = inverse_LList(cur, K, node, len - K);
    node[root].next = j;
    return pre;
}

void print_LList(int root, Node *node, int len)
{
    int i;
    for (i = 0; i < len - 1; i++)
    {
        printf("%05d %d %05d\n", node[root].ID, node[root].data, node[root].next);
        root = node[root].next;
    }
    printf("%05d %d %d\n", node[root].ID, node[root].data, node[root].next);
}
int main()
{
    int N, K, root, cur, len, i;
    int id, data, next;
    Node node[100000];
    scanf("%d%d%d", &root, &N, &K);
    for (i = 0; i < N; i++)
    {
        scanf("%d %d %d", &id, &data, &next);
        node[id].ID = id;
        node[id].data = data;
        node[id].next = next;
    }
    // length
    cur = root;
    len = 0;
    while (cur != -1)
    {
        cur = node[cur].next;
        len++;
    }

    // invert link
    cur = inverse_LList(root, K, node, len);
    print_LList(cur, node, len);
    return 0;
}