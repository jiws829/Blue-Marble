#include<stdio.h>
#include<stdlib.h>

void finish(int now)
{
	system("cls");
	go(20, 10);
	color(0, 0, 0, 0, 0, 1, 1, 1);
	if (now == 0)
	{
		printf("2P�� �̰���ϴ�!!");
	}
	else
	{
		printf("1P�� �̰���ϴ�!!");
	}
	char c[100];
	fflush(stdin);
	gets(c);

	exit(0);
}