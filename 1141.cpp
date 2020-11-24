//1141 PAT Ranking of Institutions (25分)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define MAXTABLESIZE 350000 /* 允许开辟的最大散列表长度 */
typedef enum
{
    Legitimate,
    Empty,
    Deleted
} EntryType;
struct SCHOOL
{
    char school[7];
    float score;
    int num; //人数
};
struct Cell
{
    SCHOOL Data;    /* 存放元素 */
    EntryType Info; /* 单元状态 */
};
struct HashTable
{
    int TableSize; /* 表的最大长度 */
    Cell *Cells;   /* 存放散列单元数据的数组 */
};
int NextPrime(int N)
{
    int i, p = (N % 2) ? N + 2 : N + 1;
    while (p <= MAXTABLESIZE)
    {
        for (i = (int)sqrt(p); i > 2; i--)
            if (!(p % i))
                break;
        if (i == 2)
            break;
        else
            p += 2;
    }
    return p;
}

HashTable *CreateTable(int TableSize)
{
    int i;
    HashTable *H = (HashTable *)malloc(sizeof(struct HashTable));
    H->TableSize = NextPrime(TableSize);
    H->Cells = (Cell *)malloc(H->TableSize * sizeof(Cell));
    for (i = 0; i < H->TableSize; i++)
        H->Cells[i].Info = Empty;
    return H;
}

int Hash(const char Key[], int TableSize)
{
    unsigned int h = 0;
    while (*Key != '\0')
        h = (h << 5) + *Key++;
    return h % TableSize;
}

int Find(HashTable *H, char *Key)
{
    int CurrentPos, NewPos;
    int CNum = 0;
    NewPos = CurrentPos = Hash(Key, H->TableSize); /* 初始散列位置 */
    /* 当该位置的单元非空，并且不是要找的元素时，发生冲突 */
    while (H->Cells[NewPos].Info != Empty && strcmp(H->Cells[NewPos].Data.school, Key))
    {
        /* 统计1次冲突，并判断奇偶次 */
        if (++CNum % 2)
        {                                                      /* 奇数次冲突 */
            NewPos = CurrentPos + (CNum + 1) * (CNum + 1) / 4; /* 增量为+[(CNum+1)/2]^2 */
            if (NewPos >= H->TableSize)
                NewPos = NewPos % H->TableSize; /* 调整为合法地址 */
        }
        else
        {                                          /* 偶数次冲突 */
            NewPos = CurrentPos - CNum * CNum / 4; /* 增量为-(CNum/2)^2 */
            while (NewPos < 0)
                NewPos += H->TableSize; /* 调整为合法地址 */
        }
    }
    return NewPos; /* 此时NewPos或者是Key的位置，或者是一个空单元的位置（表示找不到）*/
}

bool Insert(HashTable *H, char *Key, float score)
{
    int Pos = Find(H, Key);
    if (H->Cells[Pos].Info != Legitimate)
    {
        H->Cells[Pos].Info = Legitimate;
        H->Cells[Pos].Data.num = 1;
        H->Cells[Pos].Data.score = score;
        strcpy(H->Cells[Pos].Data.school, Key);
        return true;
    }
    else
    {
        printf("键值已存在");
        return false;
    }
}

//1141 PAT单位排行 (25分)
int cmpfunc1(const void *a, const void *b)
{
    SCHOOL *sch1 = (SCHOOL *)a;
    SCHOOL *sch2 = (SCHOOL *)b;
    if (int(sch1->score) != int(sch2->score))
        return (int(sch2->score) - int(sch1->score));
    else if (sch1->num != sch2->num)
        return (sch1->num - sch2->num);
    else
        return (strcmp(sch1->school, sch2->school));
}

int main()
{
    int i, j, N, tmp, TableSize = 300000;
    float score;
    char ID[7], school[7];
    HashTable *H;
    SCHOOL *data;
    H = CreateTable(TableSize);
    scanf("%d", &N);
    for (i = 0; i < N; i++)
    {
        scanf("%s %f %s", ID, &score, school);
        j = 0;
        while (school[j] != '\0')
        {
            if (school[j] >= 'A' && school[j] <= 'Z')
                school[j] += 32;
            j++;
        }
        if (ID[0] == 'T')
            score = score * 1.5;
        else if (ID[0] == 'B')
            score = score / 1.5;
        // HASH
        j = Find(H, school);
        if (H->Cells[j].Info != Legitimate)
            Insert(H, school, score);
        else
        {
            H->Cells[j].Data.num = H->Cells[j].Data.num + 1;
            H->Cells[j].Data.score = H->Cells[j].Data.score + score;
        }
    }
    j = 0; //count
    data = (SCHOOL *)malloc(H->TableSize * sizeof(SCHOOL));
    for (i = 0; i < H->TableSize; i++)

        if (H->Cells[i].Info == Legitimate)
        {
            strcpy(data[j].school, H->Cells[i].Data.school);
            data[j].score = H->Cells[i].Data.score;
            data[j].num = H->Cells[i].Data.num;
            j++;
        }
    qsort(data, j, sizeof(data[0]), cmpfunc1);
    tmp = 1;
    printf("%d\n", j);
    printf("%d %s %d %d\n", tmp, data[0].school, int(data[0].score), data[0].num);
    for (i = 1; i < j; i++)
    {
        if (int(data[i].score) != int(data[i - 1].score))
            tmp = i + 1;
        printf("%d %s %d %d\n", tmp, data[i].school, int(data[i].score), data[i].num);
    }
    return (0);
}