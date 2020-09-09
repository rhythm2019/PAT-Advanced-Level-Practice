//1026 Table Tennis (30分)
//DATE:20200909
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
struct PLAYER
{
    char arrival[9];
    char server[9];
    int during;
    int type; //0:ord;1:vip
};
struct TABLE
{
    int No;
    char endtime[9];
    int type;
    int count;
};
int cmpfunc(const void *a, const void *b)
{
    struct PLAYER *p1, *p2;
    p1 = (struct PLAYER *)a;
    p2 = (struct PLAYER *)b;
    return (strcmp(p1->arrival, p2->arrival));
}
int cmpfunc_vip(const void *a, const void *b)
{
    struct PLAYER *p1, *p2;
    p1 = (struct PLAYER *)a;
    p2 = (struct PLAYER *)b;
    if (p1->type != p2->type)
        return (p2->type - p1->type);
    else
        return (strcmp(p1->arrival, p2->arrival));
}
int cmpfunc01(const void *a, const void *b)
{
    struct TABLE *t1, *t2;
    t1 = (struct TABLE *)a;
    t2 = (struct TABLE *)b;
    if (strcmp(t1->endtime, t2->endtime))
        return (strcmp(t1->endtime, t2->endtime));
    else
        return (t1->No - t2->No);
}
int cmpfunc02(const void *a, const void *b)
{
    return (((struct TABLE *)a)->No - ((struct TABLE *)b)->No);
}
int cmpfunc02_vip(const void *a, const void *b)
{
    struct TABLE *t1, *t2;
    t1 = (struct TABLE *)a;
    t2 = (struct TABLE *)b;
    if (t1->type != t2->type)
        return (t2->type - t1->type);
    else
        return (t1->No - t2->No);
}
void timetostr(int t1, char *s)
{

    int hh, mm, ss;
    hh = t1 / 3600;
    t1 = t1 - hh * 3600;
    mm = t1 / 60;
    ss = t1 - mm * 60;
    s[0] = '0' + hh / 10;
    s[1] = '0' + hh % 10;
    s[2] = ':';
    s[3] = '0' + mm / 10;
    s[4] = '0' + mm % 10;
    s[5] = ':';
    s[6] = '0' + ss / 10;
    s[7] = '0' + ss % 10;
    s[8] = '\0';
    return;
}
int strtotime(char *s)
{
    int hh, mm, ss;
    hh = (s[0] - '0') * 10 + (s[1] - '0');
    mm = (s[3] - '0') * 10 + (s[4] - '0');
    ss = (s[6] - '0') * 10 + (s[7] - '0');
    return (3600 * hh + 60 * mm + ss);
}

int main()
{
    int i, j, j_min, j_min1, k, N, M1, M2, i_P;
    struct PLAYER *Player, tmpPlayer;
    struct TABLE *Table;
    char deadTime[9], tmpTime[9];
    //init player
    scanf("%d", &N);
    Player = (struct PLAYER *)malloc(N * sizeof(struct PLAYER));
    for (i = 0; i < N; i++)
    {
        scanf("%s %d %d", Player[i].arrival, &(Player[i].during), &(Player[i].type));
        if (Player[i].during > 120)
            Player[i].during = 120;
    }
    qsort(Player, N, sizeof(struct PLAYER), cmpfunc);
    //init table
    scanf("%d %d", &M1, &M2);
    Table = (struct TABLE *)malloc(M1 * sizeof(struct TABLE));
    for (i = 0; i < M1; i++)
    {
        Table[i].No = i + 1;
        Table[i].count = 0;
        strcpy(Table[i].endtime, "08:00:00");
        Table[i].type = 0;
    }
    for (i = 0; i < M2; i++)
    {
        scanf("%d", &j);
        Table[j - 1].type = 1;
    }
    // main program
    i_P = 0;
    while (i_P < N)
    {
        i = 0;
        j = 0;
        j_min = -1;
        j_min1 = 0;
        qsort(Table, M1, sizeof(struct TABLE), cmpfunc01);
        if (strcmp(Table[0].endtime, Player[i_P].arrival) > 0)
            //可能多个player 和多个相同时间的table
            strcpy(deadTime, Table[i].endtime);
        else
            //仅有1个player 和多个table
            strcpy(deadTime, Player[i_P].arrival);
        if (strcmp(deadTime, "21:00:00") >= 0)
            break;
        while (i_P + i < N && strcmp(Player[i_P + i].arrival, deadTime) <= 0 && Player[i_P + i].type == 0)
            i++;
        while (j < M1 && strcmp(Table[j].endtime, deadTime) <= 0)
        {
            if (Table[j].type == 1)
            {
                if (j_min == -1)
                    j_min = j;
                else if (Table[j].No < Table[j_min].No)
                    j_min = j;
            }
            else if (Table[j_min1].No > Table[j].No)
                j_min1 = j;
            j++;
        }
        if (j_min != -1 && i_P + i < N && Player[i_P + i].type && strcmp(Player[i_P + i].arrival, deadTime) <= 0 && Player[i_P + i].type == 1)
        {
            tmpPlayer = Player[i_P + i];
            for (k = i; k > 0; k--)
                Player[i_P + k] = Player[i_P + k - 1];
            Player[i_P] = tmpPlayer;
            j = j_min;
        }
        else
            j = j_min1;
        timetostr(strtotime(deadTime) + 60 * Player[i_P].during, tmpTime);
        strcpy(Player[i_P].server, deadTime);
        strcpy(Table[j].endtime, tmpTime);
        Table[j].count++;
        printf("%s %s %d\n", Player[i_P].arrival, Player[i_P].server, (int)round(1.0 * (strtotime(Player[i_P].server) - strtotime(Player[i_P].arrival)) / 60));
        i_P++;
    }
    qsort(Table, M1, sizeof(struct TABLE), cmpfunc02);
    for (i = 0; i < M1 - 1; i++)
        printf("%d ", Table[i].count);
    printf("%d", Table[i].count);
    return 0;
}