#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	//给定数组为a
	int a[] = { 1,2,1,6,4,7 };
	int sz = sizeof(a) / sizeof(a[0]);//a数组的元素个数
	int arr1[100] = { 0 }, arr2[100] = { 0 };//辅助数组arr1，计数数组arr2
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
			printf("%d出现了%d次\n", arr1[i], arr2[i]);
		}
	}
	return 0;
}