#include<stdio.h>
void map()
{
	//말판 출력
	color(0, 0, 0, 0, 0, 1, 1, 1);
	int i, j;

	printf("┌");
	for (i = 2; i <= 40; i++)
	{
		if ((i - 1) % 5 == 0) printf("┬");
		else printf("─");
	}
	printf("┐\n");

	//for (i = 1; i <= 41; i++) printf(" %d", i % 10);

	for (i = 2; i <= 25; i++)
	{
		if (i == 6)
		{
			printf("├");
			for (j = 2; j < 41; j++)
			{
				if (j == 6 || j == 36) printf("┼");
				else if ((j - 1) % 5 == 0) printf("┴");
				else printf("─");
			}
			printf("┤");
		}
		else if (i == 21)
		{
			printf("├");
			for (j = 2; j < 41; j++)
			{
				if (j == 6 || j == 36) printf("┼");
				else if ((j - 1) % 5 == 0) printf("┬");
				else printf("─");
			}
			printf("┤");
		}
		else if ((i - 1) % 5 == 0)
		{
			printf("├────┤");
			for (j = 7; j < 36; j++) printf("  ");
			printf("├────┤");
		}
		else if ((i >= 1 && i <= 6) || (i >= 21 && i <= 26))
		{
			printf("│        │");

			for (j = 7; j < 36; j++)
			{
				if ((j - 1) % 5 == 0) printf("│");
				else printf("  ");
			}

			printf("│        │");
		}
		else
		{
			printf("│        │");

			for (j = 7; j < 36; j++) printf("  ");

			printf("│        │");

		}
		printf("\n");
	}
	printf("└");
	for (i = 2; i <= 40; i++)
	{
		if ((i - 1) % 5 == 0) printf("┴");
		else printf("─");
	}
	printf("┘");

	//말판 이름 및 가격 출력
	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 5; j++)
		{
			color(1, 1, 1, 1, 0, 1, 1, 1);
			go(2 + 10 * i, 1 + 5 * j);
			printf("%s", block[i][j].name);
			if (block[i][j].name[0] != '\0' && !(i == 0 && j == 0) && !(i == 4 && j == 0) && !(i == 7 && j == 0) && !(i == 3 && j == 4) && !(i == 7 && j == 4))
			{
				color(1, 0, 0, 0, 0, 1, 1, 1);
				go(2 + 10 * i , 1 + 5 * j + 1);
				printf("%3d만원", block[i][j].price);
			}
		}
	}


	//사용자 상태 출력
	color(0, 0, 0, 0, 0, 1, 1, 1);
	go(0, 26);
	printf("┌");
	for (i = 1; i <= 8; i++) printf("─");
	printf("┐");
	printf("  ");
	printf("┌");
	for (i = 1; i <= 8; i++) printf("─");
	printf("┐\n");
	
	for (i = 0; i < 3; i++)
	{
		printf("│");
		for (j = 0; j < 8; j++) printf("  ");
		printf("│");
		printf("  ");
		printf("│");
		for (j = 0; j < 8; j++) printf("  ");
		printf("│\n");
	}

	printf("└");
	for (i = 1; i <= 8; i++) printf("─");
	printf("┘");
	printf("  ");
	printf("└");
	for (i = 1; i <= 8; i++) printf("─");
	printf("┘\n");

	color(1, 0, 0, 1, 0, 1, 1, 1);
	go(3, 27);
	printf("1P");
	color(0, 0, 0, 0, 0, 1, 1, 1);
	go(6, 28);
	printf("%d만원",you[0].money);
	
	color(1, 1, 0, 0, 0, 1, 1, 1);
	go(25, 27);
	printf("2P");
	color(0, 0, 0, 0, 0, 1, 1, 1);
	go(28, 28);
	printf("%d만원",you[1].money);
	

}