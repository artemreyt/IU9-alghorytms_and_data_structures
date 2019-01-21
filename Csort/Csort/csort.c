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

int main() {
    getchar();
    char *str = scan_str();
    printf("%d word(s)\n", how_many_words(str));
    puts(str);
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
