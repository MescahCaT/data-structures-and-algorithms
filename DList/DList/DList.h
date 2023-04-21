#pragma once

// ˫���ͷѭ������ - Double List 
// �����ӡ DListprint / �������� DListdestory / ͷ�� DLpushfront / ͷɾ DLpopfront / β�� DLpushback / βɾDLpopback
// ������ DLInsearch / ָ��Posλ���� DLInsert / ָ��ɾ����� DLearse / �����ʼ��

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int DLDataType;

typedef struct DListNode
{
	DLDataType data;
	struct DListNode* prev;
	struct DListNode* next;
}DL , *PDL,**PPDL;

// �����ʼ�� - ����һ���ڱ�λͷ���
void DLInit(PPDL pheard);

// β��
void DLpushback(PDL pheard, DLDataType x);

// �����ӡ
void DLprint(PDL plist);

// ͷ��
void DLpushfront(PDL plist, DLDataType x);

// ��������
void DListdestory(PDL plist,PDL p);

// ͷɾ
void DLpopfront(PDL plist);

// βɾ
void DLpopback(PDL plist);

// ������ -- Ѱ���޹��򷵻�-1
int DListSearch(PDL plist, DLDataType x);

// ָ��posλ����
void DLInsert(PDL plist, DLDataType x,size_t pos);

// ָ��posλɾ��
void DLerase(PDL plist, size_t pos);