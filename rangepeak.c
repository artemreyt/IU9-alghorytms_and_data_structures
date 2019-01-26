#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void    scan_arr(int *arr, int n);
int     peak(int *arr, int l, int r, int n);

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
        if (strcmp(command, "PEAK") == 0)
        {
            int left, right;
            scanf("%d %d", &left, &right);
            printf("%d\n", peak(arr, left, right, n));
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

int     peak(int *arr, int l, int r, int n)
{
    int count = 0;
    if (n == 1)
        return (1);
    for (int i = l; i <= r; i++)
    {
        if (i && i != n - 1 && arr[i - 1] <= arr[i] && arr[i + 1] <= arr[i])
            count++;
        else if (!i && arr[i + 1] <= arr[i])
            count++;
        else if (i == n - 1 && arr[i - 1] <= arr[i])
            count++;
    }
    return (count);
}
