#pragma once

//���
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

typedef int HPDataType;
typedef struct Heap
{
	HPDataType* _a;
	int _size;
	int _capacity;
}Heap;

void AdjustUp(HPDataType* a, int n, int root);

void AdjustDown(HPDataType* a, int n, int root);

void HeapInit(Heap* php, HPDataType* a, int n);

void HeapDestory(Heap* php);

void HeapPush(Heap* php, HPDataType x);

void HeapPop(Heap* php);
//ɾ���Ѷ�������

HPDataType HeapTop(Heap* php);