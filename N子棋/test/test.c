#include"game.h"
int main()
{
	srand((unsigned int)time(NULL));
	int input;
	do 
	{	
		menu();
		printf("Please enter your choose(0/1):>");
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
		}
	}
	while (input);
	return 0;
}