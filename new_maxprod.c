#include <stdio.h>
#include <stdlib.h>

int     scan_arr(double *arr, int n);
void    get_l_r(double *arr, int n, int *ptr_l, int *ptr_r);

int main()
{
    int n, m, left, right;
    scanf("%d", &n);
    double *arr = (double *) malloc(n * sizeof(double));
    if (scan_arr(arr, n) == n)
        printf("%d %d\n", 0, n - 1);
    else
    {
        get_l_r(arr, n, &left, &right);
        printf("%d %d\n", left, right);
        free(arr);
    }
    return (0);
}

int     scan_arr(double *arr, int n)
{
    int a, b, count = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d/%d", &a, &b);
        arr[i] = (double)a / b;
        if (a >= b)
            count++;
    }
    return (count);
}

void    get_l_r(double *arr, int n, int *ptr_l, int *ptr_r)
{
    double  max_prod = arr[0],
            min_prod = 1.0,
            prod = 1.0;
    int     min_pos = -1;
    *ptr_l = 0;
    *ptr_r = 0;
    for (int r = 0; r < n; r++)
    {
        if (arr[r] == 0)
        {
            min_prod = 1.0;
            prod = 1.0;
            min_pos = r;
        }
        else
        {
            prod *= arr[r];
            double  max_for_r = prod / min_prod;
            if (max_prod < max_for_r)
            {
                max_prod = max_for_r;
                *ptr_l = min_pos + 1;
                *ptr_r = r;
            }
            if (prod < min_prod)
            {
                min_prod = prod;
                min_pos = r;
            }
        }
    }
}
