#pragma once
#include<stdio.h>
#include<stdlib.h>

typedef char BTDataType;
typedef struct BinaryTreeNode
{
	BTDataType _data;
	struct BinaryTreeNode* _left;
	struct BinaryTreeNode* _right;
}BTNode;

// ͨ��ǰ�����������"ABD##E#H##CF##G##"����������
BTNode* BinaryTreeCreate(int x);

// ����������
void BinaryTreeDestory(BTNode** root);

// �������ڵ����
int BinaryTreeSize(BTNode* root);

// ������Ҷ�ӽڵ����
int BinaryTreeLeafSize(BTNode* root);

// ��������k��ڵ����
int BinaryTreeLevelKSize(BTNode* root, int k);

// ����������ֵΪx�Ľڵ�
BTNode* BinaryTreeFind(BTNode* root, BTDataType x);

// ������ǰ�����
void BinaryTreePrevOrder(BTNode* root);

// �������������
void BinaryTreeInOrder(BTNode* root);

// �������������
void BinaryTreePostOrder(BTNode* root);

//�����������
int BinaryTreeDepth(BTNode* root);