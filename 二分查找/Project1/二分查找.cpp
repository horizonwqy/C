#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int arr[10] = { 0,1,2,3,4,5,6,7,8,9 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	int left = 0, right = sz - 1;
	int n = 0;
	scanf("%d", &n);
	int mid;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (n > arr[mid])
		{
			left = mid+1;
		}
		else if (n < arr[mid])
		{
			right = mid-1;
		}
		else
			break;
	}
	if (left > right)
	{
		printf("没找到");
	}
	else
	{
		printf("找到了，下标是：%d",mid);
	}
	return 0;
}