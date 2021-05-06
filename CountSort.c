#include<assert.h>
#include<stdlib.h>
#include<time.h>
#include"Stack.h"
#include<memory.h>

//ֻ���������ͣ���������ͻ����ַ������򻹵��ñȽ�����
void CountSort(int* a, int n)
{
	assert(a);
	int min = a[0];
	int max = a[0];
	for (int i = 0;i < n;i++)
	{
		if (a[i] > max)
		{
			max = a[i];
		}
		if (a[i] < min)
		{
			min = a[i];
		}
	}
	int range/*��Χ*/ = max - min + 1;
	int* countArr = (int*)malloc(sizeof(int) * range);
	memset(countArr, 0, sizeof(int) * range);

	//ͳ�ƴ���
	for (int i = 0;i < n;i++)
	{
		countArr[a[i] - min]++;
	}

	//����
	int index = 0;
	for (int j = 0;j < range;j++)
	{
		while (countArr[j]--)
		{
			a[index++] = j + min;
		}
	}

	free(countArr);
}