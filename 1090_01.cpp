#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//1090 Highest Price in Supply Chain
//DATE:20200813
int main()
{
    int i, cur, layer, count = 0, max_layer = 0, N;
    int OutDegree[100000] = {0}, Parent[10000];
    double P, R;
    scanf("%d %lf %lf", &N, &P, &R);
    for (i = 0; i < N; i++)
    {
        scanf("%d", &Parent[i]);
        OutDegree[Parent[   i]]++;
    }
    //SOLVE
    for (i = 0; i < N; i++)
    {
        if (OutDegree[i])
        {
            cur = Parent[i];
            layer = 0;
            while (cur != -1)
            {
                cur = Parent[cur];
                layer++;
            }
            if (layer > max_layer)
            {
                max_layer = layer;
                count = 1;
            }
            else if (layer == max_layer)
                count++;
        }
    }
    printf("%.2lf %d", P * pow((1 + R / 100), max_layer + 1), count);
    return 0;
}