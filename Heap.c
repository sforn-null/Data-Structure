#include "Heap.h"

void Swap(HPDataType* p1, HPDataType* p2)
{
	HPDataType* tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

void AdjustUp(HPDataType* a, int n, int child)
{
	int parent = (child = 1) / 2;
	//while(parent >= 0)这是错的，因为parent永远大于0
	while (child > 0)
	{
		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}

//前提:左右子树都是小堆
//向下调整
void AdjustDown(HPDataType* a, int n, int root/*根的下标相当于从根开始调整*/)
{
	int parent = root;
	int child = parent * 2 + 1;//先默认左孩子为小的，如果右边为小的，那么就换一下
	while (child < n)
	{
		/*if (a[child] > a[parent * 2 + 2])
		child = parent * 2 + 2;*/
		//找出左右孩子中小的那个，并且在最极端的情况下，child为最后一个结点并且是左孩子，那么child+1就越界了
	    if (child+1 < n && a[child + 1] < a[child])
	    {
		    child++;//两种写法一样，不过这样比较简洁
	    }
		//如果孩子小于父亲则交换
	    if (a[child] < a[parent])
	    {
		    Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
	    }
		else
		{
			break;
		}
	}
	
}
void HeapInit(Heap* php, HPDataType* a, int n)
{
	php->_a = (HPDataType*)malloc(sizeof(HPDataType) * n);
	if (php->_a == NULL)
	{
		perror("malloc");
	}
	else
	{
		memcpy(php->_a, a, sizeof(HPDataType) * n);
		php->_size = n;
		php->_capacity = n;
		
		//构建堆
		//从倒数第一个非叶结点的树的根开始调整
		for (int i = (n - 1 - 1) / 2;i >= 0;i--)
		{
			AdjustDown(php->_a, php->_size, i);
		}
	}
}

void HeapDestory(Heap* php)
{
	assert(php);
	free(php->_a);
	php->_a = NULL;
	php->_capacity = php->_size = 0;
}

void HeapPush(Heap* php, HPDataType x)
{
	assert(php);
	//单纯的只是尾插是不行的，不能确定插入之后还是小堆
	//而头插是更不行的，头插之后整个堆的关系全乱了
	//虽然尾插也会影响一些，但是影响的都是插入的数的祖先辈
	//因此只需要写一个向上调整，与每个父辈比较
	//时间复杂度为O（logN）
	//
	if (php->_size == php->_capacity)
	{
		php->_capacity *= 2;
		HPDataType* tmp = (HPDataType*)realloc(php->_a, sizeof(HPDataType) * php->_capacity);
		//需要判断一下是否开辟成功
		php->_a = tmp;
	}
	php->_a[php->_size++] = x;
	//向上调整算法
	AdjustUp(php->_a, php->_size, php->_size - 1);
}

void HeapPop(Heap* php)
{
	assert(php);
	assert(php->_size > 0);

	Swap(&php->_a[0], &php->_a[php->_size - 1]);
	php->_size--;
	AdjustDown(php->_a, php->_size, 0);
}

HPDataType HeapTop(Heap* php)
{
	assert(php);
	assert(php->_size > 0);
	return php->_a[0];
}

