//1075 PAT Judge (25分)
//DATE:20200911
#include <stdio.h>
#include <stdlib.h>
int cmpfunc(const void *a, const void *b)
{
    int *u1 = (int *)a;
    int *u2 = (int *)b;
    if (u1[6] == u2[6])
    {
        if (u1[7] == u2[7])
            return (u1[0] - u2[0]);
        else
            return (u2[7] - u1[7]);
    }
    else
        return (u2[6] - u1[6]);
}
int main()
{
    int i, j, N, K, M, id, iprob, score;
    int user[10001][8], FULLSCORE[6];
    scanf("%d %d %d", &N, &K, &M);
    for (i = 1; i < N + 1; i++)
    {
        user[i][0] = i;
        for (j = 1; j <= K; j++)
            user[i][j] = -2; //没有提交
        user[i][6] = -2;     //没有提交
        user[i][7] = 0;
    }
    for (i = 1; i < K + 1; i++)
        scanf("%d", FULLSCORE + i);
    for (i = 0; i < M; i++)
    {
        scanf("%d %d %d", &id, &iprob, &score);
        if (user[id][iprob] < score)
            user[id][iprob] = score;
    }
    for (i = 1; i < N + 1; i++)
        for (j = 1; j < K + 1; j++)
        {
            if (user[i][j] >= 0 && user[i][6] >= 0)
                user[i][6] += user[i][j];
            else if (user[i][j] >= 0 && user[i][6] < 0)
                user[i][6] = user[i][j];
            if (user[i][j] == FULLSCORE[j])
                user[i][7]++;
        }
    qsort(user + 1, N, sizeof(user[0]), cmpfunc);
    for (i = 1; i < N + 1; i++)
    {
        if (user[i][6] < 0)
            break;
        if (user[i][6] != user[i - 1][6])
            M = i;
        printf("%d %05d %d", M, user[i][0], user[i][6]);
        for (j = 1; j < K + 1; j++)
            if (user[i][j] >= 0)
                printf(" %d", user[i][j]);
            else if (user[i][j] == -2)
                printf(" -");
            else
                printf(" 0");
        printf("\n");
    }
    return 0;
}