#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void    scan_arr(int *ar, int n);
void    build_tree(int *arr, int left, int right, int *tree, int tree_i);
int     max(int a, int b);
int     query(int *tree, int tree_i, int left, int right, int l_search, int r_search);
void    update(int *tree, int tree_i, int left, int right, int i, int value);

int     main()
{
    int n, m;
    scanf("%d", &n);
    int *arr = (int *) malloc(n * sizeof(int));
    int *tree = (int *) calloc(4*n, sizeof(int));
    scan_arr(arr, n);
    build_tree(arr, 0, n - 1, tree, 0);
    scanf("%d", &m);
    char command[4];
    int l, r;
    for (int i = 1; i <= m; i++)
    {
        scanf("%s %d %d", command, &l, &r);
        if (strcmp(command, "MAX") == 0)
            printf("%d\n", query(tree, 0, 0, n - 1, l, r));
        else
            update(tree, 0, 0, n - 1, l, r);
    }
    free(arr);
    free(tree);
    return (0);
}

void    build_tree(int *arr, int left, int right, int *tree, int tree_i)
{
    if (left == right)
        tree[tree_i] = arr[left];
    else
    {
        int medium = (left + right) / 2;
        build_tree(arr, left, medium, tree, tree_i * 2 + 1);
        build_tree(arr, medium + 1, right, tree, tree_i * 2 + 2);
        tree[tree_i] = max(tree[tree_i * 2 + 1], tree[tree_i * 2 + 2]);
    }
}

int     query(int *tree, int tree_i, int left, int right, int l_search, int r_search)
{
    if (left >= l_search && right <= r_search)
        return (tree[tree_i]);
    else if (left > r_search || right < l_search)
        return (-1000000000);
    int medium = (left + right) / 2;
    return  max(query(tree, tree_i * 2 + 1, left, medium, l_search, r_search),
                query(tree, tree_i * 2 + 2, medium + 1, right, l_search, r_search));
}

void    update(int *tree, int tree_i, int left, int right, int i, int value)
{
    if (left == right)
        tree[tree_i] = value;
    else
    {
        int medium = (left + right) / 2;
        if (i <= medium)
            update(tree, tree_i * 2 + 1, left, medium, i, value);
        else
            update(tree, tree_i * 2 + 2, medium + 1, right, i, value);
        tree[tree_i] = max(tree[tree_i * 2 + 1], tree[tree_i * 2 + 2]);
    }
}

int     max(int a, int b)
{
    return (a > b ? a : b);
}

void    scan_arr(int *arr, int n)
{
    for (int i = 0; i < n; i++)
        scanf("%d", arr + i);
}
