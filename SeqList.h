#ifndef __SEQLIST_H__
#define __SEQLIST_H__
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int SLDataType;
//��int�������ΪSLDataType���Ժ�Ҫ����������ֱ��������ľ���

typedef struct SeqList
{
	SLDataType* a;
	size_t size;
	//���ݸ���
	size_t capacity;
	//����
}SeqList;

void SeqListInit(SeqList* s);
//�Խṹ��ĳ�ʼ��

void SeqListDestory(SeqList* s);
//�Կռ���ͷ�

void SeqListCheckCacity(SeqList* s);
//���ռ��Ƿ��ã���������þʹ���һ��

void SeqListPrint(SeqList* s);
//��ӡ

void SeqListPushBack(SeqList* s,SLDataType x);
//��ĩβ����

void SeqListPopBack(SeqList* s);
//��ĩβɾ��

void SeqListPushFront(SeqList* s, SLDataType x);
//�ڿ�ͷ����

void SeqListPopFront(SeqList* s);
//�ڿ�ͷɾ��

#endif  //__SEQLIST_H__