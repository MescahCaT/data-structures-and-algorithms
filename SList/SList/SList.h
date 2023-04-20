#pragma once

//����
//ͷ�� �� β�� �� ͷɾ �� βɾ �� ���� �� ���� �� ��ӡ �� ָ��λ�ò���(ǰ�壬���) ��ָ��λ��ɾ��
//SLpushfront , SLpushback , SLpopfront , SLpopback , SLdestory , SLsearch , SLprint , SLInsert , SLearse

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int SLDatatype;

typedef struct SListNode
{
	SLDatatype data;				// ָ�����ݴ�ŵĵ�ַ
	struct SListNode* next;		//ָ��������һ���ڵ�
}SLNode,*PSL,**PPSL;

// β��
void SLpushback(PSL* pplist, SLDatatype x);

// �����ӡ
void SLprint(PSL plist);

// ͷ��
void SLpushfront(PSL* pplist, SLDatatype x);

//βɾ
void SLpopback(PSL* pplist);

//����
void SLrestroy(PSL* pplist);

// ����
int SLsearch(PSL plist, SLDatatype x);

// ����
void SLinsertAfter(PSL* plist, size_t pos, SLDatatype x);
void SLinsertBefore(PPSL, size_t, SLDatatype);

//ɾ��
void SLerase(PPSL, size_t);