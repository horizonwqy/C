#include"game.h"
void menu()
{
	printf("----------------------\n");
	printf("------  0.exit  ------\n");
	printf("------  1.play  ------\n");
	printf("----------------------\n");
}
void init(char arr[ROW][COL],int row,int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			arr[i][j] = ' ';
		}
	}
}
void print(char arr[ROW][COL],int row,int col)
{
	for (int i = 0; i < col; i++)
	{
		for (int j = 0; j < row; j++)
		{
			printf(" %c ", arr[i][j]);
			if (j < col - 1)
			{
				printf("|");
			}
		}
		printf("\n");
		if (i < row - 1)
		{
			for (int j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
				{
					printf("|");
				}
			}
			printf("\n");
		}	
	}
}
void player(char arr[ROW][COL],int row,int col,int* p)
{
	printf("This is your turn.You want to place on:>");
	int m, n;
	while (1)
	{
		scanf("%d%d", &m, &n);
		if (arr[m - 1][n - 1] == ' ')
		{
			arr[m - 1][n - 1] = '*';
			(*p)++;
			break;
		}
		else
			printf("Wrong!Please choose again:>");
	}
}
void computer(char arr[ROW][COL], int row, int col,int* p)
{
	printf("This is the computer's turn.\n");
	int m, n;
	while (1)
	{
		m = rand() % row;
		n = rand() % col;
		if (arr[m][n] == ' ')
		{
			arr[m][n] = '%';
			(*p)++;
			break;
		}
	}
}
int isfull(int row,int col,int count)
{
	if (count == row * col)
		return 0;
	else
		return 1;
}
char judge(char arr[ROW][COL], int row, int col,int rows,int cols,int count)
{
	int i, j ,m ;
	//横向
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col-cols+1; j++)
		{
			if (arr[i][j] == ' ')
				break;
			for (m = 0; m <cols-1 ; m++)
			{
				if (arr[i][j + m] != arr[i][j + m + 1])
					break;
			}
			if (m == cols - 1)
				return arr[i][j];
		}
	}
	//纵向
	for (i = 0; i < row-rows+1; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (arr[i][j] == ' ')
				break;
			for (m = 0; m < rows - 1; m++)
			{
				if (arr[i+m][j ] != arr[i+m+1][j])
					break;
			}
			if (m == rows-1)
				return arr[i][j];
		}
	}
	//左上到右下
	for (i = 0; i < col-cols+1; i++)
	{
		for (j = 0; j < row - rows+1; j++)
		{
			if (arr[i][j] == ' ')
				break;
			for (m = 0; m < rows - 1; m++)
			{
				if (arr[i + m][j+m] != arr[i + m + 1][j+m+1])
					break;
			}
			if (m == rows - 1)
				return arr[i][j];
		}
	}
	//右上到左下
	for (i = 0; i <row-rows+1; i++)
	{
		for (j = cols-1; j<cols; j++)
		{
			if (arr[i][j] == ' ')
				break;
			for (m = 0; m < rows - 1; m++)
			{
				if (arr[i +m][j -m] != arr[i +m + 1][j - m - 1])
					break;
			}
			if (m == rows - 1)
				return arr[i][j];
		}
	}
	int n = isfull(row,col,count);
	if (!n)
		return 'Q';
	else
		return 'C';
}
void game()
{
	char arr[ROW][COL] = { 0 };
	init(arr, ROW, COL);
	print(arr, ROW, COL);
	char ret;
	int count = 0;
	while (1)
	{
		player(arr,ROW,COL,&count);
		print(arr,ROW,COL);
		ret=judge(arr, ROW, COL,ROWS,COLS,count);
		if (ret != 'C')
		{
			break;
		}
		computer(arr, ROW, COL,&count);
		print(arr, ROW, COL);
		ret=judge(arr, ROW, COL,ROWS, COLS,count);
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret == 'Q')
		printf("This is a draw.\n");
	else if (ret == '*')
		printf("You win!\n");
	else
		printf("You lose!\n");
}