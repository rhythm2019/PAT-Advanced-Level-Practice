//1057 Stack (30分)
//DATE:20201112
// Min-max heap
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100000
struct Heap
{
    int type; //0 MAX HEAP;1 MIN HEAP
    int N;
    int A[MAXSIZE];
};
void UP(struct Heap *heap, int index)
{
    int tmp;
    if (heap->type == 0) //MaxHeap
    {
        while (index > 0 && heap->A[index] > heap->A[(index - 1) / 2])
        {
            tmp = heap->A[(index - 1) / 2];
            heap->A[(index - 1) / 2] = heap->A[index];
            heap->A[index] = tmp;
            index = (index - 1) / 2;
        }
    }
    else
    {
        while (index && heap->A[index] < heap->A[(index - 1) / 2])
        {
            tmp = heap->A[(index - 1) / 2];
            heap->A[(index - 1) / 2] = heap->A[index];
            heap->A[index] = tmp;
            index = (index - 1) / 2;
        }
    }
    return;
}
void DOWN(struct Heap *heap, int index)
{
    int tmp, N = heap->N;
    if (heap->type == 0) //MaxHeap
    {
        while (index < N && 2 * index + 1 < N)
        {
            if (2 * index + 2 < N && heap->A[2 * index + 2] >= heap->A[2 * index + 1] && heap->A[2 * index + 2] > heap->A[index])
            {
                tmp = heap->A[2 * index + 2];
                heap->A[2 * index + 2] = heap->A[index];
                heap->A[index] = tmp;
                index = 2 * index + 2;
            }
            else if (heap->A[2 * index + 1] > heap->A[index])
            {
                tmp = heap->A[2 * index + 1];
                heap->A[2 * index + 1] = heap->A[index];
                heap->A[index] = tmp;
                index = 2 * index + 1;
            }
            else
                break;
        }
    }
    else
    {
        while (index < N && 2 * index + 1 < N)
        {
            if (2 * index + 2 < N && heap->A[2 * index + 2] <= heap->A[2 * index + 1] && heap->A[2 * index + 2] < heap->A[index])
            {
                tmp = heap->A[2 * index + 2];
                heap->A[2 * index + 2] = heap->A[index];
                heap->A[index] = tmp;
                index = 2 * index + 2;
            }
            else if (heap->A[2 * index + 1] < heap->A[index])
            {
                tmp = heap->A[2 * index + 1];
                heap->A[2 * index + 1] = heap->A[index];
                heap->A[index] = tmp;
                index = 2 * index + 1;
            }
            else
                break;
        }
    }
    return;
}
void search(struct Heap *heap, int index, int element, int *flag)
{
    if (heap->type == 1) //minHeap
    {
        if (*flag == -1 && index < heap->N)
        {
            if (heap->A[index] == element)
            {
                *flag = index;
                return;
            }
            else if (heap->A[index] > element)
                return;
            else
            {
                search(heap, 2 * index + 1, element, flag);
                if (*flag == -1)
                    search(heap, 2 * index + 2, element, flag);
            }
        }
        return;
    }
    else //maxHeap
    {
        if (*flag == -1 && index < heap->N)
        {
            if (heap->A[index] == element)
            {
                *flag = index;
                return;
            }
            else if (heap->A[index] < element)
                return;
            else
            {
                search(heap, 2 * index + 1, element, flag);
                if (*flag == -1)
                    search(heap, 2 * index + 2, element, flag);
            }
        }
        return;
    }
}
void add(struct Heap *heap, int element)
{
    heap->A[heap->N] = element;
    heap->N++;
    UP(heap, heap->N - 1);
    return;
}
void del(struct Heap *heap, int index)
{
    heap->A[index] = heap->A[heap->N - 1];
    heap->N--;
    UP(heap, index);
    DOWN(heap, index);
    return;
}

int main()
{
    int i, j, N;
    int stack[MAXSIZE], N_stack = 0;
    char command[11];
    struct Heap minH, maxH;
    minH.N = 0;
    minH.type = 1;
    maxH.N = 0;
    maxH.type = 0;
    scanf("%d", &N);
    for (i = 0; i < N; i++)
    {
        scanf("%s", command);
        if (command[1] == 'o') //pop
        {
            if (N_stack == 0)
                printf("Invalid\n");
            else
            {
                N_stack--;
                printf("%d\n", stack[N_stack]);
                
                if (maxH.N > 0 && stack[N_stack] <= maxH.A[0])
                {
                    j = -1;
                    search(&maxH, 0, stack[N_stack], &j);
                    del(&maxH, j);
                }
                else
                {
                    j = -1;
                    search(&minH, 0, stack[N_stack], &j);
                    del(&minH, j);
                }
            }
        }
        else if (command[1] == 'u') //push
        {
            scanf("%d", stack + N_stack);
            N_stack++;
            if (maxH.N > 0 && stack[N_stack - 1] <= maxH.A[0])
                add(&maxH, stack[N_stack - 1]);
            else
                add(&minH, stack[N_stack - 1]);
        }
        else
        {

            if (N_stack == 0)
            {
                printf("Invalid\n");
                continue;
            }
            if (maxH.N <= (N_stack + 1) / 2)
            {
                for (j = maxH.N; j < (N_stack + 1) / 2; j++)
                {
                    add(&maxH, minH.A[0]);
                    del(&minH, 0);
                }
            }
            else
            {
                for (j = maxH.N; j > (N_stack + 1) / 2; j--)
                {
                    add(&minH, maxH.A[0]);
                    del(&maxH, 0);
                }
            }
            printf("%d\n", maxH.A[0]);
        }
    }
    return 0;
}