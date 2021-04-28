#include"BinaryTree.h"


void Test1()
{
	BTNode* A = BinaryTreeCreate('A');
	BTNode* B = BinaryTreeCreate('B');
	BTNode* C = BinaryTreeCreate('C');
	BTNode* D = BinaryTreeCreate('D');
	BTNode* E = BinaryTreeCreate('E');

	A->_left = B;
	A->_right = C;
	B->_left = D;
	B->_right = E;

	BinaryTreePrevOrder(A);
	printf("\n");

	BinaryTreeInOrder(A);
	printf("\n");

	BinaryTreePostOrder(A);
	printf("\n");

	//printf("TreeSize = %d\n", BinaryTreeSize(A));
	//这种就不对了


	/*int size = 0;
	BinaryTreeSize(A, &size);
	printf("TreeSize = %d\n",size);

	size = 0;
	BinaryTreeSize(B, &size);
	printf("TreeSize = %d\n", size);*/
	//这种方法能用，但是很麻烦，不好用

	printf("TreeSize = %d\n", BinaryTreeSize(A));
	printf("TreeSize = %d\n", BinaryTreeSize(B));
	printf("TreeLeafSize = %d\n", BinaryTreeLeafSize(A));
	printf("BinaryTreeDepth = %d\n", BinaryTreeDepth(A));

	printf("BinaryTreeLevelKSize = %d\n", BinaryTreeLevelKSize(A,3));

	BinaryTreeLevelOrder(A);

	printf("BinaryTreeComplete = %d\n", BinaryTreeComplete(A));
}
int main()
{
	Test1();
	return 0;
}