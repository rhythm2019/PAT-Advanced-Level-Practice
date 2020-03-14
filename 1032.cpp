#include <iostream>
#include <stdio.h>
#include <malloc.h>
#include <string.h>
//1032
struct Node
{
    int ID;
    char data;
    int next;
};
int main()
{
    int N, root1, root2, cur, len1 = 0, len2 = 0;
    int i, id, data, next, a1[100000], a2[100000];
    Node node[100000];
    scanf("%d%d%d", &root1, &root2, &N);
    for (i = 0; i < N; i++)
    {
        scanf("%d %c %d", &id, &data, &next);
        node[id].ID = id;
        node[id].data = data;
        node[id].next = next;
    }
    // length
    cur = root1;
    a1[len1] = root1;
    while (cur != -1)
    {
        cur = node[cur].next;
        len1++;
        a1[len1] = cur;
    }
    cur = root2;
    a2[len2] = root2;
    while (cur != -1)
    {
        cur = node[cur].next;
        len2++;
        a2[len2] = cur;
    }
    i = 1;
    while (len1 - i >= 0 && len2 - i >= 0)
        if (a1[len1 - i] == a2[len2 - i])
            i++;
        else
            break;
    if (i == 1)
        printf("-1");
    else
        printf("%05d", a1[len1 - i + 1]);
    return 0;
}
