#include<stdio.h>

void reset()
{
	for (int i = 8; i <= 15; i++) // 말판 가운데 초기화
	{
		go(14, i);
		for (int j = 1; j <= 52; j++) printf(" ");
	}
}