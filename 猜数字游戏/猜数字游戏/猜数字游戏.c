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
	printf("���������Ĳ²⣺");
	int guess = 0;
	while (1)
	{
		scanf("%d", &guess);
		if (guess > object)
			printf("�´��ˣ�����һ�Σ�");
		else if (guess < object)
		{
			printf("��С�ˣ�����һ�Σ�");
		}
		else
		{
			printf("��ϲ�㣡�¶��ˡ�\n");
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
		printf("���������ѡ��(0/1)>:");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("��Ϸ��ʼ,���������1��100֮��\n");
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("�����������������(0/1)>:\n");
			break;
		}
	} while (input);
	return 0;
}