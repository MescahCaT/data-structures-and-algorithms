#pragma once
// С��(�Ѷ���С)
// �Ѵ�ӡ / �ѳ�ʼ�� / ������ / �Ѳ��� / ��ɾ�� / ��ȡ�� / ���п� / ������

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

typedef int HPDataType;

typedef struct Heap
{
	HPDataType* a;
	size_t size;
	size_t capacity;
}HP;




//void Swap(HPDataType* p1, HPDataType* p2);
//// O(logN)
//void AdjustDwon(HPDataType* a, int size, int parent);
//void AdjustUp(HPDataType* a, int child);

void HeapPrint(HP* php);
void HeapInit(HP* php);
void HeapDestroy(HP* php);
void HeapPush(HP* php, HPDataType x);
void HeapPop(HP* php);
HPDataType HeapTop(HP* php);
bool HeapEmpty(HP* php);
int HeapSize(HP* php);