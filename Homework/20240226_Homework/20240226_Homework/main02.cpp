#include <iostream>
#include <time.h>

using namespace std;

enum e_RSP
{
	ROCK_RSP,
	SCISSOR_RSP,
	PAPER_RSP,
	END_RSP
};

enum e_Hand
{
	LEFT_Hand,
	RIGHT_Hand,
	END_Hand
};

int _arrMyHand[2] = {};
int _arrComHand[2] = {};
int _takedMyHand = 0;
int _takedComHand = 0;

//2. 가위바위보 하나빼기(배열사용)

void SelectMyRSP();
void SelectComRSP();
void PrintHand();
void TakeOneMyHand();
void TakeOneComHand();
void PrintResult();

void main()
{
	srand(time(NULL));
	SelectMyRSP();
	SelectComRSP();
	PrintHand();
	TakeOneMyHand();
	TakeOneComHand();
	PrintResult();
}

void SelectMyRSP()
{
	printf("┌───────────────────────────────┐\n");
	printf("│    ROCK SCISSOR PAPER GAME    │\n");
	printf("└───────────────────────────────┘\n");
	for (int i = 0; i < END_Hand; i++) // 왼손, 오른손 지정을 위해 2번 반복
	{
		printf("%d 번째 - 바위(0), 가위(1), 보(2) 입력: ", i);
		cin >> _arrMyHand[i];
		while (_arrMyHand[i] != ROCK_RSP && _arrMyHand[i] != SCISSOR_RSP && _arrMyHand[i] != PAPER_RSP) //0, 1, 2중에 하나만 입력하도록 설정
		{
			printf("0, 1, 2중에 선택하여 입력해주세요.\n");
			printf("바위(0), 가위(1), 보(2) 입력: ");
			cin >> _arrMyHand[i];
		}
	}
}

void SelectComRSP()
{
	_arrComHand[LEFT_Hand] = rand() % END_RSP; //컴퓨터 왼손 지정
	_arrComHand[RIGHT_Hand] = rand() % END_RSP; //컴퓨터 오른손손 지정
}

void PrintHand()
{
	system("cls");
	printf("┌───────────────────────────────┐\n");
	printf("│    ROCK SCISSOR PAPER GAME    │\n");
	printf("└───────────────────────────────┘\n");
	//플레이어
	if (_arrMyHand[LEFT_Hand] == ROCK_RSP)
	{
		printf("플레이어의 왼손: 바위\n");
	}
	else if (_arrMyHand[LEFT_Hand] == SCISSOR_RSP)
	{
		printf("플레이어의 왼손: 가위\n");
	}
	else
	{
		printf("플레이어의 왼손: 보\n");
	}
	if (_arrMyHand[RIGHT_Hand] == ROCK_RSP)
	{
		printf("플레이어의 오른손: 바위\n");
	}
	else if (_arrMyHand[RIGHT_Hand] == SCISSOR_RSP)
	{
		printf("플레이어의 오른손: 가위\n");
	}
	else
	{
		printf("플레이어의 오른손: 보\n");
	}
	//컴퓨터
	if (_arrComHand[LEFT_Hand] == ROCK_RSP)
	{
		printf("컴퓨터의 왼손: 바위\n");
	}
	else if (_arrComHand[LEFT_Hand] == SCISSOR_RSP)
	{
		printf("컴퓨터의 왼손: 가위\n");
	}
	else
	{
		printf("컴퓨터의 왼손: 보\n");
	}
	if (_arrComHand[RIGHT_Hand] == ROCK_RSP)
	{
		printf("컴퓨터의 오른손: 바위\n");
	}
	else if (_arrComHand[RIGHT_Hand] == SCISSOR_RSP)
	{
		printf("컴퓨터의 오른손: 가위\n");
	}
	else
	{
		printf("컴퓨터의 오른손: 보\n");
	}
}

void TakeOneMyHand()
{
	printf("빼기를 할 손 선택(왼손(0), 오른손(1)) 입력: ");
	cin >> _takedMyHand;
}

void TakeOneComHand()
{
	_takedComHand = rand() % END_Hand;
}

void PrintResult()
{
	printf("플레이어가 뺀 손 - ");
	if (_takedMyHand == LEFT_Hand)
	{
		printf("왼손\n");
	}
	else
	{
		printf("오른손\n");
	}
	printf("컴퓨터가 뺀 손 - ");
	if (_takedComHand == LEFT_Hand)
	{
		printf("왼손\n");
	}
	else
	{
		printf("오른손\n");
	}
	if (_takedMyHand == LEFT_Hand)
	{
		//플레이어: 오른손, 컴퓨터: 오른손 
		if (_takedComHand == LEFT_Hand)
		{
			if ((_arrMyHand[RIGHT_Hand] == ROCK_RSP && _arrComHand[RIGHT_Hand] == SCISSOR_RSP) ||
				(_arrMyHand[RIGHT_Hand] == SCISSOR_RSP && _arrComHand[RIGHT_Hand] == PAPER_RSP) ||
				(_arrMyHand[RIGHT_Hand] == PAPER_RSP && _arrComHand[RIGHT_Hand] == ROCK_RSP))
			{
				printf("이겼습니다.\n");
			}
			else if ((_arrMyHand[RIGHT_Hand] == ROCK_RSP && _arrComHand[RIGHT_Hand] == PAPER_RSP) ||
				(_arrMyHand[RIGHT_Hand] == SCISSOR_RSP && _arrComHand[RIGHT_Hand] == ROCK_RSP) ||
				(_arrMyHand[RIGHT_Hand] == PAPER_RSP && _arrComHand[RIGHT_Hand] == SCISSOR_RSP))
			{
				printf("졌습니다.\n");
			}
			else
			{
				printf("비겼습니다.\n");
			}
		}
		//플레이어: 오른손, 컴퓨터: 왼손 
		else
		{
			if ((_arrMyHand[RIGHT_Hand] == ROCK_RSP && _arrComHand[LEFT_Hand] == SCISSOR_RSP) ||
				(_arrMyHand[RIGHT_Hand] == SCISSOR_RSP && _arrComHand[LEFT_Hand] == PAPER_RSP) ||
				(_arrMyHand[RIGHT_Hand] == PAPER_RSP && _arrComHand[LEFT_Hand] == ROCK_RSP))
			{
				printf("이겼습니다.\n");
			}
			else if ((_arrMyHand[RIGHT_Hand] == ROCK_RSP && _arrComHand[LEFT_Hand] == PAPER_RSP) ||
				(_arrMyHand[RIGHT_Hand] == SCISSOR_RSP && _arrComHand[LEFT_Hand] == ROCK_RSP) ||
				(_arrMyHand[RIGHT_Hand] == PAPER_RSP && _arrComHand[LEFT_Hand] == SCISSOR_RSP))
			{
				printf("졌습니다.\n");
			}
			else
			{
				printf("비겼습니다.\n");
			}
		}
	}
	else
	{
		//플레이어: 왼손, 컴퓨터: 오른손 
		if (_takedComHand == LEFT_Hand)
		{
			if ((_arrMyHand[LEFT_Hand] == ROCK_RSP && _arrComHand[RIGHT_Hand] == SCISSOR_RSP) ||
				(_arrMyHand[LEFT_Hand] == SCISSOR_RSP && _arrComHand[RIGHT_Hand] == PAPER_RSP) ||
				(_arrMyHand[LEFT_Hand] == PAPER_RSP && _arrComHand[RIGHT_Hand] == ROCK_RSP))
			{
				printf("이겼습니다.\n");
			}
			else if ((_arrMyHand[LEFT_Hand] == ROCK_RSP && _arrComHand[RIGHT_Hand] == PAPER_RSP) ||
				(_arrMyHand[LEFT_Hand] == SCISSOR_RSP && _arrComHand[RIGHT_Hand] == ROCK_RSP) ||
				(_arrMyHand[LEFT_Hand] == PAPER_RSP && _arrComHand[RIGHT_Hand] == SCISSOR_RSP))
			{
				printf("졌습니다.\n");
			}
			else
			{
				printf("비겼습니다.\n");
			}
		}
		//플레이어: 왼손, 컴퓨터: 왼손 
		else
		{
			if ((_arrMyHand[LEFT_Hand] == ROCK_RSP && _arrComHand[LEFT_Hand] == SCISSOR_RSP) ||
				(_arrMyHand[LEFT_Hand] == SCISSOR_RSP && _arrComHand[LEFT_Hand] == PAPER_RSP) ||
				(_arrMyHand[LEFT_Hand] == PAPER_RSP && _arrComHand[LEFT_Hand] == ROCK_RSP))
			{
				printf("이겼습니다.\n");
			}
			else if ((_arrMyHand[LEFT_Hand] == ROCK_RSP && _arrComHand[LEFT_Hand] == PAPER_RSP) ||
				(_arrMyHand[LEFT_Hand] == SCISSOR_RSP && _arrComHand[LEFT_Hand] == ROCK_RSP) ||
				(_arrMyHand[LEFT_Hand] == PAPER_RSP && _arrComHand[LEFT_Hand] == SCISSOR_RSP))
			{
				printf("졌습니다.\n");
			}
			else
			{
				printf("비겼습니다.\n");
			}
		}
	}
}
