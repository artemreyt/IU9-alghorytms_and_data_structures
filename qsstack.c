#include <stdlib.h>
#include <stdio.h>

typedef struct Task
{
    int low;
    int high;
}   task_t;

typedef struct Node
{
    task_t      value;
    struct Node *next;
}   node_t;

typedef struct Stack
{
    node_t *head;
    int     size;
}   stack_;

void    push(stack_ *stack_ptr, task_t value);
void    pop(stack_ *stack_ptr);
void    swap(int *a, int *b);
void    stack_qsort(int *arr, int n);

int     main()
{
    int n;
    scanf("%d", &n);
    int *arr = (int *) malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        scanf("%d", arr + i);
    stack_qsort(arr, n);
    for (int i = 0; i < n; i++)
        printf("%d%c", arr[i], (i < n - 1) ? ' ' : '\n');
    free(arr);
    return (0);
}

void    stack_qsort(int *arr, int n)
{
    int low, high;
    stack_ stack = {NULL, 0};
    push(&stack, (task_t){0, n - 1});
    while (stack.size)
    {
        low = stack.head->value.low;
        high = stack.head->value.high;
        pop(&stack);
        int left = low, right = high;
        int pivot = arr[(left + right) / 2];
        while (left <= right)
        {
            while (arr[left] < pivot)
                left++;
            while (arr[right] > pivot)
                right--;
            if (left <= right)
            {
                swap(arr + left, arr + right);
                left++;
                right--;
            }
        }
        if (left < high)
            push(&stack, (task_t){left, high});
        if (right > low)
            push(&stack, (task_t){low, right});
    }
}

void    push(stack_ *stack_ptr, task_t value)
{
    node_t *new_node = (node_t *) malloc(sizeof(node_t));
    new_node->value = value;
    if (stack_ptr->size == 0)
        new_node->next = NULL;
    else
        new_node->next = stack_ptr->head;
    stack_ptr->head = new_node;
    stack_ptr->size++;
}

void    pop(stack_ *stack_ptr)
{
    node_t *new_head = stack_ptr->head->next;
    free(stack_ptr->head);
    stack_ptr->head = new_head;
    stack_ptr->size--;
}

void    swap(int *a, int *b)
{
    int buf = *a;
    *a = *b;
    *b = buf;
}
