#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void menu()
{
	printf("*************************\n");
	printf("*******   0. exit   *****\n");
	printf("*******   1. play   *****\n");
	printf("*************************\n");
}
void game()
{
	int object = rand()%100+1;
	printf("请输入您的猜测：");
	int guess = 0;
	while (1)
	{
		scanf("%d", &guess);
		if (guess > object)
			printf("猜大了，再试一次：");
		else if (guess < object)
		{
			printf("猜小了，再试一次：");
		}
		else
		{
			printf("恭喜你！猜对了。\n");
			break;
		}
	}
}
int main()
{
	srand(time(NULL));
	int input = 0;
	do
	{
		menu();
		printf("请输入你的选择(0/1)>:");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("游戏开始,这个数字在1到100之间\n");
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("输入错误，请重新输入(0/1)>:\n");
			break;
		}
	} while (input);
	return 0;
}