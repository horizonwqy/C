#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
void menu()
{
	printf("1:play   0:exit\n");
}
void game()
{
	char lei[ROWS][COLS] = { 0 };
	char show[ROWS][COLS] = { 0 };
	csh(lei,ROWS,COLS,'0');
	csh(show, ROWS, COLS, '*');
	//dis(lei,ROW,COL);
	dis(show,ROW,COL);
	fl(lei, ROW, COL);
	//dis(lei, ROW, COL);
	zl(lei,show,ROW,COL);
}
void test()
{
	int input;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择：");
		scanf("%d", &input);
		switch(input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误，请重新选择\n");
			break;
		}
	} while (input);
}
int main()
{
	test();
	return 0;
}