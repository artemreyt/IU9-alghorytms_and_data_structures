#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void    scan_arr(int*, int, FILE *);
int     gcd2(int a, int b);
int     gcd(int *arr, int l, int r);
int     abs(int a);


int main()
{
    //srand(time(0));
    int n, m;
     FILE *fp = fopen("posl.txt", "r");
    fscanf(fp, "%d", &n);
    printf("%d\n", n);
    int *arr = (int *) malloc(n * sizeof(int));
    scan_arr(arr, n, fp);
    fscanf(fp, "%d", &m);
    printf("m = %d\n",m);
    int l, r;
    for (int i = 1; i <= m; i++)
    {
        printf("i = %d: ", i);
        //fscanf(fp, "%d %d", &l, &r);
        //printf("%d\n", gcd(arr, l, r));
    }
    fclose(fp);
    free(arr);
    return (0);
}

void    scan_arr(int *arr, int n, FILE *fp)
{
    for (int i = 0; i < n; i++)
        fscanf(fp, "%d", arr + i);
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

int     abs(int a)
{
    return (a < 0) ?  -a : a;
}

int     gcd(int *arr, int l, int r)
{
    int result = abs(arr[l]);
        for (int i = l; i < r && result > 1; i++)
        {
            result = gcd2(result, abs(arr[i + 1]));
        }
    return (result);
}
