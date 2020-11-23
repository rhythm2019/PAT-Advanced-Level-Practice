//1150 Travelling Salesman Problem (25分)
//DATE:20201123
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 200
int G[MAXSIZE + 1][MAXSIZE + 1], visit[MAXSIZE + 1];
int main()
{
    int i, j, flag, N, M, n1, n2, totalDis, path[2 * MAXSIZE];
    //flag 1/2/3(Not a TS cycle)/4(Not a TS cycle and totalDis=NA)
    int shortNo, shortDis = -1;
    char s1[20] = "(TS simple cycle)\n", s2[20] = "(TS cycle)\n", s3[20] = "(Not a TS cycle)\n";
    scanf("%d %d", &N, &M);
    for (i = 0; i < M; i++)
    {
        scanf("%d %d %d", &n1, &n2, &j);
        G[n1][n2] = j;
        G[n2][n1] = j;
    }
    scanf("%d", &M);
    for (i = 0; i < M; i++)
    {
        scanf("%d", path);
        for (j = 1; j <= path[0]; j++)
            scanf("%d", path + j);
        //init
        totalDis = 0;
        for (j = 0; j < N; j++)
            visit[j] = 0;
        //judge
        if (path[0] == N + 1 && path[1] == path[N + 1])
        {
            flag = 1;
            for (j = 1; j < path[0]; j++)
            {
                n1 = path[j];
                n2 = path[j + 1];
                if (G[n1][n2])
                {
                    totalDis += G[n1][n2];
                    visit[n1] = 1;
                    visit[n2] = 1;
                }
                else
                {
                    flag = 4;
                    break;
                }
            }
            if (flag != 4)
                for (j = 1; j <= N; j++)
                    if (visit[j] == 0)
                    {
                        flag = 3;
                        break;
                    }
        }
        else if (path[0] > N + 1 && path[1] == path[path[0]])
        {
            flag = 2;
            for (j = 1; j < path[0]; j++)
            {
                n1 = path[j];
                n2 = path[j + 1];
                if (G[n1][n2])
                {
                    totalDis += G[n1][n2];
                    visit[n1] = 1;
                    visit[n2] = 1;
                }
                else
                {
                    flag = 4;
                    break;
                }
            }
            if (flag != 4)
                for (j = 1; j <= N; j++)
                    if (visit[j] == 0)
                    {
                        flag = 3;
                        break;
                    }
        }
        else
        {
            flag = 3;
            for (j = 1; j < path[0]; j++)
            {
                n1 = path[j];
                n2 = path[j + 1];
                if (G[n1][n2])
                    totalDis += G[n1][n2];
                else
                {
                    flag = 4;
                    break;
                }
            }
        }
        if (flag == 1)
            printf("Path %d: %d %s", i + 1, totalDis, s1);
        else if (flag == 2)
            printf("Path %d: %d %s", i + 1, totalDis, s2);
        else if (flag == 3)
            printf("Path %d: %d %s", i + 1, totalDis, s3);
        else
            printf("Path %d: NA %s", i + 1, s3);
        if (flag < 3 && (shortDis == -1 || shortDis > totalDis))
        {
            shortDis = totalDis;
            shortNo = i + 1;
        }
    }
    printf("Shortest Dist(%d) = %d\n", shortNo, shortDis);
    return 0;
}