#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int i, j, N1, N2;
    long int S1[200000], S2[200000];
    scanf("%d", &N1);
    for (i = 0; i < N1; i++)
        scanf("%ld", S1 + i);
    scanf("%d", &N2);
    for (i = 0; i < N2; i++)
        scanf("%ld", S2 + i);
    i = 0;
    j = 0;
    while (i < N1 && j < N2)
    {
        if (i + j == (N1 + N2 + 1) / 2)
            break;
        if (S1[i] < S2[j])
            i++;
        else
            j++;
    }
    if(i + j == (N1 + N2 + 1) / 2)
    {
        if(i==0)
            printf("%ld", S2[(N1 + N2 + 1) / 2 - 1]);
        else if(j==0)
            printf("%ld", S1[(N1 + N2 + 1) / 2 - 1]);
        else if (S1[i - 1] > S2[j - 1])
            printf("%ld", S1[i - 1]);
        else
            printf("%ld", S2[j - 1]);
    }
    else if (i == N1)
        printf("%ld", S2[(N1 + N2 + 1) / 2 - N1 - 1]);
    else if (j == N2)
        printf("%ld", S1[(N1 + N2 + 1) / 2 - N2 - 1]);
    return (0);
}