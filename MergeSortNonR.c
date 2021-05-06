#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<time.h>
#include"Stack.h"
#include<memory.h>
void MergeArr(int* a, int begin1, int end1, int begin2, int end2, int* tmp)
{
	int left = begin1;
	int right = end2;
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

void MergeSortNonR(int* a, int n)
{
	assert(a);
	int* tmp = malloc(sizeof(int) * n);
	int gap = 1;
	while (gap < n)
	{
		for (int i = 0;i < n;i += (2 * gap))
		{
			int begin1 = i, begin2 = i + gap, end1 = i + gap - 1, end2 = 2 * gap + i - 1;
			if (begin2 >= n)
			{
				break;
			}
			if (end2 >= n)
			{
				end2 = n - 1;
			}
			MergeArr(a, begin1, end1, begin2, end2, tmp);
		}
		gap = gap * 2;
	}
	free(tmp);
}