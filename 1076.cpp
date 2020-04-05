#include <stdio.h>
#include <stdlib.h>
#include <cstring>
//1076 Forwards on Weibo (30分)
struct follower
{
    int NO;
    follower *next;
};
int bfs(int node, follower *FOLLOWER, int visit[], int N, int L)
{
    int index_i = 0, index_j = 0;
    int(*Queue)[2] = (int(*)[2])malloc(2 * N * sizeof(int));
    follower *cur;
    visit[node] = 1;
    Queue[0][0] = node;
    Queue[0][1] = 0;
    while (index_j < N && index_i <= index_j && Queue[index_i][1] < L)
    {
        node = Queue[index_i][0];
        cur = &FOLLOWER[node];
        while (cur != NULL && cur->NO != -1)
        {
            if (visit[cur->NO] == 0)
            {
                visit[cur->NO] = 1;
                index_j++;
                Queue[index_j][0] = cur->NO;
                Queue[index_j][1] = Queue[index_i][1] + 1;
            }
            cur = cur->next;
        }
        index_i++;
    }
    return index_j;
}

int main()
{
    int i, j, num, tmp, N, L, K;
    int *visit, *query;
    double P;
    follower *FOLLOWER, *rear;
    scanf("%d %d", &N, &L);
    FOLLOWER = (follower *)malloc((N + 1) * sizeof(follower));
    visit = (int *)malloc(N * sizeof(int));
    //initial FOLLOWER
    for (i = 0; i < N + 1; i++)
    {
        FOLLOWER[i].NO = -1;
        FOLLOWER[i].next = NULL;
    }
    //create FOLLOWER
    for (i = 0; i < N; i++)
    {
        scanf("%d", &num);
        if (num)
            for (j = 0; j < num; j++)
            {
                scanf("%d", &tmp);
                rear = &FOLLOWER[tmp];
                if (rear->NO != -1)
                {
                    while (rear->next != NULL)
                        rear = rear->next;
                    rear->next = (follower *)malloc(sizeof(follower));
                    rear->next->NO = i + 1;
                    rear->next->next = NULL;
                }
                else
                    rear->NO = i + 1;
            }
    }
    scanf("%d", &K);
    query = (int *)malloc(K * sizeof(int));
    //BFS
    for (i = 0; i < K; i++)
        scanf("%d", &query[i]);
    for (i = 0; i < K; i++)
    {
        memset(visit, 0, sizeof(int) * (N + 1));
        printf("%d\n", bfs(query[i], FOLLOWER, visit, N, L));
    }
    return 0;
}