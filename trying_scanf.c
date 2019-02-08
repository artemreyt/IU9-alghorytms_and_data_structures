#include <stdio.h>
#include <string.h>


int main()
{
    char str[100];
    char c;
    while ((c = getchar()) != '\n')
    {
        if (c != ' ')
        {
            ungetc(c, stdin);
            scanf("%s", str);
            puts(str);
        }
    }
    return (0);
}
