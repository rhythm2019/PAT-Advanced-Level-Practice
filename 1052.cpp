#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
//1052 Linked List Sorting (25分)
struct NODE
{
    int address;
    int key;
    int next;
};
int cmpfunc1(const void *a, const void *b)
{
    NODE *s1 = (NODE *)a;
    NODE *s2 = (NODE *)b;
    return s1->key - s2->key;
}
int main()
{
    int i, j, k, N, key, count, cur;
    char root[6], address[6], next[6];
    NODE node[100000] = {0}, *Array;
    scanf("%d %s", &N, root);
    for (i = 0; i < N; i++)
    {
        scanf("%s %d %s", address, &key, next);
        node[atoi(address)].address = atoi(address);
        node[atoi(address)].key = key;
        node[atoi(address)].next = atoi(next);
    }
    Array = (NODE *)malloc(N * sizeof(NODE));
    count = 0;
    cur = atoi(root);
    while (cur != -1)
    {
        Array[count].address = cur;
        Array[count].key = node[cur].key;
        Array[count].next = node[cur].next;
        cur = node[cur].next;
        count++;
    }
    //sort
    if (count == 0)
    {
        printf("%d -1", count);
        return 0;
    }
    qsort(Array, count, sizeof(Array[0]), cmpfunc1);
    for (i = 0; i < count - 1; i++)
    {
        Array[i].next = Array[i + 1].address;
    }
    Array[count - 1].next = -1;
    //print
    printf("%d %05d\n", count, Array[0].address);
    for (i = 0; i < count; i++)
    {
        if (i == count - 1)
            printf("%05d %d %d\n", Array[i].address, Array[i].key, Array[i].next);
        else
            printf("%05d %d %05d\n", Array[i].address, Array[i].key, Array[i].next);
    }
    return 0;
}