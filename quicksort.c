#include <stdio.h>
#include <stdlib.h>

void    print_arr(const int *arr, int n);
void    scan_arr(int *arr, int n);
void    quick_sort(int *arr, int n, int m);
void    swap(int *a, int *b);
void    selection_sort(int *arr, int n);


int main(){
    int n, m;
    scanf("%d", &n);
    scanf("%d", &m);
    int *arr = (int *) malloc(n * sizeof(int));
    scan_arr(arr, n);
    quick_sort(arr, n, m);
    print_arr(arr, n);
    free(arr);
    return 0;
}

void    print_arr(const int *arr, int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
}

void    scan_arr(int *arr, int n)
{
    for (int i = 0; i < n; i++)
        scanf("%d", arr + i);
}

void    quick_sort(int *arr, int n, int m)
{
    if (n < m)
        selection_sort(arr, n);
    else
    {
        int left = 0, right = n - 1, pivot = *(arr + n / 2);
        while (left <= right)
        {
            while (arr[left] < pivot) left++;
            while (arr[right] > pivot) right--;
            if (left <= right){
                swap(arr + left, arr + right);
                left++;
                right--;
            }
        }
        quick_sort(arr, right + 1, m);
        quick_sort(arr + left, n - left, m);
    }
}

void    selection_sort(int *arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = arr[i];
        int i_min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < min){
                min = arr[j];
                i_min = j;
            }
        }
        arr[i_min] = arr[i];
        arr[i] = min;
    }
}

void    swap(int *a, int *b)
{
    int buf = *a;
    *a = *b;
    *b = buf;
}
