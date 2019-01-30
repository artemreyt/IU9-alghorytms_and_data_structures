#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void    scan_arr(int*, int);
int     gcd2(int a, int b);
int     gcd(int *arr, int l, int r);

int main()
{
    int n, m;
    scanf("%d", &n);
    int *arr = (int *) malloc(n * sizeof(int));
    scan_arr(arr, n);
    scanf("%d", &m);
    for (int i = 1; i <= m; i++)
    {
        int l, r;
        scanf("%d %d", &l, &r);
        printf("%d\n", gcd(arr, l, r));
    }
    free(arr);
    return (0);
}

void    scan_arr(int *arr, int n)
{
    for (int i = 0; i < n; i++)
        scanf("%d", arr + i);
}

int     gcd2(int a, int b)
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

int     gcd(int *arr, int l, int r)
{
    int result = abs(arr[l]);
    for (int i = l; i < r; i++)
        result = gcd2(result, abs(arr[i + 1]));
    return (result);
}
