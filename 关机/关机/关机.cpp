#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	printf("电脑将会在1分钟后关机,请输入十位的正确密码以取消关机：");
	system("shutdown -s -t 60");
	char arr[11] = { 0 };
	char input[20] = { 0 };
	scanf("%s", arr);
	if (strcmp(arr, "0.51321wqy") == 0)
	{
		system("shutdown -a");
		printf("取消成功");
	}
	else
	{
		printf("输入：我是猪 来取消关机\n请输入：");
		scanf("%s", input);
		if (strcmp(input, "我是猪") == 0)
		{
			system("shutdown -a");
			printf("取消成功");
		}
	}
		return 0;
}