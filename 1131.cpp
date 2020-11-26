//1131 Subway Map (30分)
//DATE:20201126
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 10000
#define TRANSFERSIZE 10
struct STATION
{
    short int NUM;
    short int stop[TRANSFERSIZE];
};
short int distance[MAXSIZE], trans[MAXSIZE], path[MAXSIZE];
struct STATION *stop[MAXSIZE];
short int LINE[MAXSIZE][MAXSIZE];

int cmpfunc(const void *a, const void *b)
{
    //distance+trans
    short int n1 = *(int *)a, n2 = *(int *)b;
    if (distance[n1] != distance[n2])
        return (distance[n1] - distance[n2]);
    if (trans[n1] != trans[n2])
        return (trans[n1] - trans[n2]);
    return (0);
}
void dj(short int begin, short int end)
{
    short int i, j, node1, node2, lastline = 0;
    struct STATION *cur;
    short int LList[MAXSIZE], LL_N = 0;
    // initial
    memset(trans, 0, sizeof(trans));
    memset(path, 0, sizeof(path));
    for (i = 0; i < MAXSIZE; i++)
        distance[i] = MAXSIZE;
    //solve
    distance[begin] = 0;
    node1 = begin;
    j = 0;
    while (node1 != end)
    {
        cur = stop[node1];
        for (i = 0; i < cur->NUM; i++)
        {
            node2 = cur->stop[i];
            if (distance[node2] > distance[node1] + 1)
            {
                path[node2] = node1;
                distance[node2] = distance[node1] + 1;
                if (lastline && LINE[node1][node2] != lastline)
                    trans[node2] = trans[node1] + 1;
                else
                    trans[node2] = trans[node1];
                LList[LL_N++] = node2;
            }
            else if (distance[node2] == distance[node1] + 1)
            {

                if (lastline && LINE[node1][node2] != lastline && trans[node2] > trans[node1] + 1)
                {
                    path[node2] = node1;
                    trans[node2] = trans[node1] + 1;
                }
                else if (lastline && LINE[node1][node2] == lastline && trans[node2] > trans[node1])
                {
                    trans[node2] = trans[node1];
                    path[node2] = node1;
                }
            }
        }
        //search next node
        qsort(LList + j, LL_N - j, sizeof(short int), cmpfunc);
        node1 = LList[j];
        lastline = LINE[path[node1]][node1]; //似乎有点问题
        j++;
    }
    return;
}
int main()
{
    int i, j, k, N, K, node1, node2, node3;
    short int result[MAXSIZE], result_N;
    scanf("%d", &N);
    for (i = 1; i < N + 1; i++)
    {
        scanf("%d", &j);
        for (k = 0; k < j; k++)
            scanf("%hd", result + k);
        for (k = 0; k < j - 1; k++)
        {
            LINE[result[k]][result[k + 1]] = i;
            if (stop[result[k]] == NULL)
            {
                stop[result[k]] = (struct STATION *)malloc(sizeof(struct STATION));
                stop[result[k]]->stop[0] = result[k + 1];
                stop[result[k]]->NUM = 1;
            }
            else
                stop[result[k]]->stop[stop[result[k]]->NUM++] = result[k + 1];
        }
        for (k = j - 1; k > 0; k--)
        {
            LINE[result[k]][result[k - 1]] = i;
            if (stop[result[k]] == NULL)
            {
                stop[result[k]] = (struct STATION *)malloc(sizeof(struct STATION));
                stop[result[k]]->stop[0] = result[k - 1];
                stop[result[k]]->NUM = 1;
            }
            else
                stop[result[k]]->stop[stop[result[k]]->NUM++] = result[k - 1];
        }
    }
    scanf("%d", &K);
    for (i = 0; i < K; i++)
    {
        scanf("%d %d", &node1, &node2);
        dj(node1, node2);
        result[0] = node2;
        result_N = 0;
        node3 = node2;
        while (node3 != node1)
        {
            node3 = path[node3];
            result[++result_N] = node3;
        }
        result[++result_N] = node1;
        for (j = 0; j <= result_N / 2; j++)
        {
            k = result[j];
            result[j] = result[result_N - j];
            result[result_N - j] = k;
        }
        //print
        printf("%d\n", distance[node2]);
        for (j = 1; j < result_N;)
        {
            for (k = j + 1; k < result_N; k++)
                if (LINE[result[k]][result[k + 1]] != LINE[result[j]][result[j + 1]])
                {
                    printf("Take Line#%d from %04d to %04d.\n", LINE[result[j]][result[j + 1]], result[j], result[k]);
                    j = k;
                    break;
                }
            if (k == result_N)
            {
                printf("Take Line#%d from %04d to %04d.\n", LINE[result[j]][result[j + 1]], result[j], result[k]);
                break;
            }
        }
    }
    return 0;
}