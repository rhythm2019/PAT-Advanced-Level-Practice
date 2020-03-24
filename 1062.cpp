#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>
//1062
struct stu
{
    char ID[9];
    int score1;
    int score2;
    int total;
    int type;
};
int cmpfunc1(const void *a, const void *b)
{
    stu *s1 = (stu *)a;
    stu *s2 = (stu *)b;
    if (s1->type != s2->type)
        return (s1->type - s2->type);
    else if (s1->total != s2->total)
        return (s2->total - s1->total);
    else if (s1->score1 != s2->score1)
        return (s2->score1 - s1->score1);
    else
        return (strcmp(s1->ID, s2->ID));
}

main()
{
    int i, count, score1, score2, N, L, H;
    char ID[9];
    stu *student;
    scanf("%d %d %d", &N, &L, &H);
    student = (stu *)malloc(N * sizeof(stu));
    count = 0;
    for (i = 0; i < N; i++)
    {
        scanf("%s %d %d", ID, &score1, &score2);
        if (score1 >= L && score2 >= L)
        {
            strcpy(student[count].ID, ID);
            student[count].score1 = score1;
            student[count].score2 = score2;
            student[count].total = score1 + score2;
            if (score1 >= H && score2 >= H)
                student[count].type = 1;
            else if (score1 >= H)
                student[count].type = 2;
            else if (score1 >= score2)
                student[count].type = 3;
            else
                student[count].type = 4;
            count++;
        }
    }
    //排序
    qsort(student, count, sizeof(student[0]), cmpfunc1);
    printf("%d\n", count);
    for (i = 0; i < count; i++)
        printf("%s %d %d\n", student[i].ID, student[i].score1, student[i].score2);
    return 0;
}