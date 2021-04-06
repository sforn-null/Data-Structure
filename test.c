#include "SeqList.h"

void test1()
{
	SeqList s1 = { 0 };
	SeqListInit(&s1);
	SeqListPushBack(&s1, 1);
	SeqListPushBack(&s1, 2);
	SeqListPushBack(&s1, 3);
	SeqListPushBack(&s1, 4);
	SeqListPushBack(&s1, 5);
	SeqListPrint(&s1);
	//看一下是否扩容了

	SeqListPopBack(&s1);
	SeqListPrint(&s1);

	SeqListPushFront(&s1, 0);
	SeqListPrint(&s1);

	SeqListPopFront(&s1);
	SeqListPrint(&s1);
}

int main()
{
	test1();
	return 0;
}