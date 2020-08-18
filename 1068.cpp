//1068 Find More Coins (30分)
//DATE:20200815
#include <stdio.h>
#include <stdlib.h>
void solve(int *A, int *B, int beginValue, int AMOUNT, int *Flag)
{
    int i, amount;
    if (*Flag)
        return;
    for (i = A[beginValue]; i >= 0; i--)
    {
        if (*Flag)
            return;
        amount = AMOUNT - i * beginValue;
        B[beginValue] = i;
        if (amount == 0)
        {
            *Flag = 1;
            return;
        }
        else if (amount && beginValue + 1 <= amount)
            solve(A, B, beginValue + 1, amount, Flag);
    }
    return;
}
int main()
{
    int i, j, N, AMOUNT, FLAG = 0;
    int A[101] = {0}, B[101] = {0};
    scanf("%d %d", &N, &AMOUNT);
    for (i = 0; i < N; i++)
    {
        scanf("%d", &j);
        A[j]++;
    }
    solve(A, B, 1, AMOUNT, &FLAG);
    if (FLAG)
    {
        i = 1;
        while (i <= AMOUNT && !B[i])
            i++;
        printf("%d", i);
        B[i]--;
        while (i <= AMOUNT)
        {
            while (B[i])
            {
                printf(" %d", i);
                B[i]--;
            }
            i++;
        }
    }
    else
        printf("No Solution");
    return 0;
}