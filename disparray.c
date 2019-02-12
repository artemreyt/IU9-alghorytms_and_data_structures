#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node_s
{
    int             key;
    int             value;
    struct Node_s   *next;
} Node_t;

void        Add_or_Change(Node_t **head, int key, int value);
void        Delete_from_List(Node_t **head, int key);
Node_t      *FindInList(Node_t *head, int key);
void        free_list(Node_t *head);


typedef struct HashTable_s
{
    Node_t  **list;
    int     m;
} HashTable_t;

HashTable_t     InitHashTable(int m);
int             Hash(int k, int m);
void            Assign(HashTable_t *t, int key, int value);
int             At(HashTable_t t, int key);
void            free_table(HashTable_t t);


int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    HashTable_t table = InitHashTable(m);
    char command[7];
    int k, v;
    for (int i = 0; i < n; i++)
    {
        scanf("%s %d", command, &k);
        if (strcmp("ASSIGN", command) == 0)
        {
            scanf("%d", &v);
            Assign(&table, k, v);
        }
        else
            printf("%d\n", At(table, k));
    }
    free_table(table);
    return (0);
}

/*  List  */

void    Add_or_Change(Node_t **head, int key, int value)
{
    Node_t *new = (Node_t *) malloc(sizeof(Node_t));
    new->value = value;
    new->key = key;
    new->next = NULL;
    if (*head == NULL)
        *head = new;
    else
    {
        Node_t *current = *head;
        while (current->next != NULL && current->key != key)
            current = current->next;
        if (current->key == key)
        {
            current->value = value;
            free(new);
        }
        else
            current->next = new;
    }
}

void    Delete_from_List(Node_t **head, int key)
{
    Node_t *current = *head, *prev = NULL;
    while (current->key != key)
    {
        prev = current;
        current = current->next;
    }
    if (prev != NULL)
        prev->next = current->next;
    else
        *head = (*head)->next;
    free(current);
}

Node_t      *FindInList(Node_t *head, int key)
{
    while (head != NULL && head->key != key)
        head = head->next;
    return (head);
}

void    free_list(Node_t *head)
{
    Node_t *prev = NULL;
    while (head != NULL)
    {
        prev = head;
        head = head->next;
        free(prev);
    }
}

/*    Hash Table   */

HashTable_t     InitHashTable(int m)
{
    HashTable_t new_table;
    new_table.list = (Node_t **) calloc(m, sizeof(Node_t *));
    new_table.m = m;
    return (new_table);
}

int      Hash(int k, int m)
{
    return (k % m);
}

void     Assign(HashTable_t *t, int key, int value)
{
    int hash = Hash(key, t->m);
    if (value != 0)
        Add_or_Change(t->list + hash, key, value);
    else
        Delete_from_List(t->list + hash, key);
}

int     At(HashTable_t t, int key)
{
    int hash = Hash(key, t.m);
    if (t.list[hash] != NULL)
    {
        Node_t *res = FindInList(t.list[hash], key);
        if (res != NULL)
            return (res->value);
    }
    return (0);
}

void    free_table(HashTable_t t)
{
    for (int i = 0; i < t.m; i++)
        free_list(t.list[i]);
    free(t.list);
}
