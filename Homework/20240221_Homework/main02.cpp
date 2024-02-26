#include <iostream>
#include <time.h>

using namespace std;

// 2. while문을 활용
// - 숫자맞추기 게임


int _userInput = 0;	//유저입력을 저장할 변수
int _tryNumber = 0; //시도횟수를 저장할 변수

void main()
{
	srand(time(NULL));
	int randomNumber = (rand() % 100) + 1; //1~100 랜덤 숫자 지정


	while (_userInput != randomNumber) //숫자를 맞출 때까지 반복
	{
		printf("숫자 입력: ");
		cin >> _userInput;
		_tryNumber++;
		if (_userInput == randomNumber)
		{
			printf("\n숫자를 맞추셨습니다.\n");
			printf("시도횟수: %d\n", _tryNumber);
			printf("아무숫자 입력(종료): ");
			cin >> _userInput;
			exit(0);
		}
		else if (_userInput > randomNumber) //랜덤숫자가 더 작을 때
		{
			printf("\n▼ DOWN ▼\n");
		}
		else //랜덤숫자가 더 클 때
		{
			printf("\n▲ UP ▲\n");
		}
	}
}