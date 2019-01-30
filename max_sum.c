#include <stdio.h>
#include <stdlib.h>

int     max_sum(int *arr, int n, int *ptr_l, int *ptr_r);

int main()
{
    int n;
    scanf("%d", &n);
    int *arr = (int *) malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) scanf("%d", arr + i);
    int l, r;
    printf("%d\n", max_sum(arr, n, &l, &r));
    printf("l = %d, r = %d\n", l, r);
    
    return (0);
}


int     max_sum(int *arr, int n, int *ptr_l, int *ptr_r)
{
    int sum = 0, min_sum = 0;
    int max_sum = arr[0];
    int min_pos = -1;
    *ptr_l = 0;
    *ptr_r = 0;
    for (int r = 0; r < n; r++)
    {
        sum += arr[r];
        if (max_sum < sum - min_sum)
        {
            max_sum = sum - min_sum;
            *ptr_l = min_pos + 1;
            *ptr_r = r;
        }
        if (sum < min_sum)
        {
            min_sum = sum;
            min_pos = r;
        }
    }
    return (max_sum);
}
