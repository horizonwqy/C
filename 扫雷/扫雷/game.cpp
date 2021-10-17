#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
void csh(char board[ROWS][COLS], int rows, int cols,char set)
{
	int i, j;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
	}
}
void dis(char board[ROWS][COLS], int row, int col)
{
	int i, j;
	printf("  ");
	for (i = 1; i <= col; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
}
void fl(char board[ROWS][COLS], int row, int col)
{
	int count = EASY_COUNT;
	while (count)
	{
		int x = rand() % row + 1;
		int y = rand() % row + 1;
		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			count--;
		}
	}
}
int jsl(char lei[ROWS][COLS],int x,int y)
{
	return lei[x - 1][y] + lei[x - 1][y - 1] + lei[x][y - 1] + lei[x+1][y-1] + lei[x+1][y] + lei[x+1][y+1] + lei[x][y+1] + lei[x-1][y+1]-8*'0';
}
void zl(char lei[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x, y,win;
	win = 0;
	while (win<row*col-EASY_COUNT)
	{
		printf("请输入排查雷的坐标：");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (lei[x][y] == '1')
			{
				printf("很遗憾，你被炸死了\n");
				dis(lei, row, col);
				break;
			}
			else
			{
				int count=jsl(lei,x,y);
				show[x][y] = count + '0';
				dis(show, row, col);
				win++;
			}
		}
		else
		{
			printf("坐标非法，请重新输入\n");
		}
	}
	if (win ==row * col - EASY_COUNT)
	{
		printf("恭喜你，胜利！");
		dis(lei, row, col);
	}
}
//展开功能的时候，用递归