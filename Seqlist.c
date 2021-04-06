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
		////���ݣ��ڶ�������Ҫ���ֽ�����
		////��˲��ܴ�s->capacity * 2 
		size_t newcapacity = s->capacity == 0 ? 4 : s->capacity * 2;
		//�����0�͸�newcapacity��ֵ4
		//�������0�ͽ�ԭ����capacity����һ����ֵ��ȥ
		s->a = realloc(s->a,newcapacity * sizeof(SLDataType));
		s->capacity = newcapacity;
		//��һ�εķ���û�иı�capacity��ֵ
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
	//��Ȼ�����Ǹ����ֻ��ڣ�����ȴ��Ч��
	//sizeֻ����֮ǰ��������
}

void SeqListPushFront(SeqList* s, SLDataType x)
{
	assert(s != NULL);
	//�ȿ��ռ��Ƿ��㹻
	SeqListCheckCacity(s);
	//������Ų��
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