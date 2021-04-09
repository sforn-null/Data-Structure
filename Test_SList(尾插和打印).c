#include<stdio.h>
#include "SList.h"


void test()
{
	SListNode* head = NULL;
	head = SListPushBack(head, 1);
	head = SListPushBack(head, 2);
	head = SListPushBack(head, 3);
	head = SListPushBack(head, 4);
	SListPrint(head);
}
int main()
{
	test();
	return 0;
}