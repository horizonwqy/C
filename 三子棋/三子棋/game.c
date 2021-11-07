#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
void game()
{
	char ret = 0;//用ret来判断游戏输赢
	char arr[R][C] = { 0 };//棋盘
	init(arr,R,C);//初始化棋盘
	show(arr,R,C);//打印棋盘
	while (1)//人机循环放置棋子
	{
		player(arr, R, C);
		ret=judge(arr,R,C);//放置一次，判断一次
		if (ret != 'C')//直至ret!='c'，说明游戏已结束，跳出循环
		{
			break;
		}
		computer(arr, R, C);
		ret=judge(arr,R,C);
		if (ret != 'C')
		{
			break;
		}
	}
	//游戏已结束，判断结束的情况：人赢；电脑赢；平局。
	if (ret == '*')
	{
		printf("You win!\n");
	}
	else if (ret == '#')
	{
		printf("You lose!\n");
	}
	else
	{
		printf("This is a draw!\n");//draw:n.平局
	}
}
void player(char arr[R][C], int r, int c)
{
	printf("This is your turn,and you want to place it on:>");
	int row, col;
	scanf("%d%d", &row, &col);
	while (1)
	{
		if (arr[row - 1][col - 1] == ' ')//棋盘上的坐标减一才等于数组里的下标
		{
			arr[row - 1][col - 1] = '*';//玩家放置*
			show(arr,r,c);//放置后打印一下
			break;
		}
		else//放置的位置不是空格，说明放置的未知错误
		{
			printf("Wrong!Please choose again.");
		}
	}
}
void computer(char arr[R][C], int r, int c)
{
	printf("This is the computer's turn.");
	while (1)
	{
		int row = rand() % R;//随机数除以行数得到0~R-1之间的随机数
		int col = rand() % C;//同理
		if (arr[row][col] == ' ')
		{
			arr[row][col] = '#';//电脑放置#
			printf("And computer puts it on %d %d.\n", row + 1, col + 1);
			show(arr,r,c);
			break;
		}
	}
}
int full(char arr[R][C], int r, int c)//判断棋盘是否已满，未满则返回0，继续游戏，否则返回1，结束游戏
{
	int i = 0;
	int j = 0;
	for (i = 0; i < r; i++)
	{
		for (j = 0; j < c; j++)
		{
			if (arr[i][j] == ' ')
			{
				return 0;
			}
		}
	}
	return 1;
}
char judge(char arr[R][C],int r,int c)
{
	int i = 0;
	//判断一行的情况
	for (i = 0; i < r; i++)
	{
		if (arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2] && arr[i][0] != ' ')
		{
			return arr[i][0];//返回的值即为玩家或电脑所下的字符，分别代表玩家或电脑赢
		}
	}
	//判断一列的情况
	for (i = 0; i < c; i++)
	{
		if (arr[0][i] == arr[1][i] && arr[1][i] == arr[2][i] && arr[0][i] != ' ')
		{
			return arr[0][i];
		}
	}
	//判断对角线
	if (arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2] && arr[1][1] != ' ')
		return arr[1][1];
	if (arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0] && arr[1][1] != ' ')
		return arr[1][1];
	//判断棋盘是否已满，返回值为1时，返回'Q',代表平局
	if (full(arr, r, c))
	{
		return 'Q';
	}
	return 'C';//棋盘未满，返回'C'，继续游戏
}
void menu()
{
	printf("----------------------------\n");
	printf("-----      1.play     ------\n");
	printf("-----      0.exit     ------\n");
	printf("----------------------------\n");
}
void init(char arr[R][C],int r,int c)
{
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			arr[i][j] = ' ';
		}
	}
}
void show(char arr[R][C], int r, int c)
{
	int i = 0;
	for (i = 0; i < r; i++)
	{
		int j = 0;
		for (j = 0; j < c; j++)
		{
			printf(" %c ", arr[i][j]);
			if (j < c - 1)
				printf("|");
		}
		printf("\n");
		if (i < r - 1)
		{
			for (j = 0; j < c; j++)
			{
				printf("---");
				if (j < c - 1)
					printf("|");
			}
		}
		printf("\n");
	}
}

