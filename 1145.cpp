//1145 Hashing - Average Search Time (25分)
//DATE:20201006
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int count = 0;
struct HASHTABLE
{
    int SIZE;
    int *key;
    //int *value;
};
typedef struct HASHTABLE *pHash;
pHash create_Hash(int size)
{
    int i, Flag = 0;
    pHash h1 = (pHash)malloc(sizeof(struct HASHTABLE));
    if (size <= 2)
        size = 2;
    else
        while (Flag == 0)
        {
            Flag = 1;
            for (i = 2; i < (int)pow(size, 0.5) + 1; i++)
                if (size % i == 0)
                {
                    size++;
                    Flag = 0;
                    break;
                }
        }
    h1->SIZE = size;
    h1->key = (int *)malloc(size * sizeof(int));
    //h1->value = (int *)malloc(size * sizeof(int));
    for (i = 0; i < size; i++)
    {
        h1->key[i] = 0;
        //h1->value[i] = 0;
    }
    return h1;
}
int get_pos(pHash H1, int key)
{
    long long i = 0, pos, newpos;
    pos = key % H1->SIZE;
    newpos = pos;
    while (i < H1->SIZE && H1->key[newpos] && H1->key[newpos] != key)
    {
        newpos = (newpos + 2 * i + 1) % H1->SIZE;
        i++;
    }
    if (i == H1->SIZE)
        return (-1);
    else
        return ((int)newpos);
}
void count_pos(pHash H1, int key)
{
    long long i = 0, pos, newpos;
    pos = key % H1->SIZE;
    newpos = pos;
    while (i < H1->SIZE && H1->key[newpos] && H1->key[newpos] != key)
    {
        i++;
        newpos = (pos + i * i) % H1->SIZE;
    }
    count += i + 1;
    return;
}
bool insertHash(pHash H1, int key)
{
    int pos = get_pos(H1, key);
    if (pos == -1)
    {
        printf("%d cannot be inserted.\n", key);
        return false;
    }
    H1->key[pos] = key;
    // H1->value[pos] = 1;
    return true;
}
int main()
{
    int i, j, MSIZE, N, M;
    pHash H1;
    scanf("%d %d %d", &MSIZE, &N, &M);
    H1 = create_Hash(MSIZE);
    for (i = 0; i < N; i++)
    {
        scanf("%d", &j);
        insertHash(H1, j);
    }
    for (i = 0; i < M; i++)
    {
        scanf("%d", &j);
        count_pos(H1, j);
    }
    printf("%.1f", 1.0 * count / M);
    return 0;
}