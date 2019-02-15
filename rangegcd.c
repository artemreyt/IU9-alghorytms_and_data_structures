#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int     gcd(int a, int b);
void    build_tree(int *arr, int left, int right, int *tree, int tree_i);
int     query(int *tree, int tree_i, int left, int right, int l_search, int r_search);
void    scan_arr(int *arr, int n);


int     main()
{
    int n, m;
    scanf("%d", &n);
    int *arr = (int *) malloc(n * sizeof(int));
    int *tree = (int *) calloc(4*n, sizeof(int));
    scan_arr(arr, n);
    build_tree(arr, 0, n - 1, tree, 0);
    scanf("%d", &m);
    int l, r;
    for (int i = 1; i <= m; i++)
    {
        scanf("%d %d", &l, &r);
        printf("%d\n", query(tree, 0, 0, n - 1, l, r));
    }
    free(arr);
    free(tree);
    return (0);
}


void    build_tree(int *arr, int left, int right, int *tree, int tree_i)
{
    if (left == right)
        tree[tree_i] = abs(arr[left]);
    else
    {
        int middle = (left + right) / 2;
        build_tree(arr, left, middle, tree, tree_i * 2 + 1);
        build_tree(arr, middle + 1, right, tree, tree_i * 2 + 2);
        tree[tree_i] = gcd(tree[tree_i * 2 + 1], tree[tree_i * 2 + 2]);
    }
}

int     query(int *tree, int tree_i, int left, int right, int l_search, int r_search)
{
    if (left >= l_search && right <= r_search)
        return (tree[tree_i]);
    else if (left > r_search || right < l_search)
        return (0);
    int middle = (left + right) / 2;
    return gcd(query(tree, tree_i * 2 + 1, left, middle, l_search, r_search),
                query(tree, tree_i * 2 + 2, middle + 1, right, l_search, r_search));
}

int     gcd(int a, int b)
{
    while (a > 0 && b > 0)
    {
        if (a > b)
            a %= b;
        else
            b %= a;
    }
    return (a + b);
}

void    scan_arr(int *arr, int n)
{
    for (int i = 0; i < n; i++)
        scanf("%d", arr + i);
}
