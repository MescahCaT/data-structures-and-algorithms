#pragma once

// 双向带头循环链表 - Double List 
// 链表打印 DListprint / 链表销毁 DListdestory / 头插 DLpushfront / 头删 DLpopfront / 尾插 DLpushback / 尾删DLpopback
// 结点查找 DLInsearch / 指定Pos位插入 DLInsert / 指定删除结点 DLearse / 链表初始化

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

// 链表初始化 - 包含一个哨兵位头结点
void DLInit(PPDL pheard);

// 尾插
void DLpushback(PDL pheard, DLDataType x);

// 链表打印
void DLprint(PDL plist);

// 头插
void DLpushfront(PDL plist, DLDataType x);

// 链表销毁
void DListdestory(PDL plist,PDL p);

// 头删
void DLpopfront(PDL plist);

// 尾删
void DLpopback(PDL plist);

// 结点查找 -- 寻找无果则返回-1
int DListSearch(PDL plist, DLDataType x);

// 指定pos位插入
void DLInsert(PDL plist, DLDataType x,size_t pos);

// 指定pos位删除
void DLerase(PDL plist, size_t pos);