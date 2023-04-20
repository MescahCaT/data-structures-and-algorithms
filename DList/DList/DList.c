#define _CRT_SECURE_NO_WARNINGS 1
#include"DList.h"



// �����ʼ�� - ����һ���ڱ�λͷ���
void DLInit(PPDL pplist)
{
	// �����ڱ�λ
	PDL cur = (PDL)malloc(sizeof(DL));
	if (cur == NULL)
	{
		perror("mallod");
		exit(-1);
	}
	*pplist = cur;
	(*pplist)->next = *pplist;
	(*pplist)->prev = *pplist;

}


// �����½��
PDL BuyNewNode()
{
	PDL newnode = (PDL)malloc(sizeof(DL));
	if (newnode == NULL)
	{
		perror("malloc");
		exit(-1);
	}
	newnode->next = newnode;
	newnode->prev = newnode;
	return newnode;
}

// β��
void DLpushback(PDL pheard,DLDataType x)
{

	PDL newnode = BuyNewNode();
	newnode->data = x;

	newnode->prev = pheard->prev;
	newnode->next = pheard;
	pheard->prev->next = newnode;
	pheard->prev = newnode;
}

// ��ӡ
void DLprint(PDL plist)
{

	printf("pheard->");
	PDL cur = plist->next;
	while (cur->next != plist)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("pheard...\n");
}

// ͷ��
void DLpushfront(PDL plist, DLDataType x)
{

	PDL newnode = BuyNewNode();
	newnode->data = x;

	newnode->next = plist->next;
	newnode->prev = plist;
	plist->next->prev = newnode;
	plist->next = newnode;

}


// ��������
void DListdestory(PDL plist, PDL p)
{
	PDL cur = plist;
	if (cur->next != p)
	{
		DListdestory(cur->next,p);
	}
	else
	{
		cur->prev->next = p;
		p->prev = cur->prev;
		free(cur);
	}
}


// ͷɾ
void DLpopfront(PDL plist)
{
	assert(plist->next != plist);

	PDL tail = plist->next->next;
	free(plist->next);
	plist->next = tail;
	tail->prev = plist;

}


// βɾ
void DLpopback(PDL plist)
{
	assert(plist->next != plist);

	PDL tail = plist->prev->prev;
	free(tail->next);
	plist->prev = tail;
	tail->next = plist;

}