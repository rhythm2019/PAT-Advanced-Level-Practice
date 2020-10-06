//1152 Google Recruitment (20分)
//DATE:20201006
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int isprime(int num)
{
    int i;
    if (num > 2)
    {
        for (i = 2; i <= (int)pow(num, 0.5) + 1; i++)
            if (num % i == 0)
                return (0);
        return (1);
    }
    else if (num == 2)
        return (1);
    else
        return (0);
}

int main()
{
    int i, j, L, K, num;
    char s1[1000];
    scanf("%d %d", &L, &K);
    scanf("%s", s1);
    for (j = 0; j < L + 1 - K; j++)
    {
        num = 0;
        for (i = 0; i < K; i++)
            num = num + (s1[i + j] - '0') * (int)pow(10, (K - i - 1));
        if (isprime(num))
        {
            s1[j + K] = '\0';
            printf("%s", s1 + j);
            return (0);
        }
    }
    printf("404");
    return (0);
}