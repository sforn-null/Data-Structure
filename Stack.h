#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

typedef int STDataType;
typedef struct Stack
{
	STDataType* _a;
	int _top;//栈顶下标
	int _capacity;//容量
}Stack;

void StackInit(Stack* pst);
//初始化

void StackDestory(Stack* pst);
//销毁

void StackPush(Stack* pst, STDataType x);
//入栈

void StackPop(Stack* pst);
//出栈

int StackSize(Stack* pst);
//数据个数

int StackEmpty(Stack* pst);
//返回1是空 返回0是非空

STDataType StackTop(Stack* pst);
//获得栈顶的数据