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

//β��
void SLpushback(PSL* pplist, SLDatatype x)
{
	//�����½ڵ�
	PSL newnode = BuyNewNode();
	newnode->data = x;

	//����û������
	if (*pplist == NULL)
	{
		*pplist = newnode;
	}

	//�������нڵ�
	else
	{
		PSL cur = *pplist;
		//�ҵ�β�ڵ�
		while (cur->next != NULL)
		{
			cur = cur->next;
		}
		//��β�ڵ��next ��Ϊ�½ڵ�ĵ�ַ
		cur->next = newnode;
	}
}

//�����ӡ
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

// ͷ��
void SLpushfront(PSL* pplist, SLDatatype x)
{
	//�����½ڵ�
	PSL newnode = BuyNewNode();
	newnode->data = x;

	//������û�нڵ�
	if (*pplist == NULL)
	{
		*pplist = newnode;
	}

	//�������нڵ�
	else
	{
		newnode->next = *pplist;
		*pplist = newnode;
	}

}


// βɾ
void SLpopback(PSL* pplist)
{
	// �ж�pplist�Ƿ��нڵ�
	assert(*pplist);

	// ֻ��һ�����
	if ((*pplist)->next == NULL)
	{
		free(*pplist);
		*pplist = NULL;
	}

	// �������ж����� 
	// (*pplist)->next->next ==NULL
	// �ҵ�β�ڵ�
	// �ҵ�β�ڵ�ǰһ���ڵ�
	// �ͷ�β�ڵ�
	// �ÿ�
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


//����
void SLrestroy(PSL* pplist)
{
	assert(*pplist);

	while (*pplist != NULL)
	{
		PSL cur = *pplist;
		//ֻ��һ�����
		if (cur->next == NULL)
		{
			free(cur);
			*pplist = NULL;
			return;
		}

		//�ж�����
		//�ҵ�β���
 		while (cur->next->next != NULL)
		{
			cur = cur->next;
		}
		free(cur->next);
		cur->next = NULL;
	}
}

// ����
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

// ���� ��posλ�ú����
void SLinsertAfter(PPSL plist, size_t pos, SLDatatype x)
{
	//�����½��
	SLNode* newnode = BuyNewNode();
	newnode->data = x;

	//������û�н��
	if (*plist == NULL)
	{
		*plist = newnode;
	}
	//�������н��
	else
	{
		//�ҵ�pos���
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

// ���� ��posλ��ǰ����
void SLinsertBefore(PPSL plist, size_t pos, SLDatatype x)
{
	//����Ϊ��ʱ��ֻ������pos = 0��λ�ô�������
	assert(*plist || pos == 0);

	//�����½��
	SLNode* newnode = BuyNewNode();
	newnode->data = x;

	//û�н��
	if (*plist == NULL)
	{
		*plist = newnode;
		return;
	}
	PSL cur = *plist;
	//�ҵ�pos���
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

//ɾ�� pos���
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