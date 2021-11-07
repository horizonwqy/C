/*
后续添加功能：
1.计时
2.计分
3.防止第一次就死
4.音乐
5.难度选择
*/
#define _CRT_SECURE_NO_WARNINGS 1
#include<graphics.h>
#include<Windows.h>
#include<stdio.h>
//#include<mmsystem.h>//windows中与多媒体有关的大多数接口。
#include<time.h>
//#pragma comment(lib,"winmm.lib")//导入winmm.lib库,有了它才可以支持对windows多媒体的编程
#pragma warning(disable : 4996) 
#define row 15
#define col 15
#define mine 50
#define size 40
int map[row + 2][col + 2];
int i, j, flag;
IMAGE img[12];
void open(int r, int c);
void game();
void gameinit()
{
	//mciSendString("open ./image/start.mp3 alias BGM",0,0,0);
	//mciSendString("play BGM", 0, 0, 0);
	flag = 0;
	srand((unsigned)time(NULL));
	for (i = 1; i <= row; i++)
	{
		for (j = 1; j <= col; j++)
		{
			map[i][j] = 0;
		}
	}
	for (i = 0; i < mine; )
	{
		int r = rand() % row+1;
		int c = rand() % col+1;
		if (map[r][c] == 0)
		{
			map[r][c] = -1;
			i++;
		}
	}
	for (i = 1; i <= row; i++)
	{
		for (j = 1; j <= col; j++)
		{
			if (map[i][j] == -1)
			{
				for (int m = i - 1; m <= i + 1; m++)
				{
					for (int n = j - 1; n <= j + 1; n++)
					{
						if (map[m][n] != -1)
						{
							map[m][n]++;
						}
					}
				}
			}
		}
	}
		/*
			元素		图片
			0-8			数字       +20     20-28
			-1			雷		   +20     19
			19-28		空白图片  
			39-48  		标记
		*/
	for (int i = 1; i <= row; i++)
	{
		for (int j = 1; j <= col; j++)
		{
			map[i][j] += 20;
		}
	}
	char tmp[20] = { 0 };
	for (i = 0; i < 12;i++)
	{
		sprintf(tmp, "./image/%d.jpg",i);
		loadimage(&img[i], tmp, size, size);
	}
}
void gamedraw()
{
	/*
		元素		图片
		0-8			数字		+20	   20-28
		-1			img[9]		+20    19
		19-28		img[0-8]
		>30			img[10]
	*/
	//cleardevice();
	for ( i = 1; i <= row; i++)
	{
		for ( j = 1; j <= col; j++)
		{
			if (map[i][j] == -1)
			{
				putimage((j - 1) * size, (i - 1) * size, &img[9]);//雷
			}
			else if (map[i][j] >= 0 && map[i][j] <= 8)
			{
				putimage((j - 1) * size, (i - 1) * size, &img[map[i][j]]);//0-8的数字
			}
			else if (map[i][j] >= 19 && map[i][j] <= 28)
			{
				putimage((j - 1) * size, (i - 1) * size, &img[10]);//空白
			}
			else if (map[i][j] > 30)
			{
				putimage((j - 1) * size, (i - 1) * size, &img[11]);//标记图片
			}
		}
	}
}
int mouse()
{
	if (MouseHit())//判断有没有鼠标消息
	{
		MOUSEMSG msg = GetMouseMsg();//鼠标所在x，y坐标
		int r = msg.y / size + 1;
		int c = msg.x / size + 1;
		switch (msg.uMsg)
		{
		case WM_LBUTTONDOWN://左击
			if (map[r][c] > 8&&map[r][c]<29)
			{
				//mciSendString("open ./image/start.mp3 alias BGM", 0, 0, 0);//注意不能重名
				//mciSendString("play BGM", 0, 0, 0);
				map[r][c] -= 20;
				flag++;
				open(r, c);
				//mciSendString("close BGM", 0, 0, 0);//放在if后面的第一行？
			}
			break;
		case WM_RBUTTONDOWN://右击
			if (map[r][c] > 8 && map[r][c] < 29)
			{
				map[r][c] += 20;
			}
			else if(map[r][c] > 30)
			{
				map[r][c] -= 20;
			}
			break;
		}
		return map[r][c];
	}
}
void open(int r,int c)
{
	if (map[r][c] == 0)
	{
		for (int m = r - 1; m <= r + 1; m++)
		{
			for (int n = c - 1; n <= c + 1; n++)
			{
				if (map[m][n]!=19&&map[m][n]>8)
				{
					map[m][n]-=20;
					flag++;
					open(m, n);
				}
			}
		}
	}
}
void judge()
{
	gamedraw();
	if (mouse() == -1)
	{
		int isok = MessageBox(GetHWnd(), "You lose! Do you want to play again?", "notice", MB_OKCANCEL);
		if (isok == IDOK)
		{
			game();
		}
		else
		{
			exit(666);
		}
		//mciSendString("close BGM", 0, 0, 0);
	}
	if (flag == row * col - mine)
	{
		int isok = MessageBox(GetHWnd(), "You win! Do you want to play again?", "notice", MB_OKCANCEL);
		if (isok == IDOK)
		{
			game();
		}
		else
		{
			exit(666);
		}
	}
	
}
//void show()
//{
//	for (i = 1; i <= row; i++)
//	{
//		for (j = 1; j <= col; j++)
//		{
//			printf(" %2d ", map[i][j]);
//		}
//		printf("\n");
//	}
//	//system("cls");
//}
/*void open(int x, int y)
{
	if (map[x][y] == 0)//点到的是空白
	{
		for (int i = x - 1; i <= x + 1; i++)
		{
			for (int j = y- 1; j <= y + 1; j++)
			{
				if (map[i][j] == 20 || map[i][j] != 19)
				{
					if (map[i][j] > 8)//如果没有打开就打开格子，否则不做处理
					{
						flag++;
						map[i][j] -= 20;
						open(i, j);
					}
				}
			}
		}
	}
}*/
/*void judge()
{
	//点到雷了
	if (map[x][y] == -1)
	{
		HWND hnd = GetHWnd();
		int isok = MessageBox(hnd, "是否继续！", "点到雷了游戏结束~", MB_YESNO);
		if (isok == IDYES)
		{
			//把雷关上
			map[x][y] += 20;
			flag--;
		}
		else if (isok == IDNO)
		{
			//退出程序
			exit(0);
		}
	}
	//赢得游戏
	if (flag == row * col - mine)
	{
		HWND hnd = GetHWnd();
		int isok = MessageBox(NULL, "恭喜你，过关成功~是否继续~", "YOU WIN!", MB_YESNO);
		if (isok == IDYES)
		{
			flag = 0;
			gameinit();
		}
		else
		{
			exit(666);
		}
	}
}*/
void game()
{
	gameinit();
	BeginBatchDraw();
	while (1)
	{
		//show();
		//gamedraw();
		FlushBatchDraw();
		judge();
	}
	EndBatchDraw();
}
int main()
{
	initgraph(row*size,col*size,NULL);
	game();
	getchar();
	return 0;
}