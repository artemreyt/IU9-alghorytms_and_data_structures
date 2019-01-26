#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE 1000001

int     is_hyperdrom(char *str, int l, int r);
void    update(char *str, const char *s, int index);

int     main()
{
    int m;
    char *str = (char *) calloc(BUF_SIZE, 1);
    scanf("%s %d", str, &m);
    for (int i = 1; i <= m; i++)
    {
        char command[4];
        scanf("%s", command);
        if (strcmp(command, "HD") == 0)
        {
            int l,r;
            scanf("%d %d", &l, &r);
            printf("%s\n", is_hyperdrom(str, l, r) == 1 ? "YES" : "NO");
        }
        else
        {
            int index;
            char s[100];
            scanf("%d %s", &index, s);
            update(str, s, index);
        }
    }
    return (0);
}

int     is_hyperdrom(char *str, int l, int r)
{
    int count[26] = {0};
    for (int i = l; i <= r; i++)
        count[str[i] - 'a']++;
    int mod = (r - l + 1) % 2;
    int k = 0;
    for (int i = 0; i < 26; i++)
        if (count[i] % 2 != 0)
            k++;
    return (mod == 1) ? (k == 1 ? 1 : 0) : (k == 0 ? 1 : 0);
}

void    update(char *str, const char *s, int index)
{
    while (*s)
    {
        str[index] = *s;
        index++;
        s++;
    }
}
