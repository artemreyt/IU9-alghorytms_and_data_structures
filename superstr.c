#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE 600

void    scan_arr(char **arr, int n);
void    allocate_memory(char ***arr, int n);
void    free_memory(char **arr, int n);
int     overlap(const char *s1, const char *s2);
char    *superstr(char **arr, int n);

int     main()
{
    int n;
    char **arr;
    scanf("%d", &n);
    allocate_memory(&arr, n);
    scan_arr(arr, n);
    char *super = superstr(arr, n);
    //printf("supestr = %s\n", super);
    printf("%lu\n", strlen(super));
    free_memory(arr, n);
    /*char str1[8], str2[8];
    scanf("%s %s", str1, str2);
    printf("%d\n", overlap(str1, str2));*/
    return (0);
}

void    scan_arr(char **arr, int n)
{
    for (int i = 0; i < n; i++)
        scanf("%s", arr[i]);
}

void    allocate_memory(char ***arr, int n)
{
    *arr = (char **) malloc(n * sizeof(char *));
    for (int i = 0; i < n; i++)
        (*arr)[i] = (char *) calloc(BUF_SIZE + 1, 1);
}

void    free_memory(char **arr, int n)
{
    for (int i = 0; i < n; i++)
        free(arr[i]);
    free(arr);
}

int     sum_len(char **arr, int n)
{
    int len = 0;
    for (int i = 0; i < n; i++)
        len += strlen(arr[i]);
    return (len);
}

char    *superstr(char **arr, int n)
{
    int n_cur = n;
    int *arr_len = (int *) malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        arr_len[i] = strlen(arr[i]);
       // printf("arr_len[%d] = %d ", i, arr_len[i]);
    }
    //printf("\n");
    int pref, post;
    while (n_cur > 1)
    {
        int max_overlap = -1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i != j && arr_len[i] && arr_len[j])
                {
                    int cur_overlap = overlap(arr[i], arr[j]);
                    if (cur_overlap > max_overlap)
                    {
                        pref = j, post = i;
                        max_overlap = cur_overlap;
                    }
                }
            }
        }
        strcat(arr[post], (arr[pref]) + max_overlap);
        arr_len[pref] = 0;
        arr_len[post] = strlen(arr[post]);
        n_cur--;
    }
    /*puts("AFTER DOING:");
    for (int i = 0; i < n; i++)
        printf("arr_len[%d] = %d ", i, arr_len[i]);
    printf("\n");*/
    int i;
    for (i = 0; i < n; i++)
        if (arr_len[i] != 0)
            break;
    free(arr_len);
    return (arr[i]);
}

int     overlap(const char *s1, const char *s2)
{
    int s2_len = strlen(s2);
    int s1_len = strlen(s1);
    int i = s1_len - 1;
    int result = 0;
    while (i >= 0 && s1_len - i <= s2_len)
    {
        int cur_overlap = 0;
        int j = 0;
        int i_cur = i;
        while (s2[j] && s1[i_cur])
        {
            if (s2[j++] == s1[i_cur++])
                cur_overlap++;
            else
            {
                cur_overlap = 0;
                break;
            }
        }
        if (cur_overlap > result)
            result = cur_overlap;
        i--;
    }
    return (result);
}

/*void    merge(char *first, char *second, int overlap)
{
    
}*/
