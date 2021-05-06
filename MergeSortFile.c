#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<time.h>
#include"Stack.h"
#include<memory.h>

void _MergeFile(const char* file1, const char* file2, const char* mfile)
{
	FILE* fout1 = fopen(file1, "r");
	if (fout1 == NULL)
	{
		printf("打开文件失败\n");
		exit(-1);
	}
	FILE* fout2 = fopen(file2, "r");
	if (fout2 == NULL)
	{
		printf("打开文件失败\n");
		exit(-1);
	}
	FILE* fin = fopen(mfile, "w");
	if (fin == NULL)
	{
		printf("打开文件失败\n");
		exit(-1);
	}
	int num1 = 0, num2 = 0;
	int ret1 = fscanf(fout1, "%d\n", &num1);
	int ret2 = fscanf(fout2, "%d\n", &num2);
	while (ret1 != EOF && ret2 != EOF)
	{
		if (num1 < num2)
		{
			fprintf(fin, "%d\n", num1);
			ret1 = fscanf(fout1, "%d\n", &num1);
		}
		else
		{
			fprintf(fin, "%d\n", num2);
			ret2 = fscanf(fout2, "%d\n", &num2);
		}
	}
	while (ret1 != EOF)
	{
		fprintf(fin, "%d\n", num1);
		ret1 = fscanf(fout1, "%d\n", &num1);
	}
	while (ret2 != EOF)
	{
		fprintf(fin, "%d\n", num2);
		ret2 = fscanf(fout2, "%d\n", &num2);
	}
	fclose(fout1);
	fclose(fout2);
	fclose(fin);
}


void MergeSortFile(const char* file)
{
	FILE* fout = fopen(file, "r");
	if (fout == NULL)
	{
		printf("打开文件失败\n");
		exit(-1);
	}
	//分割成一段一段数据，内存排序后写到小文件
	int n = 10;
	int a[10];
	int i = 0;
	int filei = 0;
	int num = 0;
	char subfile[20];

	memset(a, 0, sizeof(int) * n);
	while (fscanf(fout, "%d\n", &num) != EOF)
	{

		if (i < n - 1)
		{
			a[i++] = num;
		}
		else
		{
			a[i] = num;
			QuickSort(a, 0, n - 1);
			sprintf(subfile, "%d", filei++);
			//相当于建立了小文件
			FILE* fin = fopen(subfile, "w");
			for (int i = 0;i < n;i++)
			{
				fprintf(fin, "%d\n", a[i]);
				//将内容写进小文件
			}
			fclose(fin);
			i = 0;
			memset(a, 0, sizeof(int) * n);
		}
	}

	//利用互相归并到文件，实现整体有序
	char mfile[100] = "01";
	char file1[100] = "0";
	char file2[100];
	for (int i = 1;i < n;i++)
	{
		sprintf(file2, "%d", i);

		//读取file1和file2，进行归并出mfile
		_MergeFile(file1, file2, mfile);

		strcpy(file1, mfile);
		sprintf(mfile, "%s%d", mfile, i + 1);
	}
	fclose(fout);
}