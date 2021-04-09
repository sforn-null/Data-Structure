#include<stdio.h>
#include "SList.h"
//µ¥Á´±í

SListNode* SListPushBack(SListNode* head, SLTDataType x)
{
	SListNode* newnode = (SListNode*)malloc(sizeof(SListNode));
	newnode->_data = x;
	newnode->_next = NULL;
	if (head == NULL)
	{
		head = newnode;
		return head;
	}
	else
	{
		SListNode* tail = head;
		while (tail->_next != NULL)
		{
			tail = tail->_next;
		}
		tail->_next = newnode;
		return head;
	}
	
}

void SListPrint(SListNode* head)
{
	SListNode* cur = head;
	while (cur != NULL)
	{
		printf("%d->", cur->_data);
		cur = cur->_next;
	}
	printf("NULL\n");
}
