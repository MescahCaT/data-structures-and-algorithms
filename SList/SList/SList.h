#pragma once

//链表
//头插 ， 尾插 ， 头删 ， 尾删 ， 销毁 ， 查找 ， 打印 ， 指定位置插入(前插，后插) ，指定位置删除
//SLpushfront , SLpushback , SLpopfront , SLpopback , SLdestory , SLsearch , SLprint , SLInsert , SLearse

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int SLDatatype;

typedef struct SListNode
{
	SLDatatype data;				// 指向数据存放的地址
	struct SListNode* next;		//指向链表下一个节点
}SLNode,*PSL,**PPSL;

// 尾插
void SLpushback(PSL* pplist, SLDatatype x);

// 链表打印
void SLprint(PSL plist);

// 头插
void SLpushfront(PSL* pplist, SLDatatype x);

//尾删
void SLpopback(PSL* pplist);

//销毁
void SLrestroy(PSL* pplist);

// 查找
int SLsearch(PSL plist, SLDatatype x);

// 插入
void SLinsertAfter(PSL* plist, size_t pos, SLDatatype x);
void SLinsertBefore(PPSL, size_t, SLDatatype);

//删除
void SLerase(PPSL, size_t);