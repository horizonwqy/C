#define _CRT_SECURE_NO_WARNINGS 1
#include"add.h"
#include<stdio.h>
int main()
{
	int a = 10;
	int b = 20;
	int sum;
	sum = Add(a, b);
	printf("%d\n", sum);
	return 0;
}