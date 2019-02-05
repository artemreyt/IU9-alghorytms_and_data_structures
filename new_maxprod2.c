#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void    scan_arr(FILE *fp, double *arr, int n);
void    get_left_right(double *arr, int n, int *ptr_l, int *ptr_r);

int     main()
{
    int n, left, right;
    FILE *fp = fopen("50.txt", "r");
    fscanf(fp, "%d", &n);
    double *arr = (double *) malloc(n * sizeof(double));
    scan_arr(fp, arr, n);
    get_left_right(arr, n, &left, &right);
    printf("%d %d\n", left, right);
    fclose(fp);
    free(arr);
    return (0);
}

void    scan_arr(FILE *fp, double *arr, int n)
{
    double a, b;
    for (int i = 0; i < n; i++)
    {
        fscanf(fp, "%lf/%lf", &a, &b);
        arr[i] = log2(a / b);
    }
}

void    get_left_right(double *arr, int n, int *ptr_l, int *ptr_r)
{
    double  max_sum = arr[0],
    sum = 0.0;
    int     start = 0;
    *ptr_l = 0;
    *ptr_r = 0;
    for (int r = 0; r < n; r++)
    {
        sum += arr[r];
        if (sum > max_sum)
        {
            max_sum = sum;
            *ptr_l = start;
            *ptr_r = r;
        }
        if (sum < 0.0)
        {
            sum = 0.0;
            start = r + 1;
        }
    }
}
