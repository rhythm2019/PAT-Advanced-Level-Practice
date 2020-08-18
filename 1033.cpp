//1033 To Fill or Not to Fill (25分)
//DATE:20200815
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct CITY
{
    double price;
    int distance;
};
int cmpfunc(const void *a, const void *b)
{
    struct CITY *c1 = (struct CITY *)a;
    struct CITY *c2 = (struct CITY *)b;
    if (c1->distance != c2->distance)
        return (c1->distance - c2->distance);
    else
        return ((int)(c1->price - c2->price));
}
int main()
{
    int i, j, CMAX, END, Davg, N, distance;
    int *parent, *moreDistance;
    struct CITY *city;
    double *totalCost, price;
    scanf("%d %d %d %d", &CMAX, &END, &Davg, &N);
    N++;
    city = (struct CITY *)malloc(N * sizeof(struct CITY));
    totalCost = (double *)malloc(N * sizeof(double));
    parent = (int *)malloc(N * sizeof(int));
    moreDistance = (int *)malloc(N * sizeof(int));
    for (i = 0; i < N - 1; i++)
    {
        scanf("%lf %d", &city[i].price, &city[i].distance);
        parent[i] = -1;
        totalCost[i] = -1;
        moreDistance[i] = 0;
    }
    parent[N - 1] = -1;
    totalCost[N - 1] = -1;
    city[N - 1].price = 0;
    city[N - 1].distance = END;
    //solve
    qsort(city, N, sizeof(struct CITY), cmpfunc);
    if (city[0].distance)
    {
        printf("The maximum travel distance = 0.00");
        return (0);
    }
    else
    {
        totalCost[0] = 0;
        parent[0] = 0;
    }
    for (i = 0; i < N - 1; i++)
    {
        if (totalCost[i] == -1)
            break;
        for (j = i + 1; j < N; j++)
        {
            distance = city[j].distance - city[i].distance;
            if (distance > CMAX * Davg)
                break;
            if (moreDistance[i] > distance)
            {
                if (totalCost[j] == -1 || totalCost[j] > totalCost[i] + distance * city[parent[i]].price / Davg)
                {
                    totalCost[j] = totalCost[i] + distance * city[parent[i]].price / Davg;
                    parent[j] = parent[i];
                    if (city[j].price <= city[parent[j]].price)
                        moreDistance[j] = 0;
                    else
                        moreDistance[j] = moreDistance[i] - distance;
                }
            }
            else
            {
                if (totalCost[j] == -1 || totalCost[j] > totalCost[i] + moreDistance[i] * city[parent[i]].price / Davg + (distance - moreDistance[i]) * city[i].price / Davg)
                {
                    totalCost[j] = totalCost[i] + moreDistance[i] * city[parent[i]].price / Davg + (distance - moreDistance[i]) * city[i].price / Davg;
                    parent[j] = i;
                    if (city[j].price <= city[i].price)
                        moreDistance[j] = 0;
                    else
                        moreDistance[j] = CMAX * Davg - distance;
                }
            }
        }
    }
    if (totalCost[N - 1] != -1)
        printf("%.2lf", totalCost[N - 1]);
    else
    {
        for (i = N - 1; i >= 0 && totalCost[i] == -1; i--)
            ;
        printf("The maximum travel distance = %.2lf", (double)(city[i].distance + CMAX * Davg));
    }
    return 0;
}