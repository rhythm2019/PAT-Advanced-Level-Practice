#include <stdio.h>
#include <stdlib.h>
//1097 Deduplication on a Linked List (25分)
//DATE:20200813
struct Node
{
    int num;
    int next;
};
struct HASHTable
{
    int size;
    int *key;
    int *value;
};

int hash(struct HASHTable *H1, int key)
{
    return (key % H1->size);
}
int get_pos(struct HASHTable *H1, int key)
{
    int pos = key % H1->size, i = 0;
    while (i <= H1->size && (H1->value[pos] && abs(H1->key[pos]) != abs(key)))
    {
        pos = (++pos) % H1->size;
    }
    if (i > H1->size)
        return (-1);
    else
        return (pos);
}

int main()
{
    int i, root1, root2 = -1, N, pre1, pre2, cur;
    int address, num, next;
    struct Node linknode[100000];
    struct HASHTable H1;
    H1.size = 120001;
    H1.key = (int *)malloc(H1.size * sizeof(int));
    H1.value = (int *)malloc(H1.size * sizeof(int));
    for (i = 0; i < H1.size; i++)
    {
        H1.key[i] = -1;
        H1.value[i] = 0;
    }
    //
    scanf("%d %d", &root1, &N);
    for (i = 0; i < 100000; i++)
    {
        linknode[i].num = 0;
        linknode[i].next = -1;
    }
    for (i = 0; i < N; i++)
    {
        scanf("%d %d %d", &address, &num, &next);
        linknode[address].num = num;
        linknode[address].next = next;
    }
    //travel
    pre1 = root1;
    pre2 = -1;
    num = linknode[root1].num;
    address = get_pos(&H1, abs(num));
    H1.key[address] = num;
    H1.value[address] = 1;

    cur = linknode[root1].next;
    while (cur != -1)
    {
        num = linknode[cur].num;
        address = get_pos(&H1, abs(num));
        if (H1.value[address] == 0)
        {
            H1.key[address] = num;
            H1.value[address] = 1;
            linknode[pre1].next = cur;
            pre1 = cur;
            cur = linknode[cur].next;
        }
        else
        {
            if (root2 != -1)
                linknode[pre2].next = cur;
            else
                root2 = cur;
            pre2 = cur;
            cur = linknode[cur].next;
        }
    }
    if (pre1 != -1)
        linknode[pre1].next = -1;
    if (pre2 != -1)
        linknode[pre2].next = -1;
    //print result
    cur = root1;
    while (cur != -1)
    {
        if (linknode[cur].next != -1)
            printf("%05d %d %05d\n", cur, linknode[cur].num, linknode[cur].next);
        else
            printf("%05d %d %d\n", cur, linknode[cur].num, linknode[cur].next);
        cur = linknode[cur].next;
    }
    cur = root2;
    while (cur != -1)
    {
        if (linknode[cur].next != -1)
            printf("%05d %d %05d\n", cur, linknode[cur].num, linknode[cur].next);
        else
            printf("%05d %d %d\n", cur, linknode[cur].num, linknode[cur].next);
        cur = linknode[cur].next;
    }
    return (0);
}