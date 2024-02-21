#include <iostream>
#include <time.h>
using namespace std;

enum eMyHand {
	Rock,
	Scissor,
	Paper
};

//변수 선언하는 곳
int _temp = 0;
int _myHand = 0;
int _comHand = 0;

//함수 선언하는 곳
void PrintGameStartMessage()
{
	printf("┌─────────────────────────────────────────┐\n");
	printf("│             Game Start!                 │\n");
	printf("│           Rock Scissor Paper!           │\n");
	printf("└─────────────────────────────────────────┘\n");
}

void ChooseMyHand()
{
	printf("┌─────────────────────────────────────────┐\n");
	printf("│  Choose My Hand!                        │\n");
	printf("│   Rock(0) Scissor(1) Paper(2)           │\n");
	printf("└─────────────────────────────────────────┘\n");
	cin >> _myHand;
}

void ChooseComHand()
{
	_comHand = rand() % 3;	// 0 ~ 2 사이의 랜덤을 정하기 위해서
}

void PrintHands()
{
	cout << "myHand : " << _myHand << endl;
	cout << "_comHand : " << _comHand << endl;

	cout << "내가 낸 것 : ";
	switch (_myHand)
	{
	case Rock:
		cout << "바위" << endl;
		break;
	case Scissor:
		cout << "가위" << endl;
		break;
	case Paper:
		cout << "보" << endl;
		break;
	default:
		cout << "[시스템 에러 : -10001] 잘못된 값입니다." << endl;
		break;
	}

	cout << "상대가 낸 것 : ";
	switch (_comHand)
	{
	case Rock:
		cout << "바위" << endl;
		break;
	case Scissor:
		cout << "가위" << endl;
		break;
	case Paper:
		cout << "보" << endl;
		break;
	default:
		cout << "[시스템 에러 : -10001] 잘못된 값입니다." << endl;
		break;
	}
}

void PrintDrawMessage()
{
	printf("┌─────────────────────────────────────────┐\n");
	printf("│  Draw !!!!!!!!!!                        │\n");
	printf("└─────────────────────────────────────────┘\n");
}

void PrintLoseMessage()
{
	printf("┌─────────────────────────────────────────┐\n");
	printf("│  Lose !!!!!!!!!!                        │\n");
	printf("└─────────────────────────────────────────┘\n");
}

void PrintWinMessage()
{
	printf("┌─────────────────────────────────────────┐\n");
	printf("│  WIN!!!!!!!!!!!!                        │\n");
	printf("└─────────────────────────────────────────┘\n");
}

void PrintGameResultMessage()
{
	// - 비겼으면 
	//		- 비겼습니다를 출력한다.
	// - 이겼으면
	//		- 이겼습니다를 출력한다.
	// - 졌으면
	//		- 졌습니다를 출력한다.

	// 대부분의 기획서 내용은 
	// 말 그대로 코드로 변환
	// 컨텐츠코드에서는 더더욱!!
	//		=> 컨텐츠코드에서 제일 중요한건 생산성
	//			=> 생산성 : 코드가독성 + 유지보수성

	//비겼으면
	if (_comHand == _myHand)
	{
		::PrintDrawMessage();
	}
	//졌으면
	else if ((_comHand == Rock && _myHand == Scissor) ||
		(_comHand == Scissor && _myHand == Paper) ||
		(_comHand == Paper && _myHand == Rock))
	{
		::PrintLoseMessage();
	}
	//이겼으면
	else
	{
		::PrintWinMessage();
	}
}

void main()
{
	//숙제풀이.
	//1. 가위바위보
	// - 게임 시작 메시지를 출력한다.
	//  PrintGameStartMessage()
	// - 내가 낼것을 정한다
	//  ChooseMyHand();
	// - 컴퓨터가 낼것을 정한다.
	//  ChooseComHand();
	// - 내가 낸것과 컴퓨터가 낸것을 출력한다.
	//  PrintHands();
	//  PrintGameResultMessage();

	srand(time(NULL));

	::PrintGameStartMessage();
	::ChooseMyHand();
	::ChooseComHand();
	::PrintHands();
	::PrintGameResultMessage();

}