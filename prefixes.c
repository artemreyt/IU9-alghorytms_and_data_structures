#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void    print_prefixes(char *str, int index, int len, int *arr);

int     main(int argc, char **argv)
{
    char *str = argv[1];
    int i = 0;
    int len = (int)strlen(str);
    int *lens_arr = (int *) calloc(len, sizeof(int));
    while (i < len / 2)
    {
        print_prefixes(str, i, len, lens_arr);
        i++;
    }
    free (lens_arr);
    return (0);
}

void    print_prefixes(char *str, int index, int len, int *arr)
{
    for (int k = 2; k <= len / (index + 1); k++)
    {
        if (strncmp(str, str + (index + 1) * (k - 1), index + 1) == 0 && arr[(index + 1) * k - 1] == 0)
        {
            printf("%d %d\n", (index + 1) * k, k);
            arr[(index + 1) * k - 1]++;
        }
        else
            break;
    }
}
