#include<stdio.h>
void what_to_do(int now)
{
	char c[10];   //c�� �׳� �Է¹ޱ� ���� ����
	char yn;  //yes or no
	int yn2;


	if ((you[now].x == 4 && you[now].y == 0) || (you[now].x == 3 && you[now].y == 4)) //Ȳ�ݿ���
	{
		block[you[now].x][you[now].y].own = 3; //���߿� �ٸ� ���� �̵��ϴ� Ȳ�ݿ��谡 �ɷ��� �� �� ������ �����ϴ� if�� �����ϱ� ����
		key(now);
	}
	if (you[now].x == 7 && you[now].y == 4)   //����÷
	{
		go(20, 12);
		for (int i = 1; i <= 40; i++) printf(" ");
		go(30, 10);
		printf("15������ ����÷����!");
		you[now].money -= 15;
		block[7][0].price += 15;
		if (you[now].money < 0) //���� ���� ��
		{
			sell(now);
		}
		money(now);

		go(20, 11);
		color(0, 0, 0, 0, 0, 1, 1, 1);
		printf("�������� �Ѿ���� Enter Ű�� �����ּ���");
		fflush(stdin);
		gets(c);
	}
	else if (you[now].x == 7 && you[now].y == 0)   //�п쵽��
	{
		go(20, 12);
		for (int i = 1; i <= 40; i++) printf(" ");
		go(30, 10);
		printf("%d������ ȹ���ϼ̽��ϴ�", block[7][0].price);
		you[now].money += block[7][0].price;
		block[7][0].price = 0;
		money(now);

		go(20, 11);
		color(0, 0, 0, 0, 0, 1, 1, 1);
		printf("�������� �Ѿ���� Enter Ű�� �����ּ���");
		fflush(stdin);
		gets(c);
	}
	else if (you[now].x == 0 && you[now].y == 0)  //���
	{
		return;
	}
	else if ((block[you[now].x][you[now].y].own - 1) != now && block[you[now].x][you[now].y].own != 0 && block[you[now].x][you[now].y].own != 3) //���� ���Կ� �� ���
	{
		reset();
		color(0, 0, 0, 0, 0, 1, 1, 1);
		go(20, 10);
		printf("���� ���Կ��� �Ļ縦 �ϼ̽��ϴ�.");


		if ((you[now].x == 2 && you[now].y == 4) || (you[now].x == 3 && you[now].y == 0) || (you[now].x == 7 && you[now].y == 2)) //������ ���
		{
			you[now].money -= 2 * block[you[now].x][you[now].y].price;
			you[1 - now].money += 2 * block[you[now].x][you[now].y].price;

			money(now);
			money(1 - now);
		}
		else if (block[you[now].x][you[now].y].owner == 1)  //������ ���
		{
			you[now].money -= 2 * block[you[now].x][you[now].y].price;
			you[1 - now].money += 2 * block[you[now].x][you[now].y].price;

			money(now);
			money(1 - now);
		}
		else  //������ ���
		{
			you[now].money -= block[you[now].x][you[now].y].price;
			you[1 - now].money += block[you[now].x][you[now].y].price;

			money(now);
			money(1 - now);
		}

		if (you[now].money < 0) //���� ���� ��
		{
			sell(now);
			money(now);
		}

		go(20, 11);
		color(0, 0, 0, 0, 0, 1, 1, 1);
		printf("�������� �Ѿ���� Enter Ű�� �����ּ���");
		fflush(stdin);
		gets(c);
	}

	else if (you[now].money >= block[you[now].x][you[now].y].price && block[you[now].x][you[now].y].own == 0)  //���� ���� �� ���Ը� �� �� ���� ��
	{
		if ((you[now].x == 2 && you[now].y == 4) || (you[now].x == 3 && you[now].y == 0) || (you[now].x == 7 && you[now].y == 2))
		{
			go(20, 12);
			for (int i = 1; i <= 40; i++) printf(" ");
			go(28, 11);
			printf("�� ������ ��ðڽ��ϱ�?(y/n)  ");
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
			printf("1. �� �������� ������ �Ͻðڽ��ϱ�?");
			go(26, 12);
			printf("2. �� �������� ������ �Ͻðڽ��ϱ�?");
			go(26, 13);
			printf("3. �׳� �������ڽ��ϴ�.  ");
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
		printf("�� �������� ������ �Ͻðڽ��ϱ�?(y/n)  ");
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