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
	//while(parent >= 0)���Ǵ�ģ���Ϊparent��Զ����0
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

//ǰ��:������������С��
//���µ���
void AdjustDown(HPDataType* a, int n, int root/*�����±��൱�ڴӸ���ʼ����*/)
{
	int parent = root;
	int child = parent * 2 + 1;//��Ĭ������ΪС�ģ�����ұ�ΪС�ģ���ô�ͻ�һ��
	while (child < n)
	{
		/*if (a[child] > a[parent * 2 + 2])
		child = parent * 2 + 2;*/
		//�ҳ����Һ�����С���Ǹ�����������˵�����£�childΪ���һ����㲢�������ӣ���ôchild+1��Խ����
	    if (child+1 < n && a[child + 1] < a[child])
	    {
		    child++;//����д��һ�������������Ƚϼ��
	    }
		//�������С�ڸ����򽻻�
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
		
		//������
		//�ӵ�����һ����Ҷ�������ĸ���ʼ����
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
	//������ֻ��β���ǲ��еģ�����ȷ������֮����С��
	//��ͷ���Ǹ����еģ�ͷ��֮�������ѵĹ�ϵȫ����
	//��Ȼβ��Ҳ��Ӱ��һЩ������Ӱ��Ķ��ǲ�����������ȱ�
	//���ֻ��Ҫдһ�����ϵ�������ÿ�������Ƚ�
	//ʱ�临�Ӷ�ΪO��logN��
	//
	if (php->_size == php->_capacity)
	{
		php->_capacity *= 2;
		HPDataType* tmp = (HPDataType*)realloc(php->_a, sizeof(HPDataType) * php->_capacity);
		//��Ҫ�ж�һ���Ƿ񿪱ٳɹ�
		php->_a = tmp;
	}
	php->_a[php->_size++] = x;
	//���ϵ����㷨
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

