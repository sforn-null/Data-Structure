#include "BinaryTree.h"

void BinaryTreePrevOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	printf("%c ", root->_data);
	BinaryTreePrevOrder(root->_left);
	BinaryTreePrevOrder(root->_right);
}

void BinaryTreeInOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	BinaryTreeInOrder(root->_left);
	printf("%c ", root->_data);
	BinaryTreeInOrder(root->_right);
}

void BinaryTreePostOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	BinaryTreePostOrder(root->_left);
	BinaryTreePostOrder(root->_right);
	printf("%c ", root->_data);
	
}



BTNode* BinaryTreeCreate(int x)
{
	BTNode* node = (BTNode*)malloc(sizeof(BTNode));
	node->_data = x;
	node->_left = NULL;
	node->_right = NULL;
	return node;
}



//int BinaryTreeSize(BTNode* root)
//{
//	if(root == NULL)
//	return 0;
//
//	//int size = 0; �������Ľ����һ����Ϊsize�Ǿֲ�����
//	//����ÿ�ζ���һ���µ�size��0�ӵ�1������sizeһֱ����1
//	size++;
//	BinaryTreeSize(root->_left);
//	BinaryTreeSize(root->_right);
//	return size;
//}  ������ַ����Ͳ�����


//void BinaryTreeSize(BTNode* root,int* psize)
//{
//	if (root == NULL)
//		return ;
//	else
//		(*psize)++;
//	BinaryTreeSize(root->_left, psize);
//	BinaryTreeSize(root->_right, psize);
//}
//���ַ������ã����Ǻ��鷳��������

int BinaryTreeSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	else
		return 1 + BinaryTreeSize(root->_left) + BinaryTreeSize(root->_right);
}

int BinaryTreeLeafSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	else if (root->_left == NULL && root->_right == NULL)
		return 1;

	return BinaryTreeLeafSize(root->_left) + BinaryTreeLeafSize(root->_right);
}


//�������ĵ�k����
int BinaryTreeLevelKSize(BTNode* root, int k)
{
	//ԭ����k�����������k-1��
	//���ҵ�k����1ʱ��ֻ��һ�����
	if (root == NULL)
		return 0;
	if (k == 1)
		return 1;
	return BinaryTreeLevelKSize(root->_left,k-1) + BinaryTreeLevelKSize(root->_right,k-1);
}

BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	if (root == NULL)
		return NULL;
	if (root->_data == x);
		return root;
	BTNode* node = BinaryTreeFind(root->_left,x);
	if (node)
		return node;
	node = BinaryTreeFind(root->_right, x);
		return node;

	return NULL;
}

//int BinaryTreeDepth(BTNode* root)
//{
//	if (root == NULL)
//		return 0;
//	//if (BinaryTreeDepth(root->_left) > BinaryTreeDepth(root->_right))
//	//{
//	//	return BinaryTreeDepth(root->_left) + 1;
//	//}
//	//else
//	//{
//	//	return BinaryTreeDepth(root->_right) + 1;
//	//}
//	return BinaryTreeDepth(root->_left) > BinaryTreeDepth(root->_right) ? BinaryTreeDepth(root->_left) + 1 : BinaryTreeDepth(root->_right) + 1;
//}
//�����ظ��ݹ��ˣ�������˷�

int BinaryTreeDepth(BTNode* root)
{
	if (root == NULL)
		return 0;
	//if (BinaryTreeDepth(root->_left) > BinaryTreeDepth(root->_right))
	//{
	//	return BinaryTreeDepth(root->_left) + 1;
	//}
	//else
	//{
	//	return BinaryTreeDepth(root->_right) + 1;
	//}
	int leftDepth = BinaryTreeDepth(root->_left);
	int rightDepth = BinaryTreeDepth(root->_right);
	return leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1;
}

void BinaryTreeLevelOrder(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	if (root == NULL)
		return NULL;
	Queuepush(&q, root);
	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		printf("%c ", front->_data);

		if(front->_left)
			Queuepush(&q, front->_left);

		if (front->_right)
			Queuepush(&q, front->_right);
	}
	QueueDestory(&q);
	printf("\n");
}

int BinaryTreeComplete(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	if (root == NULL)
		return 1;
	Queuepush(&q, root);
	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);

		if (front == NULL)
			break;

		Queuepush(&q, front->_left);

		Queuepush(&q, front->_right);
	}
	if (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		if (front)
		{
			QueueDestory(&q);
			return 0;
		}
	}
	QueueDestory(&q);
	return 1;
}


void BinaryTreeDestory(BTNode* root)
{
	if (root == NULL)
		return;

	BinaryTreeDestory(root->_left);
	BinaryTreeDestory(root->_right);
	free(root);
}