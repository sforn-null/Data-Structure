#ifndef __SLIST_H__
#define __SLIST_H__

#include<stdio.h>

typedef int SLTDataType;
struct SListNode  //链表的节点
{
	SLTDataType _data;
	struct SListNode* _next;
};

typedef struct SListNode SListNode;

SListNode* SListPushBack(SListNode* head, SLTDataType x);
//尾插

SListNode* SListPopBack(SListNode* head);
//尾删

SListNode* SListPushFront(SListNode* head, SLTDataType x);
//头插

SListNode* SListPopFront(SListNode* head);
//头删

void SListPrint(SListNode* head);
//打印链表

#endif // !__SLIST_H__
