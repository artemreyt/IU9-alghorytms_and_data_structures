#include <stdio.h>
#include <stdlib.h>

union Int32
{
    int x;
    unsigned char bytes[4];
};

union Int32     *count_sort(union Int32 *arr, int n, int byte);
union Int32     *radix_sort(union Int32 *arr, int n);

int     main()
{
    int n;
    scanf("%d", &n);
    union Int32 *arr = (union Int32 *) malloc(n * sizeof(union Int32));
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i].x);
    arr = radix_sort(arr, n);
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i].x);
    free(arr);
    return (0);
}

union Int32     *radix_sort(union Int32 *arr, int n)
{
    int byte = 0;
    while (byte < 4)
        arr = count_sort(arr, n, byte++);
    return (arr);
}

union Int32     *count_sort(union Int32 *arr, int n, int byte)
{
    int count[256] = {0};
    union Int32 *dest = (union Int32 *) malloc(n * sizeof(union Int32));
    for (int i = 0; i < n; i++)
    {
        if (byte != 3)
            count[arr[i].bytes[byte]]++;
        else
            count[arr[i].bytes[byte] ^ 128]++;
    }
    
    for (int i = 255; i >= 0; i--)
    {
        count[i] = 0;
        for (int j = 0; j < i; j++)
            count[i] += count[j];
    }
    
    for (int i = 0; i < n; i++)
    {
        int j;
        if (byte < 3)
            j = count[arr[i].bytes[byte]]++;
        else
            j =count[arr[i].bytes[byte] ^ 128]++;
        dest[j] = arr[i];
    }
    free(arr);
    return (dest);
}
