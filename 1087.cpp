#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXN 200
//1087 All Roads Lead to Rome (30分)
//DATE:20201012
struct node
{
    int NO;
    int distance;
    struct node *next;
};
struct Graph
{
    int node_count;
    struct node G[MAXN];
};

void dj(int begin, int end, struct Graph *G, int short_dis[], struct node path[], int visit[])
{
    int i, j, k, N = G->node_count, curnode, nextnode;
    struct node *cur, *next, *tmp;
    curnode = begin;
    short_dis[begin] = 0;
    while (1)
    {
        visit[curnode] = 1;
        if (curnode == end)
            return;
        // seach adjacent node
        cur = G->G[curnode].next;
        while (cur)
        {
            nextnode = cur->NO;
            if (visit[nextnode] == 0)
            {
                if (short_dis[nextnode] == -1 || short_dis[nextnode] > short_dis[curnode] + cur->distance)
                {
                    short_dis[nextnode] = short_dis[curnode] + cur->distance;
                    next = path[nextnode].next;
                    while (next)
                    {
                        tmp = next->next;
                        free(next);
                        next = tmp;
                    }
                    next = (struct node *)malloc(sizeof(struct node));
                    next->NO = curnode;
                    next->next = NULL;
                    path[nextnode].next = next;
                }
                else if (short_dis[nextnode] == short_dis[curnode] + cur->distance)
                {
                    next = (struct node *)malloc(sizeof(struct node));
                    next->NO = curnode;
                    next->next = path[nextnode].next;
                    path[nextnode].next = next;
                }
            }
            cur = cur->next;
        }
        // search next mini distance
        for (i = 0; i < N; i++)
            if (visit[i] == 0 && short_dis[i] != -1)
            {
                curnode = i;
                i++;
                break;
            }
        for (; i < N; i++)
            if (visit[i] == 0 && short_dis[i] != -1 && short_dis[i] < short_dis[curnode])
                curnode = i;
    }
    return;
}
void dfs(int n1, int n2, int happyness[], struct node path[], int result[], int *NN, int queue[], int *NNqueue, int *maxhappy, int *curhappy, int *count)
{
    int i, curnode;
    struct node *cur;
    cur = path[n1].next;
    while (cur)
    {
        curnode = cur->NO;
        (*curhappy) += happyness[curnode];
        queue[(*NN)++] = curnode;
        if (curnode == n2)
        {
            (*count)++;
            if ((*curhappy > *maxhappy) || (*curhappy == *maxhappy && *curhappy / (*NN) > *maxhappy / (*NNqueue)))
            {
                *maxhappy = *curhappy;
                *NNqueue = *NN;
                for (i = 0; i < *NN; i++)
                    result[i] = queue[i];
            }
        }
        else
        {
            dfs(curnode, n2, happyness, path, result, NN, queue, NNqueue, maxhappy, curhappy, count);
        }
        (*curhappy) -= happyness[curnode];
        (*NN)--;
        cur = cur->next;
    }
    return;
}
int ABC_NO(char city[4])
{
    return 26 * ((city[0] - 'A') * 26 + city[1] - 'A') + city[2] - 'A';
}
void NO_ABC(int NO, char *city)
{
    city[3] = '\0';
    city[2] = NO % 26 - '0';
    city[1] = (NO - 26 * 26 * (NO / (26 * 26))) / 26 - '0';
    city[0] = NO / (26 * 26) - '0';
    return;
}

int main()
{
    int i, j, N, K;
    int short_dis[MAXN], happyness[MAXN], visit[MAXN] = {0}, cityIndex[26 * 26 * 26], result[MAXN], queue[MAXN];
    int begin, end, distance, count = 0, maxhappy = -1, curhappy = 0;
    char s1[4], s2[4], cityName[MAXN][4];
    struct node *curnode, parent[MAXN] = {0, 0, NULL};
    struct Graph GG;

    scanf("%d %d %s", &N, &K, cityName[0]);
    cityIndex[ABC_NO(cityName[0])] = 0;
    happyness[0] = 0;
    short_dis[0] = 0;
    for (i = 1; i < N; i++)
    {
        scanf("%s %d", cityName[i], &happyness[i]);
        cityIndex[ABC_NO(cityName[i])] = i;
        short_dis[i] = -1;
    }
    GG.node_count = N;
    for (i = 0; i < K; i++)
    {
        scanf("%s %s %d", s1, s2, &distance);
        begin = cityIndex[ABC_NO(s1)];
        end = cityIndex[ABC_NO(s2)];
        curnode = (struct node *)malloc(sizeof(struct node));
        curnode->next = GG.G[begin].next;
        GG.G[begin].next = curnode;
        curnode->NO = end;
        curnode->distance = distance;
        curnode = (struct node *)malloc(sizeof(struct node));
        curnode->next = GG.G[end].next;
        GG.G[end].next = curnode;
        curnode->NO = begin;
        curnode->distance = distance;
    }
    //dj
    begin = 0;
    end = cityIndex[ABC_NO((char *)"ROM")];
    dj(begin, end, &GG, short_dis, parent, visit);
    //search max happyiess
    i = 0;
    j = 0;
    dfs(end, begin, happyness, parent, result, &i, queue, &j, &maxhappy, &curhappy, &count);
    maxhappy += happyness[end];
    printf("%d %d %d %d\n", count, short_dis[end], maxhappy, maxhappy / j);
    for (i = j - 1; i >= 0; i--)
        printf("%s->", cityName[result[i]]);
    printf("%s", cityName[end]);
    return 0;
}