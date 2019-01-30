#include <stdio.h>
#include <stdlib.h>

void    scan_arr(long double *arr, int size);

int main()
{
    int n;
    scanf("%d", &n);
    long double *arr = (long double *) malloc(n * sizeof(long double));
    scan_arr(arr, n);
    long double *tree = (long double *) malloc(n * sizeof(long double));
    
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
