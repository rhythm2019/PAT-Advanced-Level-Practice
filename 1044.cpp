//1044 Shopping in Mars (25分)
//DATE:20200815
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i, j, k, N, AMOUNT, SUM, MINVALUE = 100000000;
    int A[100001] = {0};
    scanf("%d %d", &N, &AMOUNT);
    for (i = 1; i < N + 1; i++)
        scanf("%d", &A[i]);
    i = 1;
    j = 1;
    SUM = A[i];
    while (i < N + 1 && j < N + 1)
    {
        if (SUM < AMOUNT)
        {
            if ((++j) < N + 1)
                SUM += A[j];
        }
        else if (SUM > AMOUNT)
        {
            if ((SUM - AMOUNT) < MINVALUE)
                MINVALUE = SUM - AMOUNT;
            SUM -= A[i];
            i++;
        }
        else
        {
            printf("%d-%d\n", i, j);
            if ((++j) < N + 1)
                SUM += A[j];
            MINVALUE = 0;
        }
    }
    if (MINVALUE)
    {
        i = 1;
        j = 1;
        SUM = A[i];
        while (i < N + 1 && j < N + 1)
        {
            if (SUM < AMOUNT)
            {
                if ((++j) < N + 1)
                    SUM += A[j];
            }
            else if (SUM > AMOUNT)
            {
                if ((SUM - AMOUNT) == MINVALUE)
                    printf("%d-%d\n", i, j);
                SUM -= A[i];
                i++;
            }
        }
    }
    return 0;
}