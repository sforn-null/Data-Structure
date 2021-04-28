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
//	//int size = 0; 这样最后的结果是一，因为size是局部变量
//	//等于每次都是一个新的size从0加到1，所以size一直都是1
//	size++;
//	BinaryTreeSize(root->_left);
//	BinaryTreeSize(root->_right);
//	return size;
//}  因此这种方法就不好了


//void BinaryTreeSize(BTNode* root,int* psize)
//{
//	if (root == NULL)
//		return ;
//	else
//		(*psize)++;
//	BinaryTreeSize(root->_left, psize);
//	BinaryTreeSize(root->_right, psize);
//}
//这种方法能用，但是很麻烦，不好用

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


//二叉树的第k层结点
int BinaryTreeLevelKSize(BTNode* root, int k)
{
	//原树的k层就是子树的k-1层
	//并且当k等于1时，只有一个结点
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
//这种重复递归了，造成了浪费

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