#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int dice()
{
	int i, random;

	srand(time(NULL));

	random = (rand()%6)+1;

	return random;
}