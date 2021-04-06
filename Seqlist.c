#include "SeqList.h"

void SeqListInit(SeqList*s)
{
	assert(s != NULL);
	s->a = NULL;
	s->size = 0;
	s->capacity = 0;
}


void SeqListCheckCacity(SeqList* s)
{
	if (s->size == s->capacity)
	{
		//if (s->capacity == 0)
		//{
		//	s->capacity = 4;
		//}
		//s->a = realloc(s->a, s->capacity * 2 * sizeof(SLDataType));
		////扩容，第二个参数要传字节数，
		////因此不能传s->capacity * 2 
		size_t newcapacity = s->capacity == 0 ? 4 : s->capacity * 2;
		//如果是0就给newcapacity赋值4
		//如果不是0就将原来的capacity扩大一倍赋值上去
		s->a = realloc(s->a,newcapacity * sizeof(SLDataType));
		s->capacity = newcapacity;
		//第一次的方法没有改变capacity的值
	}
}

void SeqListPushBack(SeqList* s, SLDataType x)
{
	assert(s != NULL);
	SeqListCheckCacity(s);
	s->a[s->size] = x;
	s->size++;
}

void SeqListPopBack(SeqList* s)
{
	assert(s != NULL && s->size > 0);
	s->size--;
	//虽然最后的那个数字还在，但是却无效了
	//size只到它之前的数字了
}

void SeqListPushFront(SeqList* s, SLDataType x)
{
	assert(s != NULL);
	//先看空间是否足够
	SeqListCheckCacity(s);
	//将数据挪走
	int end = s->size - 1;
	for (;end >= 0;end--)
	{
		s->a[end + 1] = s->a[end];
	}
	s->a[0] = x;
	s->size++;
}

void SeqListPopFront(SeqList* s)
{
	assert(s != NULL && s->size > 0);
	size_t i = 0;
	for (i = 0;i < s->size - 1;i++)
	{
		s->a[i] = s->a[i + 1];
	}
	s->size--;
}

void SeqListPrint(SeqList* s)
{
	int i = 0;
	for (i = 0;i < s->size;i++)
	{
		printf("%d ", s->a[i]);
	}
	printf("\n");
}

void SeqListDestory(SeqList* s)
{
	assert(s != NULL);
	free(s->a);
	s->a = NULL;
	s->size = 0;
	s->capacity = 0;
}