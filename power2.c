#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void 	scan_arr(int *arr, int n);
int 	power2(int *arr, int n);
int 	sum(int bit_scale, int *arr, int n);
int 	pow2(int power);

int 	main()
{

	int 	n;

	scanf("%d", &n);

	int *arr = (int *) malloc(n * sizeof(int));
	if (arr != NULL){
		scan_arr(arr, n);
		printf("%d", power2(arr, n));
	}
	free(arr);
	return (0);
}

void	scan_arr(int *arr, int n)
{
	for (int i = 0; i < n; i++)
		scanf("%d", arr + i);
}

/*	Сама функция, считающая количество сочетаний	*/
int 	power2(int *arr, int n)
{
	int count = 0;
	int s;
	int max_scale = pow2(n) - 1;
	for (int bit_scale = 1; bit_scale < max_scale; bit_scale++){
		s = sum(bit_scale, arr, n);
		if ((s & (s - 1)) == 0 && s != 0)
			count++;
	}
	return (count);
}

/*	По битовой шкале находит сумму элементов с индесами i(поднятыми битами)	*/  
int 	sum(int bit_scale, int *arr, int n)
{
	int 	result = 0;
	int 	pow = 1;
	for (int i = 0; i < n; i++)
	{
		if (bit_scale & pow)
			result += arr[i];
		pow *= 2;
	}
	return (result);
}

int 	pow2(int power)
{
	if (power == 0)
		return (1);

	int result = 2;

	for (int i = 1; i < power; i++)
		result *= 2;
	return (result);
}