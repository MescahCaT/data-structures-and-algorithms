#define _CRT_SECURE_NO_WARNINGS 1
#include"Heap.h"

void Heaptest1()
{
	HP hp;
	HeapInit(&hp);
	HPDataType arr[] = { 12,27,36,1,55,10,65,13,48,19,80,99,16,21 };
	for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
	{
		HeapPush(&hp, arr[i]);
	}

	HeapPop(&hp);
	HeapPop(&hp);
	HeapPop(&hp);

	HeapPush(&hp, 100);
	HeapPush(&hp, 93);
	HeapPush(&hp, 56);

}

void Heaptest2()
{
	HP hp;
	HeapInit(&hp);
	HPDataType arr[] = { 12,27,36,1,55,10,65,13,48,19,80,99,16,21,1000,648,252,13 };
	for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
	{
		HeapPush(&hp, arr[i]);
	}

	int i = 0;
	while (!HeapEmpty(&hp))
	{
		printf("%d ", HeapTop(&hp));
		HeapPop(&hp);
	}
}

int main()
{
	Heaptest2();

	return 0;
}