#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VALUE_LEN 10

typedef struct Top_s
{
    int key;
    char *value;
    struct Top_s *left, *right, *parent;
    int count;
} top_t;

top_t   *Minimum(top_t *root);
top_t   *Succ(top_t *x);
void    UpdateCount(top_t *t);
void    Insert(top_t **root, int key, char *value);
top_t   *LookUp(top_t *root, int key);
char    *SearchByRank(top_t *root, int x);
void    Delete(top_t **root, int k);
void    free_tree(top_t *root);

int     main()
{
    int n;
    scanf("%d", &n);
    char command[7];
    int x;
    top_t *root = NULL;
    for (int i = 0; i < n; i++)
    {
        scanf("%s %d", command, &x);
        if (strcmp(command, "INSERT") == 0)
        {
            char *v = (char *) calloc(VALUE_LEN + 1, 1);
            scanf("%s", v);
            Insert(&root, x, v);
        }
        else if (strcmp(command, "LOOKUP") == 0)
            puts(LookUp(root, x)->value);
        else if (strcmp(command, "DELETE") == 0)
            Delete(&root, x);
        else
            puts(SearchByRank(root, x));
    }
    free_tree(root);
    return (0);
}



top_t   *Minimum(top_t *root)
{
    if (root->left == NULL)
        return (root);
    return (Minimum(root->left));
}

top_t   *Succ(top_t *x)
{
    if (x->right != NULL)
        return (Minimum(x->right));
    return (NULL);
}

void    UpdateCount(top_t *t)
{
    while (t != NULL)
    {
        t->count = 1;
        if (t->left != NULL)
            t->count += t->left->count;
        if (t->right != NULL)
            t->count += t->right->count;
        t = t->parent;
    }
}

void    Insert(top_t **root, int key, char *value)
{
    if (*root == NULL)
    {
        *root = (top_t *) malloc(sizeof(top_t));
        (*root)->value = value;
        (*root)->left = (*root)->right = (*root)->parent = NULL;
        (*root)->count = 1;
        (*root)->key = key;
    }
    else
    {
        top_t *current = *root;
        while (!(current->left == NULL && key < current->key)
               && !(current->right == NULL && key > current->key))
        {
            if (key < current->key)
                current = current->left;
            else if (key > current->key)
                current = current->right;
            else
            {
                current->value = value;
                return;
            }
        }
        top_t *new_top = (top_t *) malloc(sizeof(top_t));
        new_top->value = value;
        new_top->key = key;
        new_top->left = new_top->right = NULL;
        new_top->count = 1;
        if (key < current->key)
            current->left = new_top;
        else
            current->right = new_top;
        new_top->parent = current;
        UpdateCount(current);
    }
}

top_t   *LookUp(top_t *root, int key)
{
    top_t *current = root;
    while (current->key != key)
    {
        if (key < current->key)
            current = current->left;
        else
            current = current->right;
    }
    return (current);
}

char    *SearchByRank(top_t *root, int x)
{
    int left_count = 0, right_count = 0;
    if (root->left != NULL)
        left_count = root->left->count;
    if (root->right != NULL)
        right_count = root->right->count;
    if (x == left_count)
        return (root->value);
    if (left_count > x)
        return (SearchByRank(root->left, x));
    return (SearchByRank(root->right, x - left_count - 1));
}

void    ReplaceNode(top_t **root, top_t *old, top_t *new)
{
    if (new != NULL)
    {
        new->parent = old->parent;
        new->count = old->count;
    }
    if (old->parent != NULL)
    {
        if (old->parent->left == old)
            old->parent->left = new;
        else
            old->parent->right = new;
    }
    if (*root == old)
        *root = new;
}
            
void    Delete(top_t **root, int k)
{
    top_t *del = LookUp(*root, k);
    if (del->left == NULL || del->right == NULL)
    {
        del->count--;
        UpdateCount(del->parent);
        if (del->left == NULL && del->right == NULL)
            ReplaceNode(root, del, NULL);
        else if (del->left == NULL)
            ReplaceNode(root, del, del->right);
        else if (del->right == NULL)
            ReplaceNode(root, del, del->left);
    }
    else
    {
        top_t *next = Succ(del);
        next->count--;
        UpdateCount(next->parent);
        ReplaceNode(root, next, next->right);
        del->left->parent = next;
        next->left = del->left;
        if (del->right != NULL)
            del->right->parent = next;
        next->right = del->right;
        ReplaceNode(root, del, next);
    }
    free(del->value);
    free(del);
}

void    free_tree(top_t *root)
{
    if (root->left != NULL)
        free_tree(root->left);
    if (root->right != NULL)
        free_tree(root->right);
    free(root->value);
    free(root);
}
