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
	::printf("��������������������������������������������������������������������������\n");
	::printf("��   Rock Scissor Paper GameStart    ��\n");
	::printf("��������������������������������������������������������������������������\n");
}

void ChooseMyHand() {
	::printf("����(0), ����(1), ��(2) �߿� �������ּ���.\n");
	cin >> _myHand;
}

void ChooseComHand() {
	_comHand = rand() % 3;
}

void PrintHands() {
	::printf("���� �� ��: ");
	switch (_myHand)
	{
	case 0:
		::printf("����\n");
		break;
	case 1:
		::printf("����\n");
		break;
	case 2:
		::printf("��\n");
		break;
	default:
		break;
	}
	::printf("��ǻ�Ͱ� �� ��: ");
	switch (_comHand)
	{
	case 0:
		::printf("����\n");
		break;
	case 1:
		::printf("����\n");
		break;
	case 2:
		::printf("��\n");
		break;
	default:
		break;
	}
}

void PrintGameResult() {
	if (_myHand == _comHand) {
		::printf("�����ϴ�.\n");
	}
	else if (_myHand == 0) {
		if (_comHand == 1) {
			::printf("��ǻ�Ͱ� �̰���ϴ�.\n");
		}
		if (_comHand == 2) {
			::printf("�÷��̾ �̰���ϴ�.\n");
		}
	}
	else if (_myHand == 1) {
		if (_comHand == 2) {
			::printf("��ǻ�Ͱ� �̰���ϴ�.\n");
		}
		if (_comHand == 0) {
			::printf("�÷��̾ �̰���ϴ�.\n");
		}
	}
	else if (_myHand == 2) {
		if (_comHand == 1) {
			::printf("��ǻ�Ͱ� �̰���ϴ�.\n");
		}
		if (_comHand == 0) {
			::printf("�÷��̾ �̰���ϴ�.\n");
		}
	}
	else
		::printf("ERROR\n");
}
