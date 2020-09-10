//1067 Sort with Swap(0, i) (25分)
//DATE:20200910
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i, i_a, i_b, k, N, COUNT = 0;
    int A[100000], invA[100000];
    scanf("%d", &N);
    for (i = 0; i < N; i++)
    {
        scanf("%d", A + i);
        invA[A[i]] = i;
        if (A[i] == i)
            COUNT++;
    }
    k = 0;
    i = 1;
    //swap(0,i)
    while (COUNT < N)
    {
        if (A[0])
        {
            i_a = invA[0];
            i_b = invA[i_a];
            A[i_a] = i_a;
            A[i_b] = 0;
            invA[0] = i_b;
            invA[i_a] = i_a;
            COUNT++;
            if (i_b == 0)
                COUNT++;
        }
        else
        {
            while (A[i] == i)
                i++;
            A[0] = A[i];
            invA[A[0]] = 0;
            A[i] = 0;
            invA[0] = i;
            COUNT--;
        }
        k++;
    }
    printf("%d", k);
    return (0);
}