#include <stdio.h>
#include <stdlib.h>
int find(int node, int parent[])
{
    int root = parent[node];
    while (root != node)
    {
        node = root;
        root = parent[root];
    }
    return root;
}
int U_and_F(int parent[], int N, int connection[][2], int M, int c1)
{
    // UNION and FIND
    int i, node1, node2, count = 0;
    for (i = 0; i < N + 1; i++)
        parent[i] = i;
    for (i = 0; i < M; i++)
    {
        node1 = connection[i][0];
        node2 = connection[i][1];
        if ((node1 != c1) && (node2 != c1) && (find(node1, parent) != find(node2, parent)))
            parent[find(node2, parent)] = find(node1, parent);
    }
    for (i = 1; i < N + 1; i++)
        if (parent[i] == i)
            count++;
    return (count - 2);
}
int main()
{
    int i, count, N, M, K;
    int *parent, (*connection)[2], *lostcity;
    scanf("%d %d %d", &N, &M, &K);
    parent = (int *)malloc((N + 1) * sizeof(int));
    connection = (int(*)[2])malloc(2 * M * sizeof(int));
    lostcity = (int *)malloc(K * sizeof(int));
    for (i = 0; i < M; i++)
        scanf("%d %d", &connection[i][0], &connection[i][1]);
    for (i = 0; i < K; i++)
        scanf("%d", &lostcity[i]);
    //SOLVE
    for (i = 0; i < K; i++)
    {
        count = U_and_F(parent, N, connection, M, lostcity[i]);
        printf("%d\n", count);
    }
    return (0);
}