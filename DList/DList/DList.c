#define _CRT_SECURE_NO_WARNINGS 1
#include"DList.h"



// 链表初始化 - 包含一个哨兵位头结点
void DLInit(PPDL pplist)
{
	// 创建哨兵位
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


// 创建新结点
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

// 尾插
void DLpushback(PDL pheard,DLDataType x)
{

	PDL newnode = BuyNewNode();
	newnode->data = x;

	newnode->prev = pheard->prev;
	newnode->next = pheard;
	pheard->prev->next = newnode;
	pheard->prev = newnode;
}

// 打印
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

// 头插
void DLpushfront(PDL plist, DLDataType x)
{

	PDL newnode = BuyNewNode();
	newnode->data = x;

	newnode->next = plist->next;
	newnode->prev = plist;
	plist->next->prev = newnode;
	plist->next = newnode;

}


// 链表销毁
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


// 头删
void DLpopfront(PDL plist)
{
	assert(plist->next != plist);

	PDL tail = plist->next->next;
	free(plist->next);
	plist->next = tail;
	tail->prev = plist;

}


// 尾删
void DLpopback(PDL plist)
{
	assert(plist->next != plist);

	PDL tail = plist->prev->prev;
	free(tail->next);
	plist->prev = tail;
	tail->next = plist;

}