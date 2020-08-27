#include <stdlib.h>
#include <stdio.h>
#define MAXSIZE 500
//1126 Eulerian Path (25分)
//DATE:20200827
int get_father(int n1, int father[])
{
    while (n1 != father[n1])
        n1 = father[n1];
    return n1;
}
void search_union(int n1, int n2, int father[])
{
    n1 = get_father(n1, father);
    n2 = get_father(n2, father);
    if (n1 != n2)
        father[n2] = n1;
    return;
}
int main()
{
    int i, n1, n2, N, M, COUNT = 0;
    int degree[MAXSIZE] = {0}, father[MAXSIZE];
    scanf("%d %d", &N, &M);
    for (i = 0; i < N; i++)
        father[i] = i;
    for (i = 0; i < M; i++)
    {
        scanf("%d %d", &n1, &n2);
        degree[n1 - 1]++;
        degree[n2 - 1]++;
        search_union(n1 - 1, n2 - 1, father);
    }
    for (i = 0; i < N - 1; i++)
        printf("%d ", degree[i]);
    printf("%d\n", degree[i]);

    for (i = 0; i < N; i++)
        if (father[i] == i)
            COUNT++;
    if (COUNT != 1)
    {
        printf("Non-Eulerian");
        return (0);
    }
    else
    {
        COUNT = 0;
        for (i = 0; i < N; i++)
        {
            if (degree[i] % 2 == 1)
                COUNT++;
        }
        if (COUNT == 0)
            printf("Eulerian");
        else if (COUNT == 2)
            printf("Semi-Eulerian");
        else
            printf("Non-Eulerian");
        return 0;
    }
}