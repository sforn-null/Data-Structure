#ifndef __SLIST_H__
#define __SLIST_H__

#include<stdio.h>

typedef int SLTDataType;
struct SListNode  //����Ľڵ�
{
	SLTDataType _data;
	struct SListNode* _next;
};

typedef struct SListNode SListNode;

SListNode* SListPushBack(SListNode* head, SLTDataType x);
//β��

SListNode* SListPopBack(SListNode* head);
//βɾ

SListNode* SListPushFront(SListNode* head, SLTDataType x);
//ͷ��

SListNode* SListPopFront(SListNode* head);
//ͷɾ

void SListPrint(SListNode* head);
//��ӡ����

#endif // !__SLIST_H__
