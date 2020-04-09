#include<stdio.h>
void what_to_do(int now)
{
	char c[10];   //c는 그냥 입력받기 위한 도구
	char yn;  //yes or no
	int yn2;


	if ((you[now].x == 4 && you[now].y == 0) || (you[now].x == 3 && you[now].y == 4)) //황금열쇠
	{
		block[you[now].x][you[now].y].own = 3; //나중에 다른 지역 이동하는 황금열쇠가 걸렸을 때 빈 땅으로 구매하는 if를 방지하기 위해
		key(now);
	}
	if (you[now].x == 7 && you[now].y == 4)   //행운당첨
	{
		go(20, 12);
		for (int i = 1; i <= 40; i++) printf(" ");
		go(30, 10);
		printf("15만원을 행운당첨으로!");
		you[now].money -= 15;
		block[7][0].price += 15;
		if (you[now].money < 0) //돈이 없을 때
		{
			sell(now);
		}
		money(now);

		go(20, 11);
		color(0, 0, 0, 0, 0, 1, 1, 1);
		printf("다음으로 넘어가려면 Enter 키를 눌러주세요");
		fflush(stdin);
		gets(c);
	}
	else if (you[now].x == 7 && you[now].y == 0)   //학우돕기
	{
		go(20, 12);
		for (int i = 1; i <= 40; i++) printf(" ");
		go(30, 10);
		printf("%d만원을 획득하셨습니다", block[7][0].price);
		you[now].money += block[7][0].price;
		block[7][0].price = 0;
		money(now);

		go(20, 11);
		color(0, 0, 0, 0, 0, 1, 1, 1);
		printf("다음으로 넘어가려면 Enter 키를 눌러주세요");
		fflush(stdin);
		gets(c);
	}
	else if (you[now].x == 0 && you[now].y == 0)  //출발
	{
		return;
	}
	else if ((block[you[now].x][you[now].y].own - 1) != now && block[you[now].x][you[now].y].own != 0 && block[you[now].x][you[now].y].own != 3) //남의 가게에 들어간 경우
	{
		reset();
		color(0, 0, 0, 0, 0, 1, 1, 1);
		go(20, 10);
		printf("남의 가게에서 식사를 하셨습니다.");


		if ((you[now].x == 2 && you[now].y == 4) || (you[now].x == 3 && you[now].y == 0) || (you[now].x == 7 && you[now].y == 2)) //술집인 경우
		{
			you[now].money -= 2 * block[you[now].x][you[now].y].price;
			you[1 - now].money += 2 * block[you[now].x][you[now].y].price;

			money(now);
			money(1 - now);
		}
		else if (block[you[now].x][you[now].y].owner == 1)  //사장인 경우
		{
			you[now].money -= 2 * block[you[now].x][you[now].y].price;
			you[1 - now].money += 2 * block[you[now].x][you[now].y].price;

			money(now);
			money(1 - now);
		}
		else  //직원인 경우
		{
			you[now].money -= block[you[now].x][you[now].y].price;
			you[1 - now].money += block[you[now].x][you[now].y].price;

			money(now);
			money(1 - now);
		}

		if (you[now].money < 0) //돈이 없을 때
		{
			sell(now);
			money(now);
		}

		go(20, 11);
		color(0, 0, 0, 0, 0, 1, 1, 1);
		printf("다음으로 넘어가려면 Enter 키를 눌러주세요");
		fflush(stdin);
		gets(c);
	}

	else if (you[now].money >= block[you[now].x][you[now].y].price && block[you[now].x][you[now].y].own == 0)  //가진 돈이 이 가게를 살 수 있을 때
	{
		if ((you[now].x == 2 && you[now].y == 4) || (you[now].x == 3 && you[now].y == 0) || (you[now].x == 7 && you[now].y == 2))
		{
			go(20, 12);
			for (int i = 1; i <= 40; i++) printf(" ");
			go(28, 11);
			printf("이 술집을 사시겠습니까?(y/n)  ");
			scanf("%c", &yn);
			if (yn != 'y' && yn != 'n')
			{
				while (yn == 'y' || yn == 'n')
				{
					scanf("%c", &yn);
				}
			}
			if (yn == 'y')
			{
				block[you[now].x][you[now].y].own = now + 1;
				you[now].money -= block[you[now].x][you[now].y].price;

				go(2 + 10 * you[now].x, 1 + 5 * you[now].y);
				if (now == 0) color(1, 0, 0, 1, 0, 1, 1, 1);
				else color(1, 1, 0, 0, 0, 1, 1, 1);

				printf("%s", block[you[now].x][you[now].y].name);
				money(now);
			}
		}
		else
		{
			go(26, 11);
			printf("1. 이 음식점에 사장을 하시겠습니까?");
			go(26, 12);
			printf("2. 이 음식점에 직원을 하시겠습니까?");
			go(26, 13);
			printf("3. 그냥 지나가겠습니다.  ");
			scanf("%d", &yn2);

			if (yn2 == 1)
			{
				block[you[now].x][you[now].y].own = now + 1;
				you[now].money -= block[you[now].x][you[now].y].price;
				block[you[now].x][you[now].y].owner = 1;

				go(2 + 10 * you[now].x, 1 + 5 * you[now].y);
				if (now == 0) color(1, 0, 0, 1, 0, 1, 1, 1);
				else color(1, 1, 0, 0, 0, 1, 1, 1);

				printf("%s", block[you[now].x][you[now].y].name);
				money(now);
			}
			else if (yn2 == 2)
			{
				block[you[now].x][you[now].y].own = now + 1;
				you[now].money -= block[you[now].x][you[now].y].price / 2;;
				block[you[now].x][you[now].y].owner = 2;

				go(2 + 10 * you[now].x, 1 + 5 * you[now].y);
				if (now == 0) color(1, 0, 0, 1, 0, 1, 1, 1);
				else color(1, 1, 0, 0, 0, 1, 1, 1);

				printf("%s", block[you[now].x][you[now].y].name);
				money(now);
			}
		}
	}
	else if (!(you[now].x == 2 && you[now].y == 4) && !(you[now].x == 3 && you[now].y == 0) && !(you[now].x == 7 && you[now].y == 2) && you[now].money >= block[you[now].x][you[now].y].price / 2 && block[you[now].x][you[now].y].own == 0)
	{
		go(20, 12);
		for (int i = 1; i <= 40; i++) printf(" ");
		go(24, 11);
		printf("이 음식점에 직원을 하시겠습니까?(y/n)  ");
		scanf("%c", &yn);
		if (yn != 'y' && yn != 'n')
		{
			while (yn == 'y' || yn == 'n')
			{
				scanf("%c", &yn);
			}
		}
		if (yn == 'y')
		{
			block[you[now].x][you[now].y].own = now + 1;
			you[now].money -= (block[you[now].x][you[now].y].price) / 2;
			block[you[now].x][you[now].y].owner = 2;

			go(2 + 10 * you[now].x, 1 + 5 * you[now].y);
			if (now == 0) color(1, 0, 0, 1, 0, 1, 1, 1);
			else color(1, 1, 0, 0, 0, 1, 1, 1);

			printf("%s", block[you[now].x][you[now].y].name);
			money(now);
		}

	}
}