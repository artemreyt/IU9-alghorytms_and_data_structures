#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STR_LEN 100000

typedef struct Node_s
{
    struct Node_s   *child[26];
    int             count;
}   Node_t;

Node_t  *InitNode();
void    Insert(Node_t *root, Node_t *current, char *str, int i);
void    Delete(Node_t *root, char *str);
int     Prefix(Node_t *root, char *str);
void    free_tree(Node_t *root);

int     main()
{
    int n;
    Node_t *root = InitNode();
    scanf("%d", &n);
    char    command[7];
    char    *str = (char *) calloc(STR_LEN + 1, 1);
    for (int i = 0; i < n; i++)
    {
        scanf("%s %s",command, str);
        if (strcmp(command, "INSERT") == 0)
            Insert(root, root, str, 0);
        else if (strcmp(command, "DELETE") == 0)
            Delete(root, str);
        else
            printf("%d\n", Prefix(root, str));
    }
    free_tree(root);
    return (0);
}



Node_t  *InitNode()
{
    Node_t *node = (Node_t *) malloc(sizeof(Node_t));
    node->count = 0;
    for (int i = 0; i < 26; i++)
        node->child[i] = NULL;
    return (node);
}

void    Insert(Node_t *root, Node_t *current, char *str, int i)
{
    current->count++;
    if (str[i] != '\0')
    {
        if (current->child[str[i] - 'a'] == NULL)
            current->child[str[i] - 'a'] = InitNode();
        Insert(root, current->child[str[i] - 'a'], str, i + 1);
    }
    else
    {
        int sum = 0;
        for (int i = 0; i < 26; i++)
        {
            if (current->child[i] != NULL)
                sum += current->child[i]->count;
        }
        if (current->count - sum == 2)
            Delete(root, str);
    }
}

void    Delete(Node_t *root, char *str)
{
    root->count--;
    if (*str != '\0')
        Delete(root->child[*str - 'a'], str + 1);
    for (int i = 0; i < 26; i++)
    {
        if (root->child[i] != NULL && root->child[i]->count == 0)
        {
            free(root->child[i]);
            root->child[i] = NULL;
        }
    }
}

int     Prefix(Node_t *root, char *str)
{
    if (*str != '\0')
    {
        if (root->child[*str - 'a'] != NULL)
            return (Prefix(root->child[*str - 'a'], str + 1));
        return (0);
    }
    return (root->count);
}

void    free_tree(Node_t *root)
{
    for (int i = 0; i < 26; i++)
    {
        if (root->child[i] != NULL)
            free_tree(root->child[i]);
    }
    free(root);
}
