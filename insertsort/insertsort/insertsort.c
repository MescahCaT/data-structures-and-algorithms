#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

void InsertSort(int* ptr, size_t sz)
{
	for (size_t i = 0; i < sz - 1; i++)
	{
		int end = (int)i;
		int tmp = *(ptr + end + 1);
		while (end >= 0)
		{
 			if (*(ptr + end ) > tmp)
			{
				*(ptr + end + 1) = *(ptr + end);
				--end;
			}
			else
			{
				break;
			}
		}
		*(ptr + end + 1) = tmp;
	}
}





int main()
{
	int array[] = { 13,15,6,21,2,45,26,22 };
	size_t sz = sizeof(array) / sizeof(int);
	InsertSort(array, sz);

	for (size_t i = 0; i < sz; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");

	return 0;
}