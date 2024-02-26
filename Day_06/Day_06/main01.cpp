#include <iostream>
#include <time.h>

using namespace std;

int _firstComNumber = 0;
int _secondComNumber = 0;
int _thirdComNumber = 0;

void SelectRandomNumber(); //컴퓨터 숫자 랜덤 지정
void PrintComNumber(); //숫자출력
void PrintResult(); //결과출력

void main()
{
	srand(time(NULL));
	printf("========== 컴퓨터 랜덤 숫자 게임 ==========\n");
	SelectRandomNumber(); //컴퓨터 숫자 랜덤 지정
	PrintComNumber(); //숫자출력
	PrintResult(); //결과출력

}

void SelectRandomNumber() //컴퓨터 숫자 랜덤 지정
{
	_firstComNumber = rand() % 100; //0~99 랜덤숫자지정
	_secondComNumber = rand() % 100; //0~99 랜덤숫자지정
	_thirdComNumber = rand() % 100; //0~99 랜덤숫자지정
}

void PrintComNumber() //숫자출력
{
	printf("컴퓨터1 숫자: %d\n", _firstComNumber);
	printf("컴퓨터2 숫자: %d\n", _secondComNumber);
	printf("컴퓨터3 숫자: %d\n", _thirdComNumber);
}

void PrintResult() //결과출력
{
	//첫 번째 컴퓨터가 승리할 때
	if (_firstComNumber > _secondComNumber && _firstComNumber > _thirdComNumber)
	{
		printf("컴퓨터1 승리!!!\n");
	}
	//두 번째 컴퓨터가 승리할 때
	else if (_secondComNumber > _firstComNumber && _secondComNumber > _thirdComNumber)
	{
		printf("컴퓨터2 승리!!!\n");
	}
	//세 번째 컴퓨터가 승리할 때
	else if (_thirdComNumber > _firstComNumber && _thirdComNumber > _secondComNumber)
	{
		printf("컴퓨터3 승리!!!\n");
	}
	//1 == 2 > 3
	else if (_firstComNumber == _secondComNumber && _firstComNumber > _thirdComNumber)
	{
		printf("컴퓨터1, 컴퓨터2 동시승리!!!\n");
	}
	//1 == 3 > 2
	else if (_firstComNumber == _thirdComNumber && _firstComNumber > _secondComNumber)
	{
		printf("컴퓨터1, 컴퓨터3 동시승리!!!\n");
	}
	//2 == 3 > 1
	else if (_secondComNumber == _thirdComNumber && _secondComNumber > _firstComNumber)
	{
		printf("컴퓨터2, 컴퓨터3 동시승리!!!\n");
	}
	//1 == 2 == 3
	else if (_firstComNumber == _secondComNumber && _firstComNumber == _thirdComNumber)
	{
		printf("컴퓨터 1, 2, 3 비김\n");
	}
	else
	{
		printf("!!!오류!!!\n");
	}
}