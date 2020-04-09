//82x40

#include "horse.h"  //����� ���� �ִ� ����ü ����
#include "go.h"  //Ŀ�� �̵�
#include "color.h"  //�ܼ�â �� �ִ� �Լ� ����
#include "board.h"  //������ ���� ���� ��
#include "finish.h"  //�Ļ����� ��
#include "money.h"  //����â�� �� ����ϴ� �Լ�
#include "move.h"  //�� �̵�
#include "reset.h"  // ���� ��� �ʱ�ȭ
#include "sell.h" //���� ���̳ʽ��� �� �Ű�
#include "move_key.h"  //Ȳ�ݿ��迡 ���� �� �̵�
#include "key.h"  //Ȳ�ݿ���


#include "tiger.cpp"
#include "map.cpp"   //���� ���
#include "rand.cpp"   //�ֻ���
#include "what.cpp"  //���� �������� �� �ؾ��� ����


#include<stdio.h>

void main()
{
	char c[10];   //c�� �׳� �Է¹ޱ� ���� ����

	int num, now = 0;  //num: �ֻ���   now: 1p�� 2p ǥ��


	color(1, 1, 0, 0, 0, 1, 1, 1);  //������� ������ �۾�

	tiger();         //ȣ���� ǥ�� ��� �Լ�
	Sleep(1500);
	system("cls");

	you[0].money = you[1].money = 150;   //���� �ݾ� �ʱ�ȭ

	map();   //���� ǥ��

	color(1, 0, 0, 1, 0, 1, 1, 1);   //���ǿ� �� ǥ��
	go(3, 4);
	printf("��");
	color(1, 1, 0, 0, 0, 1, 1, 1);
	go(7, 4);
	printf("��");

	color(0, 0, 0, 0, 0, 1, 1, 1);
	go(20, 10);
	printf("�ֻ����� �������� Enter Ű�� �����ּ���");
	
	
	while (1)
	{
		color(0, 0, 0, 0, 0, 1, 1, 1);
		reset();   //reset �Լ��� ���� ��� �۾��� ����� �Լ�

		go(20, 10);
		printf("�ֻ����� �������� Enter Ű�� �����ּ���");

		go(60, 10);
		fflush(stdin);
		gets(c);       //�ֻ��� �������� Enter ���� �ޱ� ���� ���ڿ� c �Է�
		go(40, 12);


		num = dice();   //dice �Լ��� ������ �߻��Ͽ� num�� ����
		color(0, 0, 0, 0, 0, 1, 1, 1);
		printf("%d\n", num);

		move(now, num);   //now�� �ش��ϴ� ���� num��ŭ ���� �̵�
		Sleep(250);

		//����
		color(0, 0, 0, 0, 0, 1, 1, 1);
		reset();
		go(30, 9);
		printf("%s\n", block[you[now].x][you[now].y].menu);   //���� ������ ĭ�� �ش��ϴ� ������ ���

		what_to_do(now);    //���� ��� ĭ�� �������� �� �ؾ� ���ϵ�
		now = 1 - now;     //�� ���� ���� ���� �ѱ�
	}
}