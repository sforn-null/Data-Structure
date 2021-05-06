#include<assert.h>
#include<stdlib.h>
#include<time.h>
#include"Stack.h"
#include<memory.h>

//只适用于整型，如果浮点型或者字符串排序还得用比较排序
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
	int range/*范围*/ = max - min + 1;
	int* countArr = (int*)malloc(sizeof(int) * range);
	memset(countArr, 0, sizeof(int) * range);

	//统计次数
	for (int i = 0;i < n;i++)
	{
		countArr[a[i] - min]++;
	}

	//排序
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