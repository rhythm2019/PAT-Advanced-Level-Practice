//1091 Acute Stroke (30分)
//daTE:20200921
#include <stdio.h>
#include <stdlib.h>
#define ROW 1286
#define COLUMN 128
#define LAYER 60
short A[ROW][COLUMN][LAYER] = {0}, visit[ROW][COLUMN][LAYER] = {0};
short queue[ROW * COLUMN * LAYER][3];
int main()
{
    int M, N, L, volume, Gvolume = 0, threshold;
    int begin = 0, end = 0;
    int i, j, k, ii, jj, kk;
    scanf("%d %d %d %d", &M, &N, &L, &threshold);
    for (k = 0; k < L; k++)
        for (i = 0; i < M; i++)
            for (j = 0; j < N; j++)
                scanf("%hd", &A[i][j][k]);
    for (kk = 0; kk < L; kk++)
        for (ii = 0; ii < M; ii++)
            for (jj = 0; jj < N; jj++)
            {
                if (A[ii][jj][kk] == 1 && visit[ii][jj][kk] == 0)
                {
                    visit[ii][jj][kk] = 1;
                    begin = 0;
                    end = 0;
                    queue[begin][0] = ii;
                    queue[begin][1] = jj;
                    queue[begin][2] = kk;
                    while (begin <= end)
                    {
                        i = queue[begin][0];
                        j = queue[begin][1];
                        k = queue[begin][2];
                        if (i + 1 >= 0 && i + 1 < M && A[i + 1][j][k] == 1 && visit[i + 1][j][k] == 0)
                        {
                            end++;
                            queue[end][0] = i + 1;
                            queue[end][1] = j;
                            queue[end][2] = k;
                            visit[i + 1][j][k] = 1;
                        }
                        if (j - 1 >= 0 && j - 1 < N && A[i][j - 1][k] == 1 && visit[i][j - 1][k] == 0)
                        {
                            end++;
                            queue[end][0] = i;
                            queue[end][1] = j - 1;
                            queue[end][2] = k;
                            visit[i][j - 1][k] = 1;
                        }
                        if (i - 1 >= 0 && i - 1 < M && A[i - 1][j][k] == 1 && visit[i - 1][j][k] == 0)
                        {
                            end++;
                            queue[end][0] = i - 1;
                            queue[end][1] = j;
                            queue[end][2] = k;
                            visit[i - 1][j][k] = 1;
                        }
                        if (j + 1 >= 0 && j + 1 < N && A[i][j + 1][k] == 1 && visit[i][j + 1][k] == 0)
                        {
                            end++;
                            queue[end][0] = i;
                            queue[end][1] = j + 1;
                            queue[end][2] = k;
                            visit[i][j + 1][k] = 1;
                        }
                        if (k - 1 >= 0 && k - 1 < L && A[i][j][k - 1] == 1 && visit[i][j][k - 1] == 0)
                        {
                            end++;
                            queue[end][0] = i;
                            queue[end][1] = j;
                            queue[end][2] = k - 1;
                            visit[i][j][k - 1] = 1;
                        }
                        if (k + 1 >= 0 && k + 1 < L && A[i][j][k + 1] == 1 && visit[i][j][k + 1] == 0)
                        {
                            end++;
                            queue[end][0] = i;
                            queue[end][1] = j;
                            queue[end][2] = k + 1;
                            visit[i][j][k + 1] = 1;
                        }
                        begin++;
                    }
                    if (end + 1 >= threshold)
                        Gvolume = Gvolume + end + 1;
                }
            }
    printf("%d", Gvolume);
}