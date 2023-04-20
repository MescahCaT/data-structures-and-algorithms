#define _CRT_SECURE_NO_WARNINGS 1
#include"SList.h"

SLNode* BuyNewNode()
{
	PSL newnode = (PSL)malloc(sizeof(SLNode));
	if (newnode == NULL)
	{
		perror("malloc");
	}
	newnode->next = NULL;
	return newnode;
}

//尾插
void SLpushback(PSL* pplist, SLDatatype x)
{
	//创建新节点
	PSL newnode = BuyNewNode();
	newnode->data = x;

	//链表没有内容
	if (*pplist == NULL)
	{
		*pplist = newnode;
	}

	//链表已有节点
	else
	{
		PSL cur = *pplist;
		//找到尾节点
		while (cur->next != NULL)
		{
			cur = cur->next;
		}
		//将尾节点的next 置为新节点的地址
		cur->next = newnode;
	}
}

//链表打印
void SLprint(PSL plist)
{
	if (plist == NULL)
		return;
	while (plist->next)
	{
		printf("%d->", plist->data);
		plist = plist->next;
	}
	printf("NULL\n");
}

// 头插
void SLpushfront(PSL* pplist, SLDatatype x)
{
	//创建新节点
	PSL newnode = BuyNewNode();
	newnode->data = x;

	//链表中没有节点
	if (*pplist == NULL)
	{
		*pplist = newnode;
	}

	//链表中有节点
	else
	{
		newnode->next = *pplist;
		*pplist = newnode;
	}

}


// 尾删
void SLpopback(PSL* pplist)
{
	// 判断pplist是否有节点
	assert(*pplist);

	// 只有一个结点
	if ((*pplist)->next == NULL)
	{
		free(*pplist);
		*pplist = NULL;
	}

	// 链表中有多个结点 
	// (*pplist)->next->next ==NULL
	// 找到尾节点
	// 找到尾节点前一个节点
	// 释放尾节点
	// 置空
	else  
	{
		PSL prev = *pplist;
		while (prev->next->next != NULL)
		{
			prev = prev->next;
		}
		free(prev->next);
		prev->next = NULL;
	}
}


//销毁
void SLrestroy(PSL* pplist)
{
	assert(*pplist);

	while (*pplist != NULL)
	{
		PSL cur = *pplist;
		//只有一个结点
		if (cur->next == NULL)
		{
			free(cur);
			*pplist = NULL;
			return;
		}

		//有多个结点
		//找到尾结点
 		while (cur->next->next != NULL)
		{
			cur = cur->next;
		}
		free(cur->next);
		cur->next = NULL;
	}
}

// 查找
int SLsearch(PSL plist, SLDatatype x)
{
	if (plist == NULL)
		return -1;
	int count = 0;
	while (plist->next != NULL)
	{

		if (plist->data == x)
		{
			return count;
		}
		plist = plist->next;
		count++;
	}
	return -1;
}

// 插入 在pos位置后插入
void SLinsertAfter(PPSL plist, size_t pos, SLDatatype x)
{
	//创建新结点
	SLNode* newnode = BuyNewNode();
	newnode->data = x;

	//链表中没有结点
	if (*plist == NULL)
	{
		*plist = newnode;
	}
	//链表中有结点
	else
	{
		//找到pos结点
		PSL cur = *plist;
		size_t count = 0;
		while (count < pos)
		{
			cur = cur->next;
			count++;
		}
		newnode->next = cur->next;
		cur->next = newnode;
	}
}

// 插入 在pos位置前插入
void SLinsertBefore(PPSL plist, size_t pos, SLDatatype x)
{
	//链表为空时，只允许在pos = 0的位置处插入结点
	assert(*plist || pos == 0);

	//创建新结点
	SLNode* newnode = BuyNewNode();
	newnode->data = x;

	//没有结点
	if (*plist == NULL)
	{
		*plist = newnode;
		return;
	}
	PSL cur = *plist;
	//找到pos结点
	size_t count = 0;
	while (count < pos - 1)
	{
		cur = cur->next;
		count++;
		assert(cur);
	}
	newnode->next = cur->next;
	cur->next = newnode;
}

//删除 pos结点
void SLerase(PPSL pplist, size_t pos)
{
	assert(*pplist);
	
	PSL cur = *pplist;
	size_t count = 0;
	while (count < pos - 1)
	{
		cur = cur->next;
		count++;
		assert(cur->next);
	}
	PSL tmp = cur->next->next;
	free(cur->next);
	cur->next = tmp;

}