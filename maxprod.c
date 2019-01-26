#include <stdio.h>
#include <stdlib.h>

typedef struct Rational
{
    int numerator;
    int denominator;
}  rational_t;

void        scan_arr(rational_t *, int);
rational_t  multiplication(rational_t l, rational_t r);
int         more(rational_t l, rational_t r);
void        get_l_r(rational_t *arr_prod, int *l, int *r, int n);


int     main()
{
    int n;
    scanf("%d", &n);
    rational_t *arr = (rational_t *) malloc(n * sizeof(rational_t));
    scan_arr(arr, n);
    int n_of_prods = n * (n + 1) / 2;
    rational_t *arr_prod = (rational_t *) malloc(n_of_prods * sizeof(rational_t));
    int i_prods = 0;
    for (int i = 0; i < n; i++)
    {
        rational_t   mult = {1, 1};
        for (int j = i; j < n; j++)
        {
            mult = multiplication(mult, arr[j]);
            arr_prod[i_prods++] = mult;
        }
    }
    int l, r;
    get_l_r(arr_prod, &l, &r, n);
    printf("%d %d\n", l, r);
    free(arr_prod);
    free(arr);
}

int         more(rational_t l, rational_t r)
{
    return (l.numerator * r.denominator > r.numerator * l.denominator);
}

void         get_l_r(rational_t *arr_prod, int *l, int *r, int n)
{
    int i_prods = 0;
    rational_t max = arr_prod[0];
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (more(arr_prod[i_prods], max))
            {
                *l = i;
                *r = j;
                max = arr_prod[i_prods];
            }
            i_prods++;
        }
    }
}

rational_t  multiplication(rational_t l, rational_t r)
{
    rational_t result;
    result.numerator = l.numerator * r.numerator;
    result.denominator = l.denominator * r.denominator;
    return (result);
}

void    scan_arr(rational_t *arr, int size)
{
    for (int i = 0; i < size; i++)
        scanf("%d/%d", &arr[i].numerator, &arr[i].denominator);
}
