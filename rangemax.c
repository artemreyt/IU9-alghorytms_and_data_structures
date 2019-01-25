#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void    scan_arr(int *arr, int n);
int     max(int *arr, int l, int r);

int     main()
{
    int n, m;
    scanf("%d", &n);
    int *arr = (int *) malloc(n * sizeof(int));
    scan_arr(arr, n);
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
        char    command[5];
        scanf("%s", command);
        if (strcmp(command, "MAX") == 0)
        {
            int left, right;
            scanf("%d %d", &left, &right);
            printf("%d", max(arr, left, right));
        }
        else
        {
            int index, value;
            scanf("%d %d", &index, &value);
            arr[index] = value;
        }
    }
    free(arr);
}

void    scan_arr(int *arr, int n)
{
    for (int i = 0; i < n; i++)
        scanf("%d", arr + i);
}

int     max(int *arr, int l, int r)
{
    int max = arr[l];
    for (int i = l + 1; i <= r; i++)
        if (arr[i] > max)
            max = arr[i];
    return (max);
}
