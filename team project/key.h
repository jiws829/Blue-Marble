#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void key(int now)
{
	char key_name[9][100] = { { "�����~~���Ѵ�~~!! 2����~~!! ���������� ���ʽÿ�" }, { "�Ĺ���� �� ��޶��ϳפФФФ� 15������ ���ʽÿ�" },
	{ "���б��� ���Խ��ϴ�. 10������ �޾ư�����" }, { "������ ���� �������� 20������ ��� �޽��ϴ٤ФФ�" },
	{ "������ Ŭ�󽺸� �����ָ�~~!! ���������� ���ʽÿ�" }, { "������ �������� ����~~!! ���ڷ� ���ʽÿ�" },
	{ "�λ��� ���Һ�~~!! 15���� ����!!" }, { "�츮�� ��ž~~!! 30������ ���б��� ���Խ��ϴ�" },
	{ "�� ���� �� ���� �� ��ħ 15������ ��������ϴ�" } };

	int random;

	srand(time(NULL));

	random = rand() % 9;

	reset();
	go(16, 12);
	printf("%s", key_name[random]);


	switch (random)
	{
	case 0: move_key(now, 7, 2); reset(); break;
	case 1: you[now].money -= 15; break;
	case 2: you[now].money += 10; break;
	case 3: you[now].money -= 20; break;
	case 4: move_key(now, 3, 0); reset(); break;
	case 5: move_key(now, 2, 4); reset(); break;
	case 6: you[now].money += 15; break;
	case 7: you[now].money += 30; break;
	case 8: you[now].money -= 15; break;
	}
	money(now);
	if (random != 0 && random != 4 && random != 5)
	{
		go(28, 13);
		char c[100];
		fflush(stdin);
		gets(c);
	}
}