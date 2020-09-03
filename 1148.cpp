#include <stdio.h>
#include <stdlib.h>
//1148 Werewolf - Simple Version (20分)
//DATE:20200903
int main()
{
    int i, j, N, Flag, A[101];
    int wolf1, wolf2, liar_count, wolf_liar_count;
    scanf("%d", &N);
    for (i = 0; i < N; i++)
        scanf("%d", A + i + 1);
    for (wolf1 = 1; wolf1 < N; wolf1++)
        for (wolf2 = wolf1 + 1; wolf2 <= N; wolf2++)
        {
            liar_count = 0;
            wolf_liar_count = 0;
            Flag = 1;
            for (i = 1; i <= N; i++)
            {
                j = A[i];
                if ((j > 0 && (j == wolf1 || j == wolf2)) || (j < 0 && -j != wolf1 && -j != wolf2))
                {
                    liar_count++;
                    if (i == wolf1 || i == wolf2)
                        wolf_liar_count++;
                }
                if (liar_count > 2 || wolf_liar_count > 1)
                {
                    break;
                    Flag = 0;
                }
            }
            if (Flag && liar_count == 2 && wolf_liar_count == 1)
            {
                printf("%d %d", wolf1, wolf2);
                return (0);
            }
        }
    printf("No Solution");
    return (0);
}