#include<stdio.h>

void reset()
{
	for (int i = 8; i <= 15; i++) // ���� ��� �ʱ�ȭ
	{
		go(14, i);
		for (int j = 1; j <= 52; j++) printf(" ");
	}
}