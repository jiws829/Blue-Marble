#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void key(int now)
{
	char key_name[9][100] = { { "으어어~~취한다~~!! 2차다~~!! 삼파전으로 가십시오" }, { "후배님이 밥 사달라하네ㅠㅠㅠㅠ 15만원을 내십시오" },
	{ "장학금이 나왔습니다. 10만원을 받아가세요" }, { "미팅을 가는 날ㅎㅎㅎ 20만원을 사용 햇습니다ㅠㅠㅠ" },
	{ "땡전집 클라스를 보여주마~~!! 땡전집으로 가십시오" }, { "마음의 고향으로 고고고~~!! 춘자로 가십시오" },
	{ "인생은 복불복~~!! 15만원 지급!!" }, { "우리과 과탑~~!! 30만원의 장학금이 나왔습니다" },
	{ "술 취한 후 다음 날 아침 15만원이 사라졌습니다" } };

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