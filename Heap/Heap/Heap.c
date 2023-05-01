#define _CRT_SECURE_NO_WARNINGS 1
#include"Heap.h"

void HeapPrint(HP* php)
{

}



void HeapInit(HP* php)
{
	assert(php);

	php->a = NULL;
	php->capacity = 0;
	php->size = 0;
}


void HeapDestroy(HP* php)
{
	assert(php);

	free(php->a);
	php->capacity = 0;
	php->size = 0;
	php->a = NULL;
}

void Swap(HPDataType* p1, HPDataType* p2)
{
	HPDataType tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

void AdjustUp(HPDataType* a, size_t child)
{
	while (child > 0)
	{
			size_t parent = (child - 1) / 2;
			if (*(a + child) < *(a + parent))
			{
				Swap(a + child, a + parent);
				child = parent;
			}
			else
			{
				break;
			}
	}	
}

void HeapPush(HP* php, HPDataType x)
{
	assert(php);

	// 检查是否有空间存储数据
	if (php->capacity == php->size)
	{
		size_t newcapacity = php->capacity == 0 ? 4 : php->capacity * 2;
		HPDataType* tmp = (HPDataType*)realloc(php->a, newcapacity*sizeof(HPDataType));
		if (tmp == NULL)
		{
			perror("realloc");
			exit(-1);
		}
		php->a = tmp;
		php->capacity = newcapacity;
	}

	php->a[php->size] = x;
	php->size++;

	// 向上调整
	AdjustUp(php->a, php->size - 1);

}


// 向下调整
void AdjuestDown(HPDataType* a, int size, int parent)
{
	while (parent * 2 + size % 2 + 1< size) 
	{
		// 找到小的孩子
		int min_child;
		if (parent * 2 + 2 >= size)
			min_child = parent * 2 + 1;
		else
			min_child = *(a + (parent * 2 + 1)) > *(a + (parent * 2 + 2)) ? (parent * 2 + 2) : (parent * 2 + 1);
		// 
		if (*(a + min_child) < *(a + parent))
		{
			Swap(a + min_child, a + parent);
			parent = min_child;
		}
		else
		{
			break;
		}
	}
}

void HeapPop(HP* php)
{
	assert(php);
	assert(php->size > 0);

	// 交换
	Swap(&(php->a[0]), &(php->a[php->size - 1]));

	// 删除数据
	php->size--;

	// 向下调整
	AdjuestDown(php->a, php->size, 0);

}
 
HPDataType HeapTop(HP* php)
{
	assert(php);
	assert(php->size > 0);

	return php->a[0];
}


bool HeapEmpty(HP* php)
{
	assert(php);
	return php->size == 0;
}


int HeapSize(HP* php)
{
	assert(php);
	return php->size - 1;
}


