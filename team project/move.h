#include<stdio.h>


void move(int now, int num)
{
	int x1, y1; // 1�� 2�� xy ��ǥ
	int a, b; //now�� ���� �ʱⰪ
	if (now == 0)
	{
		a = 3; b = 4;
	}
	else
	{
		a = 7; b = 4;
	}

	x1 = a + you[now].x * 10;
	y1 = b + you[now].y * 5;

	while (1)
	{
		if (num == 0) return;
		switch (you[now].direction)
		{
		case 0: you[now].y++; break;
		case 1: you[now].x++; break;
		case 2: you[now].y--; break;
		case 3: you[now].x--; break;
		}

		if (you[now].direction == 0 && you[now].y > 4)
		{
			you[now].direction = 1;
			you[now].x += (you[now].y - 4);
			you[now].y = 4;
		}
		if (you[now].direction == 1 && you[now].x > 7)
		{
			you[now].direction = 2;
			you[now].y -= (you[now].x - 7);
			you[now].x = 7;
		}
		if (you[now].direction == 2 && you[now].y < 0)
		{
			you[now].direction = 3;
			you[now].x -= (0 - you[now].y);
			you[now].y = 0;
		}
		if (you[now].direction == 3 && you[now].x < 0)
		{
			you[now].direction = 0;
			you[now].y += (0 - you[now].x);
			you[now].x = 0;
		}
		num--;
		if (you[now].x == 0 && you[now].y == 0) you[now].money += 20;


		go(x1, y1);
		printf("  ");
		Sleep(150);
		go(a + you[now].x * 10, b + you[now].y * 5);
		if (now == 0) color(1, 0, 0, 1, 0, 1, 1, 1);
		else color(1, 1, 0, 0, 0, 1, 1, 1);
		printf("��");
		Sleep(150);
		x1 = a + you[now].x * 10;
		y1 = b + you[now].y * 5;

		if (you[now].x == 0 && you[now].y == 0) money(now);
	}
}