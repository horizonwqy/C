#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
void game()
{
	char ret = 0;//��ret���ж���Ϸ��Ӯ
	char arr[R][C] = { 0 };//����
	init(arr,R,C);//��ʼ������
	show(arr,R,C);//��ӡ����
	while (1)//�˻�ѭ����������
	{
		player(arr, R, C);
		ret=judge(arr,R,C);//����һ�Σ��ж�һ��
		if (ret != 'C')//ֱ��ret!='c'��˵����Ϸ�ѽ���������ѭ��
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
	//��Ϸ�ѽ������жϽ������������Ӯ������Ӯ��ƽ�֡�
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
		printf("This is a draw!\n");//draw:n.ƽ��
	}
}
void player(char arr[R][C], int r, int c)
{
	printf("This is your turn,and you want to place it on:>");
	int row, col;
	scanf("%d%d", &row, &col);
	while (1)
	{
		if (arr[row - 1][col - 1] == ' ')//�����ϵ������һ�ŵ�����������±�
		{
			arr[row - 1][col - 1] = '*';//��ҷ���*
			show(arr,r,c);//���ú��ӡһ��
			break;
		}
		else//���õ�λ�ò��ǿո�˵�����õ�δ֪����
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
		int row = rand() % R;//��������������õ�0~R-1֮��������
		int col = rand() % C;//ͬ��
		if (arr[row][col] == ' ')
		{
			arr[row][col] = '#';//���Է���#
			printf("And computer puts it on %d %d.\n", row + 1, col + 1);
			show(arr,r,c);
			break;
		}
	}
}
int full(char arr[R][C], int r, int c)//�ж������Ƿ�������δ���򷵻�0��������Ϸ�����򷵻�1��������Ϸ
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
	//�ж�һ�е����
	for (i = 0; i < r; i++)
	{
		if (arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2] && arr[i][0] != ' ')
		{
			return arr[i][0];//���ص�ֵ��Ϊ��һ�������µ��ַ����ֱ������һ����Ӯ
		}
	}
	//�ж�һ�е����
	for (i = 0; i < c; i++)
	{
		if (arr[0][i] == arr[1][i] && arr[1][i] == arr[2][i] && arr[0][i] != ' ')
		{
			return arr[0][i];
		}
	}
	//�ж϶Խ���
	if (arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2] && arr[1][1] != ' ')
		return arr[1][1];
	if (arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0] && arr[1][1] != ' ')
		return arr[1][1];
	//�ж������Ƿ�����������ֵΪ1ʱ������'Q',����ƽ��
	if (full(arr, r, c))
	{
		return 'Q';
	}
	return 'C';//����δ��������'C'��������Ϸ
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

