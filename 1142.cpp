//1142 Maximal Clique (25分)
//DATE:20201003
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 201
int main()
{
    int i, j, k, ii, Flag, M, n1, n2, nv, ne, count, query[MAXSIZE];
    bool G[MAXSIZE][MAXSIZE] = {false}, result[MAXSIZE];
    scanf("%d %d", &nv, &ne);
    for (i = 1; i <= nv; i++)
        G[i][i] = true;

    for (i = 0; i < ne; i++)
    {
        scanf("%d %d", &n1, &n2);
        G[n1][n2] = true;
        G[n2][n1] = true;
    }
    scanf("%d", &k);
    for (i = 0; i < k; i++)
    {
        scanf("%d", &M);
        for (j = 0; j < M; j++)
            scanf("%d", query + j);
        Flag = 0;
        for (j = 1; j <= nv; j++)
            result[j] = G[query[0]][j];
        for (ii = 1; ii < M; ii++)
            for (j = 1; j <= nv; j++)
                result[j] = result[j] && G[query[ii]][j];
        for (j = 0; j < M; j++)
            if (result[query[j]] == false)
            {
                printf("Not a Clique\n");
                Flag = 1;
                break;
            }
        if (Flag)
            continue;
        else
        {
            count = 0;
            for (j = 1; j <= nv; j++)
                if (result[j])
                    count++;
            if (count > M)
                printf("Not Maximal\n");
            else
                printf("Yes\n");
        }
    }
    return (0);
}