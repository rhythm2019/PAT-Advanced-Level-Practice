#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//1090 Highest Price in Supply Chain (25)
//DATE:20200813
int max_layer = 0, count = 0;
struct RETAILER
{
    int adj;
    struct RETAILER *next;
};
int dfs(int node, struct RETAILER *retailer, int LAYER)
{
    int curNode;
    struct RETAILER *curD = &retailer[node];
    if (!(curD->next))
    {
        if (LAYER > max_layer)
        {
            max_layer = LAYER;
            count = 1;
        }
        else if (LAYER == max_layer)
            count++;
    }
    while (curD->next)
    {
        curD = curD->next;                
        dfs(curD->adj, retailer, LAYER + 1);        
    }
    return 1;
}
int main()
{
    int i, j, NO, root, N;
    struct RETAILER *retailer, *rear[100000], *cur;
    double P, R;
    scanf("%d %lf %lf", &N, &P, &R);
    retailer = (struct RETAILER *)malloc(N * sizeof(struct RETAILER));
    for (i = 0; i < N; i++)
    {
        retailer[i].adj = -1;
        retailer[i].next = NULL;
        rear[i] = retailer + i;
    }
    //create Tree
    for (i = 0; i < N; i++)
    {
        scanf("%d", &NO);
        if (NO != -1)
        {
            cur = rear[NO];
            cur->next = (struct RETAILER *)malloc(sizeof(struct RETAILER));
            cur = cur->next;
            cur->adj = i;
            cur->next = NULL;
            rear[NO] = cur;
        }
        else
            root = i;
    }
    //SOLVE
    dfs(root, retailer, 0);
    printf("%.2lf %d", P * pow((1 + R / 100), max_layer), count);
    return 0;
}