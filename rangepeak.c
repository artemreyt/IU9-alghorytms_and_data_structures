#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void    build_tree(int *arr, int n, int left, int right, int *tree, int tree_i);
void    scan_arr(int *ar, int n);
int     is_peak(int *arr, int i, int n);
int     query(int *tree, int tree_i, int left, int right, int l_search, int r_search);
void    update(int *tree, int tree_i, int left, int right, int i, int *arr, int n);

int     main()
{
    int n, m;
    scanf("%d", &n);
    int *arr = (int *) malloc(n * sizeof(int));
    int *tree = (int *) calloc(4*n, sizeof(int));
    scan_arr(arr, n);
    build_tree(arr, n, 0, n - 1, tree, 0);
    
    /*for (int i = 0; i < 4*n; i++) printf("%d ", tree[i]);
    puts("");*/
    
    scanf("%d", &m);
    char command[5];
    int l, r;
    for (int i = 1; i <= m; i++)
    {
        scanf("%s %d %d", command, &l, &r);
        if (strcmp(command, "PEAK") == 0)
            printf("%d\n", query(tree, 0, 0, n - 1, l, r));
        else
        {
            arr[l] = r;
            update(tree, 0, 0, n - 1, l, arr, n);
            if (n != 1)
            {
                if (l != 0)
                    update(tree, 0, 0, n - 1, l - 1, arr, n);
                if (l != n - 1)
                    update(tree, 0, 0, n - 1, l + 1, arr, n);
            }
           /*for (int i = 0; i < 4*n; i++) printf("%d ", tree[i]);
            puts("");*/
            
        }
    }
    free(arr);
    free(tree);
}

void    build_tree(int *arr, int n, int left, int right, int *tree, int tree_i)
{
    if (left == right)
        tree[tree_i] = is_peak(arr, left, n);
    else
    {
        int medium = (left + right) / 2;
        build_tree(arr, n, left, medium, tree, tree_i * 2 + 1);
        build_tree(arr, n, medium + 1, right, tree, tree_i * 2 + 2);
        tree[tree_i] = tree[tree_i * 2 + 1] + tree[tree_i * 2 + 2];
    }
}

int     query(int *tree, int tree_i, int left, int right, int l_search, int r_search)
{
    if (left >= l_search && right <= r_search)
        return (tree[tree_i]);
    else if (left > r_search || right < l_search)
        return (0);
    int middle = (left + right) / 2;
    return (query(tree, tree_i * 2 + 1, left, middle, l_search, r_search) +
                query(tree, tree_i * 2 + 2, middle + 1, right, l_search, r_search));
}

void    update(int *tree, int tree_i, int left, int right, int i, int *arr, int n)
{
    if (left == right)
        tree[tree_i] = is_peak(arr, i, n);
    else
    {
        int middle = (left + right) / 2;
        if (i <= middle)
            update(tree, tree_i * 2 + 1, left, middle, i, arr, n);
        else
            update(tree, tree_i * 2 + 2, middle + 1, right, i, arr, n);
        tree[tree_i] = tree[tree_i * 2 + 1] + tree[tree_i * 2 + 2];
    }
}
                   
void    scan_arr(int *arr, int n)
{
    for (int i = 0; i < n; i++)
        scanf("%d", arr + i);
}

int     is_peak(int *arr, int i, int n)
{
    if (n == 1)
        return (1);
    if ((!i && arr[i] >= arr[i + 1]) || (i && i != n - 1 && arr[i] >= arr[i + 1] && arr[i] >= arr[i - 1]) || (i == n - 1 && arr[i] >= arr[i - 1]))
        return (1);
    return (0);
}
