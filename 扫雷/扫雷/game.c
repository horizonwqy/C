#include"game.h"
int count;
void menu()
{
	printf("***********************\n");
	printf("******   1.play   *****\n");
	printf("******   0.exit   *****\n");
	printf("***********************\n");
}
void open(int map[ROWS][COLS], char show[ROWS][COLS], int x, int y)
{
	if (show[x][y] == '?')//若未打开，就打开
	{
		if (map[x][y] == 0)//递归打开
		{
			count++;
			show[x][y] = ' ';
			for (int m = -1; m <= 1; m++)
			{
				for (int n = -1; n <= 1; n++)
				{
					if (map[x + m][y + n] != -1 && show[x + m][y + n] != ' ')
						open(map, show, x + m, y + n);
				}
			}
		}
		else//普通打开
		{
			count++;
			show[x][y] = '0' + map[x][y];
		}
	}
}
int judge(int x,int row,int col,int mine)
{
	if (x == row * col - mine)
	{
		return 1;
	}
	else
		return 0;
}
int sweep(int map[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x, y;
	printf("Please enter the coordinate you choose:>");
	scanf("%d%d", &x, &y);
	if (map[x][y] == -1)
	{
		for (x = 1; x <= row; x++)
		{
			for (y = 1; y <= col; y++)
			{
				if (map[x][y] == -1)
					show[x][y] = '*';
			}
		}
		printf("You lose!\n");
		print(map, show, row, col);
		return 0;
	}
	else
	{
		if (show[x][y] == '?')
		{
			open(map, show, x, y);
			print(map, show, row, col);
			if (judge(count, row, col, MINE))
			{
				printf("You win!\n");
				return 0;
			}
		}
		else
			printf("Wrong!Please choose again!\n");
	}
	return 1;
}
void init(int map[ROWS][COLS],char show[ROWS][COLS],int row,int col)
{
	int i, j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			map[i][j] = 0;
			if(i== 0||i==row-1||j==col-1||j==0)
				show[i][j] = ' ';
			else
				show[i][j] = '?';
		}
	}
	for (i = 0; i < MINE;)
	{
		int x = rand() % (row-2)+1;
		int y = rand() % (col-2)+1;
		if (map[x][y] == 0)
		{
			i++;
			map[x][y] = -1;
		}
	}
	for (i = 1; i < row - 1; i++)
	{
		for (j = 1; j < col - 1; j++)
		{
			if (map[i][j] == -1)
			{
				for (int m = -1; m <= 1; m++)
				{
					for (int n = -1; n <= 1; n++)
					{
						if (map[i + m][j + n] != -1)
							map[i + m][j + n]++;
					}
				}
			}
		}
	}
}
void print(int map[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int i, j;
	for (i = 1; i <= row; i++)
	{
		for (j = 1; j <= col; j++)
		{
			printf(" %2d", map[i][j]);
		}
		printf("\n");
	}
	for (i = 0; i <=col; i++)
	{
		printf("%d ",i );
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d", i);
		for (j = 1; j <= col; j++)
		{
			printf(" %c", show[i][j]);
		}
		printf("\n");
	}
}