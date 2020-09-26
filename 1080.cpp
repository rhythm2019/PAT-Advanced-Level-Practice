//1085 1080 Graduate Admission (30分)
//DATE:20200926
#include <stdio.h>
#include <stdlib.h>
struct STUDENT
{
    int GE, GI, Gtotal;
    int choice[5];
    int selected;
};
struct STUDENT stu[40000];
struct UNIVERSITY
{
    int quota, curquota, lst_stu;
};

int cmpfunc(const void *a, const void *b)
{

    int s1 = *(int *)a, s2 = *(int *)b;
    if (stu[s1].Gtotal != stu[s2].Gtotal)
        return (stu[s2].Gtotal - stu[s1].Gtotal);
    else
        return (stu[s2].GE - stu[s1].GE);
}
int cmpfunc01(const void *a, const void *b)
{

    int s1 = *(int *)a, s2 = *(int *)b;
    if (stu[s1].selected != stu[s2].selected)
        return (stu[s1].selected - stu[s2].selected);
    else
        return (s1 - s2);
}
int main()
{
    int i, j, k, nostu, nouniv, N, M, K, stuNo[40000];
    struct UNIVERSITY univ[100];
    scanf("%d %d %d", &N, &M, &K);
    for (i = 0; i < M; i++)
    {
        scanf("%d", &(univ[i].quota));
        univ[i].curquota = 0;
    }
    for (i = 0; i < N; i++)
    {
        stuNo[i] = i;
        scanf("%d %d", &stu[i].GE, &stu[i].GI);
        for (j = 0; j < K; j++)
            scanf("%d", stu[i].choice + j);
        stu[i].Gtotal = stu[i].GE + stu[i].GI;
        stu[i].selected = 101;
    }
    qsort(stuNo, N, sizeof(int), cmpfunc);
    for (i = 0; i < N; i++)
    {
        nostu = stuNo[i];
        for (j = 0; j < K; j++)
        {
            nouniv = stu[nostu].choice[j];
            if ((univ[nouniv].curquota < univ[nouniv].quota) || (univ[nouniv].curquota >= univ[nouniv].quota && stu[nostu].Gtotal == stu[univ[nouniv].lst_stu].Gtotal && stu[nostu].GE == stu[univ[nouniv].lst_stu].GE))
            {
                univ[nouniv].curquota++;
                univ[nouniv].lst_stu = nostu;
                stu[nostu].selected = nouniv;
                break;
            }
        }
    }
    qsort(stuNo, N, sizeof(int), cmpfunc01);
    k = 0;
    for (i = 0; i < M; i++)
    {
        if (univ[i].curquota)
        {
            for (j = 0; j < univ[i].curquota - 1; j++)
                printf("%d ", stuNo[k++]);
            printf("%d\n", stuNo[k++]);
        }
        else
            printf("\n");
    }
    return (0);
}