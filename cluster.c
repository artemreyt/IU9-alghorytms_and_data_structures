#include <stdio.h>
#include <stdlib.h>

typedef struct Task_s
{
    int t1;
    int t2;
}   task_t;

typedef struct Queue_s
{
    int *heap;
    int size;
}   Queue;

void    swap(int *a, int *b);
void    SiftDown(int *heap, int k, int i);
void    BuildHeap(int *heap, int k);
void    SiftUp(int *heap, int i);
void    Insert(int *heap, int k, int value);
int     Pop(int *heap, int k);
int     pop(Queue *q);
void    InsertWithPriority(Queue *q, int value);

int     main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    task_t *arr = (task_t *) malloc(m * sizeof(task_t));
    for (int j = 0; j < m; j++)
        scanf("%d %d", &arr[j].t1, &arr[j].t2);
    Queue q = {NULL, 0};
    q.heap = (int *) malloc(n * sizeof(int));
    int i = 0;
    while (i < n && i < m)
    {
        q.heap[i] = arr[i].t1 + arr[i].t2;
        q.size++;
        i++;
    }
    BuildHeap(q.heap, q.size);
    int cur_time = 0;
    while (q.size > 0)
    {
        cur_time = pop(&q);
        if (i < m)
        {
            int finish;
            if (cur_time >= arr[i].t1)
                finish = cur_time + arr[i].t2;
            else
                finish = arr[i].t1 + arr[i].t2;
            InsertWithPriority(&q, finish);
            i++;
        }
    }
    printf("%d\n", cur_time);
    free(q.heap);
    free(arr);
    return (0);
}

void    InsertWithPriority(Queue *q, int value)
{
    q->size++;
    Insert(q->heap, q->size, value);
}

int     pop(Queue *q)
{
    return Pop(q->heap, q->size--);
}

void swap(int *a, int *b)
{
    int buf = *a;
    *a = *b;
    *b = buf;
}

void    SiftDown(int *heap, int k, int i)
{
    if (i * 2 + 1 > k - 1)
        return ;
    int i_min = i * 2 + 1;
    if (i * 2 + 2 <= k - 1 && heap[i * 2 + 2] < heap[i_min])
        i_min = i * 2 + 2;
    if (heap[i] > heap[i_min])
    {
        swap(heap + i, heap + i_min);
        SiftDown(heap, k, i_min);
    }
}

void    BuildHeap(int *heap, int k)
{
    for (int i = k / 2 - 1; i >= 0; i--)
        SiftDown(heap, k, i);
}

void    SiftUp(int *heap, int i)
{
    if (i == 0)
        return;
    int parent = (i - 1) / 2;
    if (heap[i] < heap[parent])
    {
        swap(heap + i, heap + parent);
        SiftUp(heap, parent);
    }
}

void    Insert(int *heap, int k, int value)
{
    heap[k - 1] = value;
    SiftUp(heap, k - 1);
}

int     Pop(int *heap, int k)
{
    int result = heap[0];
    heap[0] = heap[k - 1];
    SiftDown(heap, k - 1, 0);
    return (result);
}
