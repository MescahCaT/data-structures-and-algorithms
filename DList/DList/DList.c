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
	(*pplist)->data = 999;
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

// 结点查找
int DListSearch(PDL plist, DLDataType x)
{
	assert(plist->next);

	int count = 0;
	PDL tail = plist->next;
	while (tail->data != x && tail != plist)
	{
		tail = tail->next;
		count++;
	}
	if (tail == plist)
		return -1;
	return count;
}


// 指定pos位插入
void DLInsert(PDL plist, DLDataType x,size_t pos)
{
	// 链表为空时，只允许在pos = 0的地址插入
	assert(plist->next != plist || pos == 0);

	//	创建新结点
	PDL newnode = BuyNewNode();
	newnode->data = x;

	// 寻找pos位
	size_t count = 0;
	PDL cur = plist->next;
	while (count < pos)
	{
		cur = cur->next;
		count++;
		assert(cur != plist);
	}

	// 插入结点
	newnode->next = cur;
	newnode->prev = cur->prev;
	cur->prev = newnode;
	newnode->prev->next = newnode;
}


// 指定pos位删除
void DLerase(PDL plist, size_t pos)
{
	assert(plist->next != plist);

	// 寻找pos位
	size_t count = 0;
	PDL cur = plist;
	while (count < pos)
	{
		cur = cur->next;
		count++;
		assert(cur != plist);
	}

	PDL tail = cur->next->next;
	free(cur->next);
	cur->next = tail;
	tail->prev = cur;

}