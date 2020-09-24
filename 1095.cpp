//1095 Cars on Campus (30分)
//daTE:20200924
//数据清洗是关键，HASH并不需要
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define MAXSIZE 10000
struct CARinf
{
    char CARNo[8];
    int time;
    int status;
};
struct HASHTable
{
    int size;
    char (*key)[8];
    int *status; //in->1 and out->0
};
typedef HASHTable *pHAT;
pHAT createHash(int N)
{
    int i, Flag = 0;
    pHAT h1 = (pHAT)malloc(sizeof(struct HASHTable));
    if (N <= 2)
        N == 19;
    else
        while (1)
        {
            Flag = 0;
            for (i = 2; i < pow(N, 0.5) + 1; i++)
                if (N % i == 0)
                {
                    Flag = 1;
                    break;
                }
            if (Flag)
                N += 2;
            else
                break;
        }
    h1->size = N;
    h1->key = (char(*)[8])malloc(h1->size * sizeof(char(*)[8]));
    h1->status = (int *)malloc(h1->size * sizeof(int));
    for (i = 0; i < h1->size; i++)
    {
        h1->key[i][0] = '\0';
        h1->status[i] = 0;
    }
    return h1;
}
int get_pos(pHAT H1, char *key)
{
    int i, pos = 0;
    for (i = 0; i < 7; i++)
    {
        if (key[i] >= 'A')
            pos = pos << 2 + key[i] - 'A' + 10;
        else
            pos = pos << 2 + key[i] - '0';
    }
    pos = pos % H1->size;
    while (H1->key[pos][0] != '\0' && strcmp(H1->key[pos], key))
        pos = ++pos % H1->size;
    return (pos);
}
int to_time(char *t)
{
    return 3600 * (10 * (t[0] - '0') + t[1] - '0') + 60 * (10 * (t[3] - '0') + t[4] - '0') + (10 * (t[6] - '0') + t[7] - '0');
}
int cmpfunc(const void *a, const void *b)
{
    return (((struct CARinf *)a)->time - ((struct CARinf *)b)->time);
}
int cmpfunc01(const void *a, const void *b)
{
    struct CARinf *c1 = (struct CARinf *)a;
    struct CARinf *c2 = (struct CARinf *)b;
    if (strcmp(c1->CARNo, c2->CARNo))
        return (strcmp(c1->CARNo, c2->CARNo));
    else
        return (c1->time - c2->time);
}
int main()
{
    const int endTime = 23 * 3600 + 59 * 60 + 59;
    int i, j, k, pos, N1, N2, park;
    int maxTime = 0, maxCount = 0, totaltime = 0;
    char CarNo[8], Time[9], status[4], carMax[MAXSIZE][8];
    struct CARinf car[MAXSIZE + 1];
    pHAT H1 = createHash(2 * MAXSIZE + 1);
    scanf("%d %d", &N1, &N2);
    for (i = 0; i < N1; i++)
    {
        scanf("%s %s %s", car[i].CARNo, Time, status);
        car[i].time = to_time(Time);
        if (status[0] == 'i')
            car[i].status = 1;
        else
            car[i].status = 0;
    }
    j = 0;
    //check and calute maxparktime
    qsort(car, N1, sizeof(struct CARinf), cmpfunc01);
    car[N1].status = 0;
    car[N1].time = 0;
    strcpy(car[N1].CARNo, "\n");
    totaltime = 0;
    if (car[0].status == 0)
        car[0].time = endTime + 3600;
    for (i = 1; i < N1 + 1; i++)
    {
        if (strcmp(car[i].CARNo, car[i - 1].CARNo))
        {
            if (totaltime > maxTime)
            {
                maxTime = totaltime;
                maxCount = 1;
                strcpy(carMax[0], car[i - 1].CARNo);
            }
            else if (totaltime == maxTime)
            {
                strcpy(carMax[maxCount], car[i - 1].CARNo);
                maxCount++;
            }
            if (car[i - 1].status)
                car[i - 1].time = endTime + 3600;
            totaltime = 0;
            if (car[i].status == 0)
                car[i].time = endTime + 3600;
        }
        else if (car[i].status && car[i - 1].status)
            car[i - 1].time = endTime + 3600;
        else if (car[i].status == 0 && car[i - 1].status == 0)
            car[i].time = endTime + 3600;
        else if (car[i].status == 0 && car[i - 1].status)
            totaltime += car[i].time - car[i - 1].time;
    }
    //sort and solve
    qsort(car, N1, sizeof(struct CARinf), cmpfunc);
    j = 0;
    park = 0;
    for (i = 0; i < N2; i++)
    {
        scanf("%s", Time);
        while (j < N1 && car[j].time <= to_time(Time))
        {
            pos = get_pos(H1, car[j].CARNo);
            if (car[j].status)
            {
                strcpy(H1->key[pos], car[j].CARNo);
                H1->status[pos] = 1;
                park++;
            }
            else if (strcmp(H1->key[pos], car[j].CARNo) == 0)
            {
                H1->status[pos] = 0;
                park--;
            }
            j++;
        }
        printf("%d\n", park);
    }
    //print max park time
    for (i = 0; i < maxCount; i++)
        printf("%s ", carMax[i]);
    printf("%02d:%02d:%02d", maxTime / 3600, (maxTime - 3600 * (maxTime / 3600)) / 60, (maxTime - 3600 * (maxTime / 3600)) % 60);
    return (0);
}