#ifndef __SEQLIST_H__
#define __SEQLIST_H__
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int SLDataType;
//将int类型替代为SLDataType，以后要改数据类型直接在这里改就行

typedef struct SeqList
{
	SLDataType* a;
	size_t size;
	//数据个数
	size_t capacity;
	//容量
}SeqList;

void SeqListInit(SeqList* s);
//对结构体的初始化

void SeqListDestory(SeqList* s);
//对空间的释放

void SeqListCheckCacity(SeqList* s);
//检查空间是否够用，如果不够用就处理一下

void SeqListPrint(SeqList* s);
//打印

void SeqListPushBack(SeqList* s,SLDataType x);
//在末尾插入

void SeqListPopBack(SeqList* s);
//在末尾删除

void SeqListPushFront(SeqList* s, SLDataType x);
//在开头插入

void SeqListPopFront(SeqList* s);
//在开头删除

#endif  //__SEQLIST_H__