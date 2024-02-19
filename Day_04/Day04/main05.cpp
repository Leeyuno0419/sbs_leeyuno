#include <iostream>
#include <time.h>
using namespace std;

int _myHand = 0;
int _comHand = 0;

void PrintGameStart();
void ChooseMyHand();
void ChooseComHand();
void PrintHands();
void PrintGameResult();

void main() {
	srand(time(NULL));
	::PrintGameStart();
	::ChooseMyHand();
	::ChooseComHand();
	::PrintHands();
	::PrintGameResult();
}

void PrintGameStart(){
	::printf("┌───────────────────────────────────┐\n");
	::printf("│   Rock Scissor Paper GameStart    │\n");
	::printf("└───────────────────────────────────┘\n");
}

void ChooseMyHand() {
	::printf("가위(0), 바위(1), 보(2) 중에 선택해주세요.\n");
	cin >> _myHand;
}

void ChooseComHand() {
	_comHand = rand() % 3;
}

void PrintHands() {
	::printf("내가 고른 손: ");
	switch (_myHand)
	{
	case 0:
		::printf("가위\n");
		break;
	case 1:
		::printf("바위\n");
		break;
	case 2:
		::printf("보\n");
		break;
	default:
		break;
	}
	::printf("컴퓨터가 고른 손: ");
	switch (_comHand)
	{
	case 0:
		::printf("가위\n");
		break;
	case 1:
		::printf("바위\n");
		break;
	case 2:
		::printf("보\n");
		break;
	default:
		break;
	}
}

void PrintGameResult() {
	if (_myHand == _comHand) {
		::printf("비겼습니다.\n");
	}
	else if (_myHand == 0) {
		if (_comHand == 1) {
			::printf("컴퓨터가 이겼습니다.\n");
		}
		if (_comHand == 2) {
			::printf("플레이어가 이겼습니다.\n");
		}
	}
	else if (_myHand == 1) {
		if (_comHand == 2) {
			::printf("컴퓨터가 이겼습니다.\n");
		}
		if (_comHand == 0) {
			::printf("플레이어가 이겼습니다.\n");
		}
	}
	else if (_myHand == 2) {
		if (_comHand == 1) {
			::printf("컴퓨터가 이겼습니다.\n");
		}
		if (_comHand == 0) {
			::printf("플레이어가 이겼습니다.\n");
		}
	}
	else{
		::printf("ERROR\n");
	}
}
