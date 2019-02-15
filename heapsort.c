#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void 	scan_arr(char **arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		char *str = (char *) calloc(100, sizeof(char));
		str = fgets(str, 100, stdin);
		arr[i] = (char *) calloc(strlen(str) + 1, sizeof(char));
		strncpy(arr[i], str, strlen(str));
		free(str);
	}
}

void 	free_arr(char **arr, int n)
	for (int i = 0; i < n; i++)
		free(arr[i]);
	free(arr);
}

void print_arr(char **arr, int n)
{
	for (int i = 0; i < n; i++)
		fputs(arr[i], stdout);
}

int 	count_a(const char *str)
{
	int count = 0;
	while (*str)
	{
		if (*str == 'a')
			count++;
		str++;
	}
	return (count);
}

int 	more_a(const void *str1, const void *str2)
{
	return (count_a(*(char **)str1) > count_a(*(char **)str2));
}

void 	swap(void *a, void *b, size_t width)
{
	void *buf = malloc(width);
	memcpy(buf, a, width);
	memcpy(a, b, width);
	memcpy(b, buf, width);
	free(buf);
}

void 	siftDown(void *base, size_t nel, size_t width, int (*compare)(const void *a, const void *b), int k)
{
	int child;
	while (k <= (int)nel / 2 - 1)
	{
		child = 2*k + 1;
		if (child < (int)nel - 1 && compare((char *)base + (child + 1) * width, (char *)base + child *width))
			child++;
		if (compare((char *)base + child * width, (char *)base + k * width))
			swap((char *)base + child * width, (char *)base + k * width , width);
		else
			break;
		k = child;
	}
}

void 	hsort(void *base, size_t nel, size_t width, int (*compare)(const void *a, const void *b))
{
	for(int i = nel / 2 - 1; i >= 0; i--)
		siftDown(base, nel, width, more_a, i);
	for(int i = nel - 1; i > 0; i--)
	{	
		swap((char *)base, (char *)base + i * width, width);
		siftDown(base, i, width, more_a, 0);
	}
}

int 	main()
{
	int n;

	scanf("%d", &n);
	getchar();
	char **arr = (char**) malloc(n * sizeof(char*));
	scan_arr(arr, n);
	hsort(arr, n, sizeof(char*), more_a);
	print_arr(arr, n);
	free_arr(arr, n);
	return(0);
}
