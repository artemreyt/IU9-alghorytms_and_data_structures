#include <stdio.h>
#include <stdlib.h>

/*typedef struct Rational
{
    int numerator;
    int denominator;
    float value;
}  rational_t;*/

void        scan_arr(long double *, int);
//int         more(rational_t l, rational_t r);
void        get_l_r(long double *arr_prod, int *l, int *r, int n);


int     main()
{
    int n;
    scanf("%d", &n);
    long double *arr = (long double *) malloc(n * sizeof(long double));
    scan_arr(arr, n);
    int n_of_prods = n * (n + 1) / 2;
    long double *arr_prod = (long double *) malloc(n_of_prods * sizeof(long double));
    int i_prods = 0;
    for (int i = 0; i < n; i++)
    {
        long double mult = 1.0;
        for (int j = i; j < n; j++)
        {
            mult *= arr[j];
            arr_prod[i_prods++] = mult;
        }
    }
    int l, r;
    get_l_r(arr_prod, &l, &r, n);
    printf("%d %d", l, r);
    free(arr_prod);
    free(arr);
}

/*int         more(rational_t l, rational_t r)
{
    return (l.numerator * r.denominator > r.numerator * l.denominator);
}*/

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

/*rational_t  multiplication(rational_t l, rational_t r)
{
    rational_t result;
    result.numerator = l.numerator * r.numerator;
    result.denominator = l.denominator * r.denominator;
    return (result);
} */

void    scan_arr(long double *arr, int size)
{
    int a, b;
    for (int i = 0; i < size; i++)
    {
        scanf("%d/%d", &a, &b);
        arr[i] = (long double)a / b;
    }
}
