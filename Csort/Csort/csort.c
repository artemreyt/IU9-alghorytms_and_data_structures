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

int main() {
    getchar();
    char *str = scan_str();
    
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
