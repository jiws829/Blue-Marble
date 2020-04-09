#include<stdio.h>
void sell(int now)
{
	int x, y;
	int dir;

	x = y = dir = 0;


	while (you[now].money<0)
	{
		if (block[x][y].own - 1 == now)
		{
			if (block[x][y].owner == 0 || block[x][y].owner == 1)
			{
				block[x][y].own = 0;
				you[now].money += block[x][y].price;
			}
			else
			{
				block[x][y].own = 0;
				you[now].money += block[x][y].price / 2;
			}
			block[x][y].owner = 0;

			go(2 + 10 * x, 1 + 5 * y);
			color(1, 1, 1, 1, 0, 1, 1, 1);
			printf("%s", block[x][y].name);
		}

		switch (dir)
		{
		case 0: y++; break;
		case 1: x++; break;
		case 2: y--; break;
		case 3: x--; break;
		}

		if (dir == 0 && y > 4)
		{
			dir = 1;
			x += (y - 4);
			y = 4;
		}
		if (dir == 1 && x > 7)
		{
			dir = 2;
			y -= (x - 7);
			x = 7;
		}
		if (dir == 2 && y < 0)
		{
			dir = 3;
			x -= (0 - y);
			y = 0;
		}
		if (dir == 3 && x < 0)
		{
			dir = 0;
			y += (0 - x);
			x = 0;
		}


		if (x == 0 && y == 0)
		{
			Sleep(2000);
			finish(now);
		}
	}
}