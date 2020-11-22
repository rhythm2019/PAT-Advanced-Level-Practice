//1139 First Contact (30分)
//DATE:20201121
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 10000
struct node
{
    int NO;
    struct node *next;
};
bool gender[MAXSIZE], G[MAXSIZE][MAXSIZE];
struct node *Adj[MAXSIZE];
int toNum(char *s)
{
    int N;
    if (s[0] == '-')
        N = (s[1] - '0') * 1000 + (s[2] - '0') * 100 + (s[3] - '0') * 10 + (s[4] - '0');
    else
    {
        N = (s[0] - '0') * 1000 + (s[1] - '0') * 100 + (s[2] - '0') * 10 + (s[3] - '0');
        gender[N] = true;
    }
    return (N);
}
void addNode(int n1, int n2)
{
    struct node *cur, *tmp;
    if (Adj[n1] == NULL || Adj[n1]->NO > n2)
    {
        tmp = (struct node *)malloc(sizeof(struct node));
        tmp->NO = n2;
        tmp->next = Adj[n1];
        Adj[n1] = tmp;
    }
    else
    {
        cur = Adj[n1];
        while (cur->next && cur->next->NO < n2)
            cur = cur->next;
        tmp = (struct node *)malloc(sizeof(struct node));
        tmp->NO = n2;
        tmp->next = cur->next;
        cur->next = tmp;
    }
    if (Adj[n2] == NULL || Adj[n2]->NO > n1)
    {
        tmp = (struct node *)malloc(sizeof(struct node));
        tmp->NO = n1;
        tmp->next = Adj[n2];
        Adj[n2] = tmp;
    }
    else
    {
        cur = Adj[n2];
        while (cur->next && cur->next->NO < n1)
            cur = cur->next;
        tmp = (struct node *)malloc(sizeof(struct node));
        tmp->NO = n1;
        tmp->next = cur->next;
        cur->next = tmp;
    }
    return;
}
int main()
{
    int i, j, N, M, n1, n2;
    struct node *cur1, *cur2;
    char s1[5], s2[5];
    scanf("%d %d", &N, &M);
    for (i = 0; i < M; i++)
    {
        scanf("%s %s", s1, s2);
        n1 = toNum(s1);
        n2 = toNum(s2);
        G[n1][n2] = true;
        G[n2][n1] = true;
        if (gender[n1] == gender[n2])
            addNode(n1, n2);
    }
    scanf("%d", &M);
    for (i = 0; i < M; i++)
    {
        scanf("%s %s", s1, s2);
        n1 = toNum(s1);
        n2 = toNum(s2);
        j = 0;
        cur1 = Adj[n1];
        while (cur1)
        {
            cur2 = Adj[n2];
            while (cur2)
            {
                if (G[cur1->NO][cur2->NO] && cur2->NO != n1 && cur1->NO != n2)
                    j++;
                cur2 = cur2->next;
            }
            cur1 = cur1->next;
        }
        if (j == 0)
        {
            printf("0\n");
            continue;
        }
        else
        {
            printf("%d\n", j);
            cur1 = Adj[n1];
            while (cur1)
            {
                cur2 = Adj[n2];
                while (cur2)
                {
                    if (G[cur1->NO][cur2->NO] && cur2->NO != n1 && cur1->NO != n2)
                        printf("%04d %04d\n", cur1->NO, cur2->NO);
                    cur2 = cur2->next;
                }
                cur1 = cur1->next;
            }
        }
    }
    return 0;
}