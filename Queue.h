#pragma once

#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

typedef int QDataType;
typedef struct QueueNode
{
	QDataType _data;
	struct QueueNode* _next;
 }QueueNode;

typedef struct Queue
{
	QueueNode* _head;
	QueueNode* _tail;
}Queue;

void QueueInit(Queue* pq);

void QueueDestory(Queue* pq);

void Queuepush(Queue* pq, QDataType x);

void QueuePop(Queue* pq);

QDataType QueueFront(Queue* pq);

QDataType QueueBack(Queue* pq);

int QueueEmpty(Queue* pq);
//返回1是空，返回0是非空

int QueueSize(Queue* pq);