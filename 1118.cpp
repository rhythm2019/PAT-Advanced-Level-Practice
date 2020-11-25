//1118 Birds in Forest (25分)
//DATE:20200824
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 10000
int get_parent(int node, int parent[][2])
{
    while (node != parent[node][0])
        node = parent[node][0];
    return (node);
}
void find_union(int node1, int node2, int parent[][2])
{
    if (get_parent(node1, parent) != get_parent(node2, parent))
        parent[get_parent(node2, parent)][0] = get_parent(node1, parent);
    return;
}

int main()
{
    int i, j, N, K, Q;
    int bird1, bird2, birds[MAXSIZE + 1][2];
    int Tree_num = 0, Bird_num = 0;
    for (i = 0; i < MAXSIZE + 1; i++)
    {
        birds[i][0] = i;
        birds[i][1] = 0;
    }
    scanf("%d", &N);
    for (i = 0; i < N; i++)
    {
        scanf("%d", &K);
        if (K)
        {
            scanf("%d", &bird1);
            birds[bird1][1] = 1;
            for (j = 1; j < K; j++)
            {
                scanf("%d", &bird2);
                birds[bird2][1] = 1;
                find_union(bird1, bird2, birds);
            }
        }
    }
    for (i = 1; i < MAXSIZE + 1; i++)
    {
        if (birds[i][1] == 0)
            break;
        Bird_num++;
        if (birds[i][0] == i)
            Tree_num++;
        else
            birds[i][0] = get_parent(i, birds);
    }
    printf("%d %d\n", Tree_num, Bird_num);
    scanf("%d", &Q);
    for (i = 0; i < Q; i++)
    {
        scanf("%d %d", &bird1, &bird2);
        if (birds[bird1][0] == birds[bird2][0])
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}