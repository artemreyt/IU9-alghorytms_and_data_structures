#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE 1000001

void    build_tree(const char *str, int *tree, int tree_i, int left, int right);
int     query(int *tree, int tree_i, int left, int right, int l_search, int r_search);
void    update(int *tree, int tree_i, int left, int right, int i, char *s, int s_len);

int     main()
{
    int n, m;
    char *str = (char *) calloc(BUF_SIZE, 1);
    scanf("%s", str);
    n = strlen(str);
    int  *tree = (int *) calloc(2 * n - 1, sizeof(int));
    build_tree(str, tree, 0, 0 , n - 1);
    scanf("%d", &m);
    char *s = (char *) calloc(BUF_SIZE, 1);
    char command[4];
    int  l, r;
    for (int i = 0; i < m; i++)
    {
        scanf("%s", command);
        if (strcmp(command, "HD") == 0)
        {
            scanf("%d %d", &l, &r);
            int result = query(tree, 0, 0, n - 1, l, r);
            if ((r - l + 1) % 2 == 1)
                printf("%s\n", (result & (result - 1)) == 0 ? "YES" : "NO");
            else
                printf("%s\n", !result ? "YES" : "NO");
        }
        else
        {
            scanf("%d %s", &l, s);
            int s_len = strlen(s);
            update(tree, 0, 0, n - 1, l, s, s_len);
          /*  for (int i = 0; i < 2 * n - 1; i++)
                printf("tree[%d] = %d\n", i, tree[i]);*/
        }
    }
    free(s);
    free(tree);
    free(str);
    return (0);
}

void    build_tree(const char *str, int *tree, int tree_i, int left, int right)
{
    if (left == right)
        tree[tree_i] = 1 << (str[left] - 'a');
    else
    {
        int middle = (left + right) / 2;
        build_tree(str, tree, tree_i * 2 + 1, left, middle);
        build_tree(str, tree, tree_i * 2 + 2, middle + 1, right);
        tree[tree_i] = tree[tree_i * 2 + 1] ^ tree[tree_i * 2 + 2];
    }
}

int     query(int *tree, int tree_i, int left, int right, int l_search, int r_search)
{
    if (left >= l_search && right <= r_search)
        return (tree[tree_i]);
    else if (left > r_search || right < l_search)
        return (0);
    int middle = (left + right) / 2;
    return (query(tree, tree_i * 2 + 1, left, middle, l_search, r_search)
            ^ query(tree, tree_i * 2 + 2, middle + 1, right, l_search, r_search));
}

void    update(int *tree, int tree_i, int left, int right, int i, char *s, int s_len)
{
    if (left == right)
        tree[tree_i] = 1 << (s[left - i] - 'a');
    else
    {
        int middle = (left + right) / 2;
        if (i <= middle)
            update(tree, tree_i * 2 + 1, left, middle, i, s, s_len);
        if (i + s_len - 1 >= middle + 1)
            update(tree, tree_i * 2 + 2, middle + 1, right, i, s, s_len);
        tree[tree_i] = tree[tree_i * 2 + 1] ^ tree[tree_i * 2 + 2];
    }
}
