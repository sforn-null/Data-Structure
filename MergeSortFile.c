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
		printf("���ļ�ʧ��\n");
		exit(-1);
	}
	FILE* fout2 = fopen(file2, "r");
	if (fout2 == NULL)
	{
		printf("���ļ�ʧ��\n");
		exit(-1);
	}
	FILE* fin = fopen(mfile, "w");
	if (fin == NULL)
	{
		printf("���ļ�ʧ��\n");
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
		printf("���ļ�ʧ��\n");
		exit(-1);
	}
	//�ָ��һ��һ�����ݣ��ڴ������д��С�ļ�
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
			//�൱�ڽ�����С�ļ�
			FILE* fin = fopen(subfile, "w");
			for (int i = 0;i < n;i++)
			{
				fprintf(fin, "%d\n", a[i]);
				//������д��С�ļ�
			}
			fclose(fin);
			i = 0;
			memset(a, 0, sizeof(int) * n);
		}
	}

	//���û���鲢���ļ���ʵ����������
	char mfile[100] = "01";
	char file1[100] = "0";
	char file2[100];
	for (int i = 1;i < n;i++)
	{
		sprintf(file2, "%d", i);

		//��ȡfile1��file2�����й鲢��mfile
		_MergeFile(file1, file2, mfile);

		strcpy(file1, mfile);
		sprintf(mfile, "%s%d", mfile, i + 1);
	}
	fclose(fout);
}