#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	//��������Ϊa
	int a[] = { 1,2,1,6,4,7 };
	int sz = sizeof(a) / sizeof(a[0]);//a�����Ԫ�ظ���
	int arr1[100] = { 0 }, arr2[100] = { 0 };//��������arr1����������arr2
	int i = 0, j = 0;
	for (i = 1; i < 100; i++)
	{
		arr1[i] = i;
	}
	for (i = 0; i < 100; i++)
	{
		for (j = 0; j < sz; j++)
		{
			if (a[j] == arr1[i])
			{
				arr2[i]++;
			}
		}
	}
	for (i = 0; i < 100; i++)
	{
		if (arr2[i] != 0)
		{
			printf("%d������%d��\n", arr1[i], arr2[i]);
		}
	}
	return 0;
}