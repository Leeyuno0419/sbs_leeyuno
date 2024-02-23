#include <iostream>
#include <time.h>

using namespace std;

// 3. 가위바위보 만든거
// 내가 5승할때까지 반복

// 4. 가위바위보 만든거
// 10번 반복

// (심화)5. 3-4 합친 모드.
// 1. 게임시작하면 게임모드 정하기 (승수로할지, 판수로할지)

int _userInput = 0; //유저입력을 저장할 변수
int _userHand = 0; //유저 가위바위보를 저장할 변수
int _comHand = 0; //컴퓨터 가위바위보를 저장할 변수
int _tryNumber = 0; //시도횟수를 저장할 변수
int _winNumber = 0; //승리횟수를 저장할 변수
int _loseNumber = 0; //패배횟수를 저장할 변수
int _drawNumber = 0; //무승부횟수를 저장할 변수

enum eRSP
{
	ROCK,
	SCISSOR,
	PAPER
};

void SelectGame(); //게임선택 함수
void PlayWinFiveTimesGame(); //5번 이길 떄까지 반복모드 함수
void PlayRepeatTenTimesGame(); //10번 반복모드 함수
void RockScissorPaperGame(); //가위바위보게임 함수
void PrintResult(); //가위바위보 결과 출력 및 처리 함수

void main()
{
	srand(time(NULL));
	SelectGame();
}

void SelectGame()
{
	printf("┌───────────────────────────────┐\n");
	printf("│    ROCK SCISSOR PAPER GAME    │\n");
	printf("└───────────────────────────────┘\n");
	printf("게임모드 선택\n");
	printf("1. 5번 이길 때까지 반복\n");
	printf("2. 10번 반복\n");
	printf("게임모드 입력(1 OR 2): ");
	cin >> _userInput;
	while (_userInput != 1 && _userInput != 2) //1, 2중에 하나만 입력하도록 설정
	{
		printf("1과 2중에 선택하여 입력해주세요.\n");
		printf("게임모드 입력(1 OR 2): ");
		cin >> _userInput;
	}
	if (_userInput == 1) //게임모드 1번 - 5번이길 때까지 반복모드
	{
		PlayWinFiveTimesGame();
	}
	else if (_userInput == 2) //게임모드 2번 - 10번 반복모드
	{
		PlayRepeatTenTimesGame();
	}
}

void PlayWinFiveTimesGame() //게임모드 1번 - 5번 이길 때까지 반복모드
{
	while (_winNumber < 5) //5번 이길 때까지 반복
	{
		system("cls"); //콘솔창 초기화
		printf("┌───────────────────────────────┐\n");
		printf("│    ROCK SCISSOR PAPER GAME    │\n");
		printf("└───────────────────────────────┘\n");
		printf("게임모드 - 5번이길 때까지 반복모드\n");
		printf("현재 승리횟수: %d, 패배횟수: %d\n", _winNumber, _loseNumber);
		printf("현재 무승부횟수: %d, 반복횟수: %d\n", _drawNumber, _tryNumber);
		RockScissorPaperGame();
	}
	system("cls"); //콘솔창 초기화
	printf("┌─────────────────────────────────┐\n");
	printf("│    ROCK SCISSOR PAPER Result    │\n");
	printf("└─────────────────────────────────┘\n");
	printf("게임모드 - 5번이길 때까지 반복모드\n");
	printf("현재 승리횟수: %d, 패배횟수: %d\n", _winNumber, _loseNumber);
	printf("현재 무승부횟수: %d, 반복횟수: %d\n", _drawNumber, _tryNumber);
}

void PlayRepeatTenTimesGame() //게임모드 2번 - 10번 반복모드
{
	while (_tryNumber < 10) //10번 반복할 때까지 반복
	{
		system("cls"); //콘솔창 초기화
		printf("┌───────────────────────────────┐\n");
		printf("│    ROCK SCISSOR PAPER GAME    │\n");
		printf("└───────────────────────────────┘\n");
		printf("게임모드 - 10번 반복모드\n");
		printf("현재 승리횟수: %d, 패배횟수: %d\n", _winNumber, _loseNumber);
		printf("현재 무승부횟수: %d, 반복횟수: %d\n", _drawNumber, _tryNumber);
		RockScissorPaperGame(); //게임실행
	}
	system("cls"); //콘솔창 초기화
	printf("┌─────────────────────────────────┐\n");
	printf("│    ROCK SCISSOR PAPER Result    │\n");
	printf("└─────────────────────────────────┘\n");
	printf("게임모드 - 10번 반복모드\n");
	printf("현재 승리횟수: %d, 패배횟수: %d\n", _winNumber, _loseNumber);
	printf("현재 무승부횟수: %d, 반복횟수: %d\n", _drawNumber, _tryNumber);
}

void RockScissorPaperGame() //가위바위보게임 실행
{
	printf("바위(0), 가위(1), 보(2) 입력: ");
	cin >> _userHand;
	while (_userHand != 0 && _userHand != 1 && _userHand != 2) //0, 1, 2중에 하나만 입력하도록 설정
	{
		printf("0, 1, 2중에 선택하여 입력해주세요.\n");
		printf("바위(0), 가위(1), 보(2) 입력: ");
		cin >> _userHand;
	}
	_comHand = rand() % 3;
	PrintResult();
}

void PrintResult() //결과 출력 및 처리
{
	++_tryNumber; //시도횟수 +1;
	//일단 무엇을 냈는지 출력
	if (_userHand == ROCK)
	{
		printf("플레이어: 바위\n");
	}
	else if (_userHand == SCISSOR)
	{
		printf("플레이어: 가위\n");
	}
	else if (_userHand == PAPER)
	{
		printf("플레이어: 보\n");
	}
	if (_comHand == ROCK)
	{
		printf("컴퓨터: 바위\n");
	}
	else if (_comHand == SCISSOR)
	{
		printf("컴퓨터: 가위\n");
	}
	else if (_comHand == PAPER)
	{
		printf("컴퓨터: 보\n");
	}
	//결과 출력 및 처리
	if (_userHand == _comHand)
	{
		_drawNumber++; //무승부횟수 +1
		printf("비겼습니다.\n");
	}
	else if ((_userHand == ROCK && _comHand == SCISSOR) ||
		(_userHand == SCISSOR && _comHand == PAPER) ||
		(_userHand == PAPER && _comHand == ROCK)) //플레이어가 이겼을 때
	{ 
		_winNumber++; //승리횟수 +1
		printf("이겼습니다.\n");
	}
	else if ((_comHand == ROCK && _userHand == SCISSOR) ||
		(_comHand == SCISSOR && _userHand == PAPER) ||
		(_comHand == PAPER && _userHand == ROCK)) //컴퓨터가 이겼을 때
	{
		_loseNumber++; //패배횟수 +1
		printf("졌습니다.\n");
	}
	printf("아무숫자 입력(다음 턴): ");
	cin >> _userInput;
}
