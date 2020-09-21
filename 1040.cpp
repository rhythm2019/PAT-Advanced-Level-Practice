//1040 Longest Symmetric String (25分)
//DATE:20200825
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLEN 1010
int main()
{
    int i, j, k, COUNT = -1;
    int len1;
    char s1[MAXLEN], s2[MAXLEN];
    gets(s1);
    len1 = strlen(s1);
    j = 0;
    for (i = len1 - 1; i >= 0; i--)
        s2[j++] = s1[i];
    for (i = 0; i + COUNT < len1; i++)
        for (j = 0; j + COUNT < len1; j++)
        {
            k = 0;
            while (i + k < len1 && j + k < len1 && s1[i + k] == s2[j + k])
                k++;
            k--;
            if (k > COUNT)
                COUNT = k;
            if (i + k + 1 == len1)
            {
                printf("%d", COUNT + 1);
                return (0);
            }
        }
    printf("%d", COUNT + 1);
    return 0;
}