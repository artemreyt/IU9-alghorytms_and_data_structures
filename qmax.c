#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Node
{
    int         value;
    int         max;
    struct Node *next;
}   node_t;

typedef struct Queue_s
{
    node_t  *input;
    node_t  *output;
}   Queue;


void    push(node_t **head, int x);
void    pop(node_t **head);
void    free_stack(node_t *head);

void    Enqueue(Queue *q, int x);
int     Dequeue(Queue *q);
int     QueueEmpty(Queue q);
int     Maximum(Queue q);
void    free_queue(Queue q);

int     max(int a, int b);


int     main()
{
    int n;
    Queue q = {NULL, NULL};
    scanf("%d", &n);
    char command[10];
    for (int i = 0; i < n; i++)
    {
        scanf("%s", command);
        if (strcmp(command, "ENQ") == 0)
        {
            int x;
            scanf("%d", &x);
            Enqueue(&q, x);
        }
        else if (strcmp(command, "DEQ") == 0)
            printf("%d\n", Dequeue(&q));
        else if (strcmp(command, "MAX") == 0)
            printf("%d\n", Maximum(q));
        else
            printf("%s\n", QueueEmpty(q) ? "true" : "false");
    }
    free_queue(q);
    return (0);
}

void    push(node_t **head, int x)
{
    node_t *new_node = (node_t *) malloc(sizeof(node_t));
    new_node->next = *head;
    new_node->value = x;
    *head = new_node;
    if ((*head)->next == NULL)
        (*head)->max = x;
    else
        (*head)->max = max(x, (*head)->next->max);
}

void    free_stack(node_t *head)
{
    node_t *current = head;
    node_t *next;
    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
}

void    pop(node_t **head)
{
    node_t *new_head = (*head)->next;
    free(*head);
    *head = new_head;
}

void    Enqueue(Queue *q, int x)
{
    push(&(q->input), x);
}

int     Dequeue(Queue *q)
{
    int result;
    if (q->output == NULL)
    {
        while (q->input != NULL)
        {
            push(&(q->output), q->input->value);
            pop(&(q->input));
        }
    }
    result = q->output->value;
    pop(&(q->output));
    return (result);
}

int     QueueEmpty(Queue q)
{
    return !(q.input || q.output);
}

int     Maximum(Queue q)
{
    if (q.input == NULL && q.output != NULL)
        return (q.output->max);
    else if (q.input != NULL && q.output == NULL)
        return (q.input->max);
    return max(q.input->max, q.output->max);
}

void    free_queue(Queue q)
{
    free_stack(q.input);
    free_stack(q.output);
}

int     max(int a, int b)
{
    return (a > b) ? a : b;
}
