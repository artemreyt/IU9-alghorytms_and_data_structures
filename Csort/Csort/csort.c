//
//  main.c
//  Csort
//
//  Created by Artem Starshov on 22/01/2019.
//  Copyright © 2019 Artem Starshov. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char    *scan_str(void);
int     how_many_words(char *str);
void    csort(char *src, char *dest);
void    make_index_array(int *arr, int words, char *str);
int     len_by_index(int *arr, int n, int index);

int main() {
    getchar();
    char *src = scan_str();
    char *dest = (char *) calloc(strlen(src) + 1, 1);
    csort(src, dest);
    puts(dest);
    return 0;
}

char    *scan_str()
{
    char buf[1000];
    int i = 0;
    char c;
    while ((c = getchar()) != '\n')
    {
        if (c == ' ' && (i == 0 || buf[i - 1] == ' '))
            continue;
        buf[i] = c;
        i++;
    }
    if (buf[i - 1] == ' ')
        i--;
    buf[i] = '\0';
    char *str = (char *) malloc(strlen(buf) + 1);
    strcpy(str, buf);
    return (str);
}

void    csort(char *src, char *dest)
{
    int     words = how_many_words(src);
    int     *indx_arr = (int *) malloc((words + 1) * sizeof(int));
    make_index_array(indx_arr, words, src);
    int     *count = (int *) calloc(words, sizeof(int));
    
    for (int i = 0; i < words; i++)
    {
        int len_i = indx_arr[i + 1] - indx_arr[i] - 1;
        int k = 0;
        for (int j = 0; j < words; j++)
        {
            int len_j = indx_arr[j + 1] - indx_arr[j] - 1;
            if (len_i > len_j)
                k++;
        }
        while (count[k] != 0)
            k++;
        count[k] = indx_arr[i];
    }
    for (int i = 0; i < words; i++)
    {
        strncat(dest, src + count[i], indx_arr[count[i] + 1] - indx_arr[count[i]] - 1);
        strcat(dest, " ");
    }
}

int     len_by_index(int *arr, int n, int index)
{
    return (arr[index + 1] + arr[index] - 1);
}

void    make_index_array(int *arr, int words, char *str)
{
    int i_arr = 0;
    int i_str = 0;
    int in_word = 0;
    while (i_arr <= words)
    {
        if (in_word == 0 && str[i_str] != ' ')
        {
            arr[i_arr] = i_str;
            i_arr++;
            in_word = 1;
        }
        else if (in_word == 1 && str[i_str] == ' ')
            in_word = 0;
        i_str++;
    }
    arr[words + 1] = (int)strlen(str) + 2;
}

int     how_many_words(char *str)
{
    int spaces = 0;
    int i = 0;
    while(str[i])
    {
        if (str[i] == ' ')
            spaces++;
        i++;
    }
    if (i == 0)
        return (0);
    return (spaces + 1);
}
