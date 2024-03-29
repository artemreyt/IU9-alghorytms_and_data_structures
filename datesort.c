#include <stdio.h>
#include <stdlib.h>

typedef  struct Date
{
    int Day, Month, Year;
} date_t;

void    radix_sort(date_t *arr, date_t *dest, int n);
void    scan_arr(date_t *arr, int n);
void    count_sort_by_day(date_t *arr, date_t *dest, int n);
void    count_sort_by_month(date_t *arr, date_t *dest, int n);
void    count_sort_by_year(date_t *arr, date_t *dest, int n);
void    print_arr(date_t *arr, int n);

int main()
{
    int n;
    scanf("%d", &n);
    date_t *arr = (date_t *) malloc(n * sizeof(date_t));
    date_t *dest = (date_t *) malloc(n * sizeof(date_t));
    scan_arr(arr, n);
    radix_sort(arr, dest, n);
    print_arr(dest, n);
    free(arr);
    free(dest);
    return 0;
}

void    scan_arr(date_t *arr, int n)
{
    for (int i = 0; i < n; i++)
        scanf("%d %d %d", &arr[i].Year, &arr[i].Month, &arr[i].Day);
}

void    print_arr(date_t *arr, int n)
{
    for (int i = 0; i < n; i++)
        printf("%d %2d %2d\n", arr[i].Year, arr[i].Month, arr[i].Day);
}

void    radix_sort(date_t *arr, date_t *dest, int n)
{
    count_sort_by_day(arr, dest, n);
    count_sort_by_month(dest, arr, n);
    count_sort_by_year(arr, dest, n);
}

void    count_sort_by_day(date_t *arr, date_t *dest, int n)
{
    int count[31] = {0};
    for (int i = 0; i < n; i++)
        count[arr[i].Day - 1]++;
    for (int i = 30; i >= 0; i--)
    {
        count[i] = 0;
        for (int j = 0; j < i; j++)
            count[i] += count[j];
    }
    for (int i = 0; i < n; i++)
    {
        int j = count[arr[i].Day - 1];
        dest[j] = arr[i];
        count[arr[i].Day - 1]++;
    }
}

void    count_sort_by_month(date_t *arr, date_t *dest, int n)
{
    int count[12] = {0};
    for (int i = 0; i < n; i++)
        count[arr[i].Month - 1]++;
    for (int i = 11; i >= 0; i--)
    {
        count[i] = 0;
        for (int j = 0; j < i; j++)
            count[i] += count[j];
    }
    for (int i = 0; i < n; i++)
    {
        int j = count[arr[i].Month - 1];
        dest[j] = arr[i];
        count[arr[i].Month - 1]++;
    }
}

void    count_sort_by_year(date_t *arr, date_t *dest, int n)
{
    int count[61] = {0};
    for (int i = 0; i < n; i++)
        count[arr[i].Year - 1970]++;
    for (int i = 60; i >= 0; i--)
    {
        count[i] = 0;
        for (int j = 0; j < i; j++)
            count[i] += count[j];
    }
    for (int i = 0; i < n; i++)
    {
        int j = count[arr[i].Year - 1970];
        dest[j] = arr[i];
        count[arr[i].Year - 1970]++;
    }
}
