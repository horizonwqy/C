#include"game.h"
void game()
{
	init(map,show,ROWS,COLS);
	print(map, show, ROW, COL);
	while (sweep(map, show,ROW,COL));
}
int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
		menu();
		printf("Please enter your choice(0/1):>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			break;
		default:
			printf("Wrong!Please choose again.\n");
			break;
		}
	} while (input);
	return 0;
}