#include "Stack.h"

void StackInit(Stack* pst)
{
	/*assert(pst);
	pst->_a = NULL;
	pst->_top = 0;
	pst->_capacity = 0;*/
	//但是这种方式，第一次放数据不好放不好放

	pst->_a = malloc(sizeof(STDataType) * 4);
	pst->_top = 0;
	pst->_capacity = 4;
}

void StackDestory(Stack* pst)
{
	assert(pst);
	free(pst->_a);
	pst->_a = NULL;
	pst->_top = 0;
	pst->_capacity = 0;
}

void StackPush(Stack* pst, STDataType x)
{
	assert(pst);
	if (pst->_top == pst->_capacity)
	{
		pst->_capacity *= 2;
		STDataType* tmp = (STDataType*)realloc(pst->_a, sizeof(STDataType) * pst->_capacity);
		if (tmp == NULL)
		{
			printf("内存不足");
			exit(-1);
		}
		else
		{
			pst->_a = tmp;
		}
	}
	pst->_a[pst->_top] = x;
	pst->_top++;
}

void StackPop(Stack* pst)
{
	assert(pst);
	assert(pst->_top > 0);
	pst->_top--;
}

int StackSize(Stack* pst)
{
	assert(pst);
	return pst->_top;
}

int StackEmpty(Stack* pst)
{
	assert(pst);
	/*if (pst->_top == 0)
		return 1;
	else
		return 0;*/
	return pst->_top == 0 ? 1 : 0;
}

STDataType StackTop(Stack* pst)
{
	assert(pst);
	assert(pst->_top > 0);
	return pst->_a[pst->_top - 1];
}
