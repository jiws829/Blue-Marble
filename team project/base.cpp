//82x40

#include "horse.h"  //사용자 정보 있는 구조체 선언
#include "go.h"  //커서 이동
#include "color.h"  //콘솔창 색 넣는 함수 선언
#include "board.h"  //보드판 정보 적힌 곳
#include "finish.h"  //파산했을 때
#include "money.h"  //상태창에 돈 출력하는 함수
#include "move.h"  //말 이동
#include "reset.h"  // 말판 가운데 초기화
#include "sell.h" //돈이 마이너스일 때 매각
#include "move_key.h"  //황금열쇠에 의한 말 이동
#include "key.h"  //황금열쇠


#include "tiger.cpp"
#include "map.cpp"   //말판 출력
#include "rand.cpp"   //주사위
#include "what.cpp"  //말판 도달했을 때 해야할 내용


#include<stdio.h>

void main()
{
	char c[10];   //c는 그냥 입력받기 위한 도구

	int num, now = 0;  //num: 주사위   now: 1p와 2p 표시


	color(1, 1, 0, 0, 0, 1, 1, 1);  //흰바탕에 빨간색 글씨

	tiger();         //호랑이 표지 출력 함수
	Sleep(1500);
	system("cls");

	you[0].money = you[1].money = 150;   //시작 금액 초기화

	map();   //지도 표시

	color(1, 0, 0, 1, 0, 1, 1, 1);   //말판에 말 표시
	go(3, 4);
	printf("●");
	color(1, 1, 0, 0, 0, 1, 1, 1);
	go(7, 4);
	printf("●");

	color(0, 0, 0, 0, 0, 1, 1, 1);
	go(20, 10);
	printf("주사위를 굴리려면 Enter 키를 눌러주세요");
	
	
	while (1)
	{
		color(0, 0, 0, 0, 0, 1, 1, 1);
		reset();   //reset 함수는 말판 가운데 글씨들 지우는 함수

		go(20, 10);
		printf("주사위를 굴리려면 Enter 키를 눌러주세요");

		go(60, 10);
		fflush(stdin);
		gets(c);       //주사위 굴리기전 Enter 값을 받기 위해 문자열 c 입력
		go(40, 12);


		num = dice();   //dice 함수가 난수를 발생하여 num에 저장
		color(0, 0, 0, 0, 0, 1, 1, 1);
		printf("%d\n", num);

		move(now, num);   //now에 해당하는 말을 num만큼 말판 이동
		Sleep(250);

		//시작
		color(0, 0, 0, 0, 0, 1, 1, 1);
		reset();
		go(30, 9);
		printf("%s\n", block[you[now].x][you[now].y].menu);   //말이 도착한 칸에 해당하는 문구들 출력

		what_to_do(now);    //말이 어떤한 칸에 도착했을 때 해야 할일들
		now = 1 - now;     //그 다음 말로 턴을 넘김
	}
}