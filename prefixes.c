#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void    print_prefixes(char *str, int index, int len);

int     main(int argc, char **argv)
{
    char *str = argv[1];
    int i = 0;
    int len = (int)strlen(str);
    while (i < (len + 1) / 2 - 1)
    {
        print_prefixes(str, i, len);
        i++;
    }
    return (0);
}

void    print_prefixes(char *str, int index, int len)
{
    for (int k = 2; k <= len / (index + 1); k++)
    {
        if (strncmp(str, str + (index + 1) * (k - 1), index + 1) == 0)
            printf("%d %d\n", (index + 1) * k, k);
        else
            break;
    }
}
