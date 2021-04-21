#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

typedef int STDataType;
typedef struct Stack
{
	STDataType* _a;
	int _top;//ջ���±�
	int _capacity;//����
}Stack;

void StackInit(Stack* pst);
//��ʼ��

void StackDestory(Stack* pst);
//����

void StackPush(Stack* pst, STDataType x);
//��ջ

void StackPop(Stack* pst);
//��ջ

int StackSize(Stack* pst);
//���ݸ���

int StackEmpty(Stack* pst);
//����1�ǿ� ����0�Ƿǿ�

STDataType StackTop(Stack* pst);
//���ջ��������