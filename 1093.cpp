//1093 Count PAT's (25分)
//DATE:20200815
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int i;
    int NT = 0, NAT = 0, NPAT = 0;
    char s[100001];
    scanf("%s", s);
    for (i = strlen(s) - 1; i >= 0; i--)
    {
        if (s[i] == 'T')
            NT++;
        else if (s[i] == 'A')
            NAT = NAT + NT;
        else if (s[i] == 'P')
            NPAT = (NPAT + NAT) % 1000000007;
    }
    printf("%d", NPAT);
    return 0;
}