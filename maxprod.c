#include <stdio.h>
#include <stdlib.h>

void        scan_arr(long double *, int);
int         all_are_greater_1(long double *arr, int n);


int     main()
{
    int n;
    scanf("%d", &n);
    long double *arr = (long double *) malloc(n * sizeof(long double));
    scan_arr(arr, n);
    if (all_are_greater_1(arr, n))
        printf("%d %d\n", 0, n - 1);
    else
    {
        long double max = arr[0];
        int i_max = 0, j_max = 0;
        for (int i = 0; i < n; i++)
        {
            long double mult = 1.0;
            for (int j = i; j < n; j++)
            {
                mult *= arr[j];
                if (mult > max)
                {
                    max = mult;
                    i_max = i;
                    j_max = j;
                }
            }
        }
        printf("%d %d", i_max, j_max);
    }
    free(arr);
    return (0);
}

void         get_l_r(long double *arr_prod, int *l, int *r, int n)
{
    int i_prods = 0;
    *l = 0;
    *r = 0;
    long double max = arr_prod[0];
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (arr_prod[i_prods] > max)
            {
                *l = i;
                *r = j;
                max = arr_prod[i_prods];
            }
            i_prods++;
        }
    }
}

int     all_are_greater_1(long double *arr, int n)
{
    for (int i = 0; i < n; i++)
        if (arr[i] < 1.0)
            return (0);
    return (1);
}

void    scan_arr(long double *arr, int size)
{
    int a, b;
    for (int i = 0; i < size; i++)
    {
        scanf("%d/%d", &a, &b);
        arr[i] = (long double)a / b;
    }
}
