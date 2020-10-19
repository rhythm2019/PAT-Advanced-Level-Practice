#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//1072 Gas Station (30分)
//DATE:20201017
//floyd 超时了
int G[1010][1010] = {0};
int main()
{
    int i, j, k, n1, n2, dis, Nhouse, Ngas, Nroad, Dmax;
    int ID = 0, sumD, minD = 0, minV, flag;
    char s1[6], s2[6];
    scanf("%d %d %d %d", &Nhouse, &Ngas, &Nroad, &Dmax);
    for (i = 0; i < Nhouse + Ngas; i++)
        for (j = 0; j < Nhouse + Ngas; j++)
            if (i != j)
                G[i][j] = Dmax + 1;
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
    /////Floyed
    for (k = 0; k < Nhouse + Ngas; k++)
        for (i = 0; i < Nhouse + Ngas; i++)
            for (j = 0; j < Nhouse + Ngas; j++)
                if (G[i][k] + G[k][j] < G[i][j])
                    G[i][j] = G[i][k] + G[k][j];
    /////solve
    for (i = Nhouse; i < Nhouse + Ngas; i++)
    {
        flag = 1;
        minV = Dmax;
        k = 0;
        for (j = 0; j < Nhouse; j++)
            if (G[i][j] > Dmax)
            {
                flag = 0;
                break;
            }
            else
            {
                k += G[i][j];
                if (i != j && G[i][j] < minV)
                    minV = G[i][j];
            }
        if (flag && (minV > minD || (minV == minD && k < sumD)))
        {
            sumD = k;
            ID = i;
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