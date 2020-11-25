#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAXSIZE 10000
//1114 Family Property (25分)
//DATE:20200823
struct person
{
    int Gset;
    int Garea;
    int delegate;
    int COUNT;
    int nGset;
    int nGarea;
};
int findparent(int id, int *parent)
{
    while (id != parent[id])
        id = parent[id];
    return (id);
}
void search_union(int id1, int id2, int *parent)
{
    if (findparent(id1, parent) != findparent(id2, parent))
        parent[findparent(id2, parent)] = findparent(id1, parent);
    return;
}
int cmpfunc(const void *a, const void *b)
{
    struct person *p1 = (struct person *)a, *p2 = (struct person *)b;
    if (p1->nGset == 0)
        return (1);
    else if (p2->nGset == 0)
        return (-1);
    else
    {
        if (1.0 * p1->nGarea / p1->COUNT > 1.0 * p2->nGarea / p2->COUNT)
            return (-1);
        else if (1.0 * p1->nGarea / p1->COUNT < 1.0 * p2->nGarea / p2->COUNT)
            return (1);
        else
            return (p1->delegate - p2->delegate);
    }
}

int main()
{
    int i, j, N, id, p1, p2, child, parent[MAXSIZE];
    struct person Family[MAXSIZE];
    for (i = 0; i < MAXSIZE; i++)
    {
        parent[i] = i;
        Family[i].Gset = 0;
        Family[i].Garea = 0;
        Family[i].delegate = MAXSIZE + 1;
        Family[i].COUNT = 0;
        Family[i].nGset = 0;
        Family[i].nGarea = 0;
    }
    scanf("%d", &N);
    for (i = 0; i < N; i++)
    {
        scanf("%d %d %d", &id, &p1, &p2);
        if (p1 != -1)
            search_union(id, p1, parent);
        if (p2 != -1)
            search_union(id, p2, parent);
        scanf("%d", &j);
        while (j)
        {
            scanf("%d", &child);
            search_union(id, child, parent);
            j--;
        }
        scanf("%d %d", &Family[id].Gset, &Family[id].Garea);
    }
    for (i = 0; i < MAXSIZE; i++)
    {
        id = i;
        p1 = findparent(id, parent);
        Family[p1].COUNT++;
        Family[p1].nGset += Family[id].Gset;
        Family[p1].nGarea += Family[id].Garea;
        if (id < Family[p1].delegate)
            Family[p1].delegate = id;
    }
    qsort(Family, MAXSIZE, sizeof(struct person), cmpfunc);
    for (i = 0; Family[i].nGset; i++)
        ;
    printf("%d\n", i);
    for (j = 0; j < i; j++)
        printf("%04d %d %.3f %.3f\n", Family[j].delegate, Family[j].COUNT, 1.0 * Family[j].nGset / Family[j].COUNT, 1.0 * Family[j].nGarea / Family[j].COUNT);
    return 0;
}