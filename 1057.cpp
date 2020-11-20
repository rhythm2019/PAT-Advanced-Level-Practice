//1057 Stack (30分)
//DATE:20201120
// Min-max heap
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100000
int DATA[47 * 47 * 47];
int BUCKET01[47], BUCKET02[47][47];
int peek_median(int N)
{
    int i = 0, j = 0, k = 0;
    int COUNT = 0;
    N = (N + 1) / 2;
    while (COUNT + BUCKET01[i] < N)
    {
        COUNT += BUCKET01[i];
        i++;
    }
    while (COUNT + BUCKET02[i][j] < N)
    {
        COUNT += BUCKET02[i][j];
        j++;
    }
    while (COUNT + DATA[47 * 47 * i + 47 * j + k] < N)
    {
        COUNT += DATA[47 * 47 * i + 47 * j + k];
        k++;
    }
    return (47 * 47 * i + 47 * j + k);
}
void add(int element)
{
    int i = element / (47 * 47), j = element % (47 * 47) / 47;
    DATA[element]++;
    BUCKET01[i]++;
    BUCKET02[i][j]++;
    return;
}
void del(int element)
{
    int i = element / (47 * 47), j = element % (47 * 47) / 47;
    DATA[element]--;
    BUCKET01[i]--;
    BUCKET02[i][j]--;
    return;
}
int main()
{
    int i, j, N;
    int stack[MAXSIZE], N_stack = 0;
    char command[11];
    scanf("%d", &N);
    for (i = 0; i < N; i++)
    {
        scanf("%s", command);
        if (command[1] == 'o') //pop
        {
            if (N_stack == 0)
                printf("Invalid\n");
            else
            {
                N_stack--;
                printf("%d\n", stack[N_stack]);
                del(stack[N_stack]);
            }
        }
        else if (command[1] == 'u') //push
        {
            scanf("%d", stack + N_stack);
            N_stack++;
            add(stack[N_stack - 1]);
        }
        else
        {
            if (N_stack == 0)
            {
                printf("Invalid\n");
                continue;
            }
            else
                printf("%d\n", peek_median(N_stack));
        }
    }
    return (0);
}