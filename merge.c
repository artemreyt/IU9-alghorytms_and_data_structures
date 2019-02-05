#include <stdio.h>
#include <stdlib.h>

typedef struct Element
{
    int value;
    int arr_index;
} elem_t;


void swap(elem_t *a, elem_t *b)
{
    elem_t buf = *a;
    *a = *b;
    *b = buf;
}

void    SiftDown(elem_t *heap, int k, int i)
{
    if (i * 2 + 1 > k - 1)
        return ;
    int i_min = i * 2 + 1;
    if (i * 2 + 2 <= k - 1 && heap[i * 2 + 2].value < heap[i_min].value)
        i_min = i * 2 + 2;
    if (heap[i].value > heap[i_min].value)
    {
        swap(heap + i, heap + i_min);
        SiftDown(heap, k, i_min);
    }
}

void    BuildHeap(elem_t *heap, int k)
{
    for (int i = k / 2 - 1; i >= 0; i--)
        SiftDown(heap, k, i);
}

void    SiftUp(elem_t *heap, int i)
{
    if (i == 0)
        return;
    int parent = (i - 1) / 2;
    if (heap[i].value < heap[parent].value)
    {
        swap(heap + i, heap + parent);
        SiftUp(heap, parent);
    }
}

void    Insert(elem_t *heap, int k, elem_t value)
{
    heap[k - 1] = value;
    SiftUp(heap, k - 1);
}

elem_t     Pop(elem_t *heap, int k)
{
    elem_t result = heap[0];
    heap[0] = heap[k - 1];
    SiftDown(heap, k - 1, 0);
    return (result);
}

void    scan_arr(int *arr, int n)
{
    for (int i = 0; i < n; i++)
        scanf("%d", arr + i);
}

int     arrays_are_empty(int *arr_lens, int *index_in_array, int k)
{
    for (int i = 0; i < k; i++)
        if (arr_lens[i] != index_in_array[i])
            return (0);
    return (1);
}

int     main()
{
    int k;
    scanf("%d", &k);
    int *arr_lens = (int *) malloc(k * sizeof(int));
    elem_t *heap = (elem_t *) malloc(k * sizeof(elem_t));
    scan_arr(arr_lens, k);
    int n = 0;
    for (int i = 0; i < k; i++)
        n += arr_lens[i];
    elem_t **matrix = (elem_t **) malloc(k * sizeof(elem_t *));
    for (int i = 0; i < k; i++)
    {
        matrix[i] = (elem_t *) malloc(arr_lens[i] * sizeof(elem_t));
        for (int j = 0; j < arr_lens[i]; j++)
        {
            scanf("%d", &matrix[i][j].value);
            matrix[i][j].arr_index = i;
        }
    }
    int *index_in_array = (int *) malloc(k * sizeof(int));
    for (int i = 0; i < k; i++)
        Insert(heap, i + 1, matrix[i][0]);
    for (int i = 0; i < k; i++)
        index_in_array[i] = 1;
    int n_output = 0;
    while (n_output < n - k)
    {
        elem_t deleted = Pop(heap, k);
        int index = deleted.arr_index;
        while (index_in_array[index] == arr_lens[index])
            index = (index + 1) % k;
        Insert(heap, k, matrix[index][index_in_array[index]]);
        index_in_array[index]++;
        printf("%d ", deleted.value);
        n_output++;
    }
    for (int i = k; i > 0; i--)
        printf("%d ", Pop(heap, i).value);
    for (int i = 0; i < k; i++)
        free(matrix[i]);
    free(matrix);
    free(index_in_array);
    free(arr_lens);
    free(heap);
    return (0);
}
