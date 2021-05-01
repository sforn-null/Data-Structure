#include"Sort.h"


void PrintArray(int* a, int n)
{
	for (int i = 0;i < n;i++)
	{
		printf("%d", a[i]);
	}
	printf("\n");
}

void InsertSort(int* a, int n)
{
	assert(a);
	for (int i = 0;i < n - 1;++i)
	{
		int end = i;
		int tmp = a[end + 1];
		while (end >= 0)
		{
			if (tmp < a[end])
			{
				a[end + 1] = a[end];
				end--;
			}
			else
			{
				break;
			}
		}
		a[end + 1] = tmp;
	}
}

void ShellSort(int* a, int n)
{
	assert(a);
	//1.gap > 1�൱��Ԥ����������ӽ�����
	//2.gap = 1 ���൱��ֱ�Ӳ������򣬱�֤����
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		//+1��֤�����һ��gapһ����1
		//2.gap = 1 ���൱��ֱ�Ӳ������򣬱�֤����
		for (int i = 0;i < n - gap;i++)
		{
			int end = i;
			int	tmp = a[end + gap];
			while (end >= 0)
			{
				if (tmp < a[end])
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}	
			a[end + gap] = tmp;
		}
		//PrintArray(a, n);
	}
	
}

void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

void SelectSort(int* a, int n)
{
	assert(a);
	int begin = 0;
	int end = n - 1;
	while (begin < end)
	{
		int min, max;
		min = max = begin;
		for (int i = begin + 1;i <= end;i++)
		{
			if (a[i] > a[max])
			{
				max = i;
			}
			if (a[i] < a[min])
			{
				min = i;
			}
		}
		/*if (begin == max)
		{
			int tmp = a[begin];
			Swap(&a[begin], &a[min]);
			Swap(&a[end], &tmp);
		}
		else
		{
			Swap(&a[begin], &a[min]);
			Swap(&a[end], &a[max]);
		}*/

		Swap(&a[begin], &a[min]);
		//���max��begin��λ���ص�����ômax��λ����Ҫ����
		if (begin == max)
		{
			max = min;
		}
		Swap(&a[end], &a[max]);
		begin++;
		end--;
	}
}

void AdjustDwon(int* a, int n, int root)
{
	int parent = root;
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (child + 1 < n && a[child + 1] > a[child])
		{
			++child;
		}
		if (a[child] > a[parent])
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

void HeapSort(int* a, int n)
{
	//�����򣬽����
	for (int i = (n - 1 - 1) / 2;i >= 0;i--)
	{
		AdjustDwon(a, n, i);
	}
	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDwon(a, end, 0);
		end--;
	}
}

void BubbleSort(int* a, int n)
{
	int end = n;
	while (end > 0)
	{
		int exchange = 0;
		for (int i = 0;i < end;i++)
		{
			if (a[i - 1] > a[i])
			{
				Swap(&a[i - 1], &a[i]);
				exchange = 1;
			}
		}
		if (exchange = 0)
		{
			break;
		}
		end--;
	}
}

//Ϊ�˱����������ѡkeyʱ��Ҫѡ�����ĺ���С��
//����ȡ�з�ѡkey
//�����������ٻ����
//����ۺ϶��Կ���ʱ��ʱ�临�Ӷ�ΪO(N*logN)
//�ռ临�Ӷ�ΪO(logN)

int GetMidIndex(int* a, int begin, int end)
{
	int mid = (begin + end) / 2;
	if (a[begin] < a[mid])
	{
		if (a[mid] < a[end])
			return mid;
		else if (a[end] < a[begin])
			return begin;
		else
			return end;
	}
	else
	{
		if (a[begin] < a[end])
			return begin;
		else if (a[end] < a[mid])
			return mid;
		else
			return end;
	}
}

//[begin,end]
//����ָ�뷨
int PartSort1(int* a, int begin, int end)
{
	int midIndex = GetMidIndex(a, begin, end);
	Swap(&a[midIndex], &a[end]);
	int keyindex = end;
	while (begin < end)
	{
		//begin�Ҵ�
		//keyΪend��ʱ������ߵ�begin�ȶ���
		//�ܱ�֤���ֹͣ���Ǹ�λ�õ�ֵһ����key��
		while (begin < end && a[begin] <= a[keyindex])
		{
			begin++;
		}
		//endҪ��С
		while (begin < end && a[end] >= a[keyindex])
		{
			end--;
		}
		Swap(&a[begin], &a[end]);
	}
	Swap(&a[begin], &a[keyindex]);
	return begin;
}

//�ڿӷ�
int PartSort2(int* a, int begin, int end)
{
	int midIndex = GetMidIndex(a, begin, end);
	Swap(&a[midIndex], &a[end]);
	int key = a[end];
	while (begin < end)
	{
		//begin�Ҵ�
		//keyΪend��ʱ������ߵ�begin�ȶ���
		//�ܱ�֤���ֹͣ���Ǹ�λ�õ�ֵһ����key��
		while (begin < end && a[begin] <= key)
		{
			begin++;
		}
		a[end] = a[begin];
		//endҪ��С
		while (begin < end && a[end] >= key)
		{
			end--;
		}
		a[begin] = a[end];
	}
	a[begin] = key;
	return begin;
}

//ǰ��ָ�뷨
//cur�ҵ�
int PartSort3(int* a, int begin, int end)
{
	int midIndex = GetMidIndex(a, begin, end);
	Swap(&a[midIndex], &a[end]);
	int cur = begin;
	int prev = begin-1;
	int keyIndex = end;
	while (cur <= end)
	{
		if (a[cur] <= a[keyIndex] && ++prev != cur)
		{
			Swap(&a[prev], &a[cur]);
		}
		cur++;
	}
	return prev;
}

//�ݹ�
//void QuickSort(int* a, int left, int right)
//{
//	assert(a);
//	if (left >= right)
//		return;
//	if ((right - left) > 10)
//	{
//		int div = PartSort(a, left, right);
//		QuickSort(a, left, div - 1);
//		QuickSort(a, div + 1, right);
//	}
//	else
//	{
//		InsertSort(a+left, right - left + 1);
//	}
//}

//�ݹ�ĳɷǵݹ�
//1.�ĳ�ѭ����쳲�����������⣩һЩ�򵥵ĵݹ���ܸĳ�ѭ��
//2.ջģ��洢���ݷǵݹ�
//�ĳɷǵݹ������:1�����Ч�ʣ��ݹ齨��ջ֡���������ĵģ�
// ���Ƕ����ִ��ļ����������Ż�΢����΢���Ժ��ԣ�
//2.�ݹ�����ȱ���ǣ����ջ֡�����̫����ܻᵼ��ջ���
//��Ϊϵͳջ�ռ�һ�㲻��һ����M����
//   ���ݽṹģ��ǵݹ飬�����Ǵ洢�ڶ��ϵģ�����G�����
void QuickSort(int* a, int left, int right)
{
	assert(a);
	Stack st;
	StackInit(&st);
	StackPush(&st, right);
	StackPush(&st, left);
	while (!StackEmpty(&st))
	{
		int begin = StackTop(&st);
		StackPop(&st);
		int end = StackTop(&st);
		StackPop(&st);
		int div = PartSort3(a, begin, end);
		
		if (div + 1 < end)
		{
			StackPush(&st, end);
			StackPush(&st, div + 1);
		}
		if (begin < div - 1)
		{
			StackPush(&st, div - 1);
			StackPush(&st, begin);
		}
	}
}


void _MergeSort(int* a, int left, int right, int* tmp)
{
	if (left >= right)
		return;
	int mid = (left + right) / 2;
	_MergeSort(a, left, mid, tmp);
	_MergeSort(a, mid + 1, right, tmp);
	int begin1 = left, end1 = mid;
	int begin2 = mid + 1, end2 = right;
	int index = begin1;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
		{
			tmp[index++] = a[begin1++];
		}
		else
		{
			tmp[index++] = a[begin2++];
		}
	}
	while (begin1 <= end1)
		tmp[index++] = a[begin1++];
	while (begin2 <= end2)
		tmp[index++] = a[begin2++];
	for (int i = left;i <= right;i++)
	{
		a[i] = tmp[i];
	}
}

void MergeSort(int* a, int n)
{
	assert(a);
	int* tmp = malloc(sizeof(int) * n);
	_MergeSort(a, 0, n - 1, tmp);
	free(tmp);
}
