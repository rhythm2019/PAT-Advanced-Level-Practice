#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 1000
//1128 N Queens Puzzle (20分)
//DATE:20200823
int main()
{
    int i, j, k, N1, N2, Flag;
    int lst01[MAXSIZE], matrix[MAXSIZE + 1];
    scanf("%d", &N1);
    for (i = 0; i < N1; i++)
    {
        Flag = 1;
        scanf("%d", &N2);
        for (j = 0; j < N2; j++)
        {
            scanf("%d", lst01 + j);
            matrix[j] = 0;
        }
        matrix[j] = 0;
        for (j = 0; j < N2; j++)
        {
            if (matrix[lst01[j]] == 1)
            {
                Flag = 0;
                break;
            }
            for (k = 0; k < j; k++)
                if (lst01[k] == lst01[j] + j - k || lst01[k] == lst01[j] + k - j)
                {
                    Flag = 0;
                    break;
                }            
            if (Flag == 0)
                break;
            matrix[lst01[j]] = 1;
        }
        if (Flag)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}