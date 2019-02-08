#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Queue_s
{
    int     *buffer;
    int     head;
    int     tail;
    int     len, buf_size;
}   Queue;

void    InitQueue(Queue *q)
{
    q->buf_size = 4;
    q->len = 0;
    q->buffer = (int *) malloc(q->buf_size * sizeof(int));
    q->head = q->tail = 0;
}

void    Resize(Queue *q)
{
    int *new_buffer = (int *) malloc(q->buf_size * 2 * sizeof(int));
    int i = q->head, i_new = 0;
    do
    {
        new_buffer[i_new] = q->buffer[i];
        i = (i + 1) % q->buf_size;
    } while (i != q->tail);
    q->head = 0;
    q->tail = q->buf_size;
    q->buf_size *= 2;
    free(q->buffer);
    q->buffer = new_buffer;
}

void    Enqueue(Queue *q, int x)
{
    q->len++;
    if (q->len > q->buf_size)
        Resize(q);
    q->buffer[q->tail] = x;
    q->tail = (q->tail + 1) % q->buf_size;
}

int     Dequeue(Queue *q)
{
    q->len--;
    int result = q->buffer[q->head];
    q->head = (q->head + 1) % q->buf_size;
    return (result);
}

int     main(int argc, char **argv)
{
    int n;
    FILE *fp = fopen(argv[1], "r");
    Queue q;
    InitQueue(&q);
    fscanf(fp, "%d", &n);
    char command[10];
    for (int i = 0; i < n; i++)
    {
        fscanf(fp, "%s", command);
        if (strcmp(command, "ENQ") == 0)
        {
            int x;
            fscanf(fp, "%d", &x);
            Enqueue(&q, x);
        }
        else if (strcmp(command, "DEQ") == 0)
            printf("%d\n", Dequeue(&q));
        else
            printf("%s\n", (q.len == 0) ? "true" : "false");
    }
    free(q.buffer);
    return (0);
}

