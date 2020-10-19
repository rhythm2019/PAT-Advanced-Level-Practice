#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//1072 Gas Station (30分)
//DATE:20201019
int G[1010][1010] = {0};
void dij(int G[1010][1010], int begin, int N1, int N2, int minDis, int *flag, int *sumDis, int *shortest)
{
    int i, j, curminDis, visit[1010] = {0}, shortDis[1010] = {0};
    int curnode, adjnode;
    curnode = begin;
    while (1)
    {
        visit[curnode] = 1;
        for (adjnode = 0; adjnode < N1 + N2; adjnode++)
            if (visit[adjnode] == 0 && G[curnode][adjnode] && (shortDis[adjnode] == 0 || shortDis[adjnode] > shortDis[curnode] + G[curnode][adjnode]))
                shortDis[adjnode] = shortDis[curnode] + G[curnode][adjnode];
        curminDis = minDis + 1;
        for (i = 0; i < N1 + N2; i++)
        {
            if (visit[i] == 0 && shortDis[i] && shortDis[i] < curminDis)
            {
                curminDis = shortDis[i];
                curnode = i;
            }
        }
        if (curminDis > minDis)
            break;
    }
    *sumDis = 0;
    *shortest = minDis;
    for (i = 0; i < N1; i++)
    {
        if (visit[i] == 0 || shortDis[i] > minDis)
        {
            *flag = 0;
            return;
        }
        *sumDis = *sumDis + shortDis[i];
        if (shortDis[i] < *shortest)
            *shortest = shortDis[i];
    }
    *flag = 1;
    return;
}
int main()
{
    int i, j, k, n1, n2, dis, Nhouse, Ngas, Nroad, Dmax;
    int flag, ID = 0, sumD, minD = 0, sumV, minV;
    char s1[6], s2[6];
    scanf("%d %d %d %d", &Nhouse, &Ngas, &Nroad, &Dmax);
    for (i = 0; i < Nroad; i++)
    {
        scanf("%s %s %d", s1, s2, &dis);
        n1 = 0;
        n2 = 0;
        if (s1[0] == 'G')
            j = 1;
        else
            j = 0;
        for (; s1[j] != '\0'; j++)
            n1 = 10 * n1 + s1[j] - '0';
        if (s2[0] == 'G')
            j = 1;
        else
            j = 0;
        for (; s2[j] != '\0'; j++)
            n2 = 10 * n2 + s2[j] - '0';
        if (s1[0] == 'G')
            n1 = n1 + Nhouse;
        if (s2[0] == 'G')
            n2 = n2 + Nhouse;
        G[n1 - 1][n2 - 1] = dis;
        G[n2 - 1][n1 - 1] = dis;
    }
    /////dij
    for (i = Nhouse; i < Nhouse + Ngas; i++)
    {
        dij(G, i, Nhouse, Ngas, Dmax, &flag, &sumV, &minV);
        if (flag && (minV > minD || (minV == minD && sumV < sumD)))
        {
            ID = i;
            sumD = sumV;
            minD = minV;
        }
    }
    if (ID)
    {
        printf("G%d\n", ID - Nhouse + 1);
        printf("%.1f %.1f", 1.0 * minD, 1.0 * sumD / Nhouse);
    }
    else
        printf("No Solution");
    return 0;
}