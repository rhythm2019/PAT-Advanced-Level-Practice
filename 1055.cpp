//1055 The World's Richest (25分)
//DATE:20200910
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLEN 1000
struct RICHMAN
{
    char name[9];
    int age;
    int worth;
};
int cmpfunc(const void *a, const void *b)
{
    struct RICHMAN *r1, *r2;
    r1 = (struct RICHMAN *)a;
    r2 = (struct RICHMAN *)b;
    if (r1->worth == r2->worth)
    {
        if (r1->age != r2->age)
            return (r1->age - r2->age);
        else
            return (strcmp(r1->name, r2->name));
    }
    else
        return (r2->worth - r1->worth);
}
int main()
{
    int i, j, k, N1, N2;
    int result[MAXLEN][101] = {0}, COUNT[MAXLEN], AGE[MAXLEN][2];
    struct RICHMAN *rich;
    scanf("%d %d", &N1, &N2);
    rich = (struct RICHMAN *)malloc(N1 * sizeof(struct RICHMAN));
    for (i = 0; i < N1; i++)
        scanf("%s %d %d", rich[i].name, &rich[i].age, &rich[i].worth);
    qsort(rich, N1, sizeof(struct RICHMAN), cmpfunc);
    //////
    for (i = 0; i < N2; i++)
        scanf("%d %d %d", COUNT + i, &AGE[i][0], &AGE[i][1]);
    for (i = 0; i < N1; i++)
        for (j = 0; j < N2; j++)
            if (result[j][0] < COUNT[j] && rich[i].age <= AGE[j][1] && rich[i].age >= AGE[j][0])
            {
                result[j][0]++;
                result[j][result[j][0]] = i;
            }
    for (i = 0; i < N2; i++)
    {
        printf("Case #%d:\n", i + 1);
        if (result[i][0])
            for (j = 1; j <= result[i][0]; j++)
            {
                k = result[i][j];
                printf("%s %d %d\n", rich[k].name, rich[k].age, rich[k].worth);
            }
        else
            printf("None\n");
    }
    return 0;
}