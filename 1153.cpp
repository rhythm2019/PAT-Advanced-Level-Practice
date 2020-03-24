#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//1153 Decode Registration Card of PAT (25分)
struct PTA
{
    char ID[14];
    int score;
};
struct Query
{
    int NO;
    char s[7];
};
struct exam
{
    int NO;
    int count;
};
PTA *student;
int cmpfunc1(const void *a, const void *b)
{

    PTA *s1 = &(student[*(int *)a]);
    PTA *s2 = &(student[*(int *)b]);
    if (s1->score > s2->score)
        return (-1);
    else if (s1->score < s2->score)
        return (1);
    else
        return (strcmp(s1->ID, s2->ID));
}
int cmpfunc3(const void *a, const void *b)
{
    exam *s1 = (exam *)a;
    exam *s2 = (exam *)b;
    if (s1->count > s2->count)
        return (-1);
    else if (s1->count < s2->count)
        return (1);
    else
        return (s1->NO - s2->NO);
}

int main()
{
    int i, j, k, N, M, count, sum, *result;
    exam result1[1000];
    PTA *stu;
    Query *query;
    char s[4];
    scanf("%d %d", &N, &M);
    stu = (PTA *)malloc(N * sizeof(PTA));
    student = stu;
    result = (int *)malloc(N * sizeof(int));

    query = (Query *)malloc(M * sizeof(Query));
    for (i = 0; i < N; i++)
        scanf("%s %d", stu[i].ID, &(stu[i].score));
    for (i = 0; i < M; i++)
        scanf("%d %s", &(query[i].NO), query[i].s);
    for (i = 0; i < M; i++)
    {
        if (query[i].NO == 1)
        {
            count = 0;
            for (j = 0; j < N; j++)
                if (query[i].s[0] == stu[j].ID[0])
                {
                    result[count] = j;
                    count++;
                }
            //排序
            qsort(result, count, sizeof(result[0]), cmpfunc1);
            printf("Case %d: %d %s\n", i + 1, query[i].NO, query[i].s);
            if (count)

                for (j = 0; j < count; j++)
                    printf("%s %d\n", stu[result[j]].ID, stu[result[j]].score);
            else
                printf("NA\n");
        }
        else if (query[i].NO == 2)
        {
            count = 0;
            sum = 0;
            for (j = 0; j < N; j++)
                if (query[i].s[0] == stu[j].ID[1] and query[i].s[1] == stu[j].ID[2] and query[i].s[2] == stu[j].ID[3])
                {
                    sum = sum + stu[j].score;
                    count++;
                }
            printf("Case %d: %d %s\n", i + 1, query[i].NO, query[i].s);
            if (count)
                printf("%d %d\n", count, sum);
            else
                printf("NA\n");
        }
        else if (query[i].NO == 3)
        {
            count = 0;
            for (j = 0; j < 1000; j++)
            {
                result1[j].count = 0;
                result1[j].NO = j;
            }
            for (j = 0; j < N; j++)
                if (query[i].s[0] == stu[j].ID[4] and query[i].s[1] == stu[j].ID[5] and query[i].s[2] == stu[j].ID[6] and query[i].s[3] == stu[j].ID[7] and query[i].s[4] == stu[j].ID[8] and query[i].s[5] == stu[j].ID[9])
                {
                    s[0] = stu[j].ID[1];
                    s[1] = stu[j].ID[2];
                    s[2] = stu[j].ID[3];
                    s[3] = '\0';
                    k = atoi(s);
                    result1[k].count += 1;
                    count += 1;
                }
            //排序
            qsort(result1, 1000, sizeof(result1[0]), cmpfunc3);
            printf("Case %d: %d %s\n", i + 1, query[i].NO, query[i].s);
            if (count)
                for (k = 0; result1[k].count; k++)
                    printf("%d %d\n", result1[k].NO, result1[k].count);
            else
                printf("NA\n");
        }
    }
}
