//1091 Acute Stroke (30分)
//daTE:20200914
//DFS 是超时的
#include <stdio.h>
#include <stdlib.h>
//DFS NO
void dfs(int i, int j, int k, int A[][128][60], int visit[][128][60], int *volume, int M, int N, int L)
{
    if (i >= 0 && i < M && j >= 0 && j < N && k >= 0 && k < L && A[i][j][k] == 1 && visit[i][j][k] == 0)
    {
        visit[i][j][k] = 1;
        (*volume)++;
        //next node
        dfs(i + 1, j, k, A, visit, volume, M, N, L);
        dfs(i, j - 1, k, A, visit, volume, M, N, L);
        dfs(i - 1, j, k, A, visit, volume, M, N, L);
        dfs(i, j + 1, k, A, visit, volume, M, N, L);
        dfs(i, j, k - 1, A, visit, volume, M, N, L);
        dfs(i, j, k + 1, A, visit, volume, M, N, L);
    }
    return;
}
// DFS NO
int main()
{
    int i, j, k, M, N, L, volume, Gvolume = 0, threshold;
    int A[1286][128][60] = {0}, visit[1286][128][60] = {0};
    scanf("%d %d %d %d", &M, &N, &L, &threshold);
    for (k = 0; k < L; k++)
        for (i = 0; i < M; i++)
        {
            for (j = 0; j < N; j++)
                scanf("%d", &A[i][j][k]);
        }
    //DFS NO
    for (k = 0; k < L; k++)
        for (i = 0; i < M; i++)
            for (j = 0; j < N; j++)
            {
                if (A[i][j][k] == 1 && visit[i][j][k] == 0)
                {
                    volume = 0;
                    dfs(i, j, k, A, visit, &volume, M, N, L);
                    if (volume >= threshold)
                        Gvolume = Gvolume + volume;
                }
            }
    //DFS NO
    printf("%d", Gvolume);
}