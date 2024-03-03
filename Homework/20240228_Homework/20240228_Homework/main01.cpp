#include <iostream>
#include <time.h>

#define BINGOSIZE 4 //빙고판 크기 BINGOSIZE * BINGOSIZE
#define BINGOEND 3 //빙고 완성조건 (예: 3일경우 3줄완성 시 끝남)

using namespace std;

void InitBingo(int bingoBoard[][BINGOSIZE]); //BINGOSIZE*BINGOSIZE 크기의 빙고판 초기생성 함수 - (1 ~ BINGOSIZE*BINGOSIZE)
void PrintBingo(int bingoBoard1[][BINGOSIZE], int bingoBoard2[][BINGOSIZE]);//빙고판1, 빙고판2 출력 함수
void SwapBingo(int bingoBoard[][BINGOSIZE], int swapTime);//빙고판을 swapTime만큼 섞는 함수
void SelectBingoNumber(int selectNumber); //빙고판 숫자 입력함수
bool isDuplicate(int number); //중복된 입력을 확인하는 함수 (중복입력시 true반환, 중복입력이 아닐 시 false 반환)
bool isBingo(int bingoBoard1[][BINGOSIZE]); //빙고완성 조건 달성조건 확인하는 함수(완성조건 달성 시 true반환)
void PrintResult(); //빙고가 끝날 시 자동 출력

int _bingoPlayer[BINGOSIZE][BINGOSIZE]; //플레이어 빙고판 2차원 배열 BINGOSIZE * BINGOSIZE
int _bingoCom[BINGOSIZE][BINGOSIZE]; //컴퓨터 빙고판 2차원 배열 BINGOSIZE * BINGOSIZE
int _selectedNumber[BINGOSIZE * BINGOSIZE] = {}; //입력된 숫자를 저장하는 변수
int _tryNumber = 0; //입력된 숫자의 횟수를 저장하는 변수

void main()
{
	int playerInput = 0;

	srand(time(NULL));

	InitBingo(_bingoPlayer);
	InitBingo(_bingoCom);
	SwapBingo(_bingoPlayer, 1000);
	SwapBingo(_bingoCom, 1000);
	while (!isBingo(_bingoPlayer) && !isBingo(_bingoCom)) //둘중에 한명이라도 완성조건 달성 시 그만 합니다.
	{
		PrintBingo(_bingoPlayer, _bingoCom);
		printf("숫자를 입력: ");
		cin >> playerInput;
		SelectBingoNumber(playerInput);
		PrintBingo(_bingoPlayer, _bingoCom);
		PrintResult();
		printf("컴퓨터 턴\n");
		system("pause");
		SelectBingoNumber(rand()% (BINGOSIZE * BINGOSIZE) + 1);
		PrintResult();
	}
}

void InitBingo(int bingoBoard[][BINGOSIZE])
{
	int temp = 0;
	for (int i = 0; i < BINGOSIZE; i++)
	{
		for (int j = 0; j < BINGOSIZE; j++)
		{
			bingoBoard[i][j] = ++temp;
		}
	}
}

void PrintBingo(int bingoBoard1[][BINGOSIZE], int bingoBoard2[][BINGOSIZE])
{
	printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n\n");
	printf("\tPLAYER");
	for (int i = 0; i < BINGOSIZE; i++)
	{
		printf("\t");
	}
	printf("\tCOMPUTER\n");
	for (int i = 0; i < BINGOSIZE; i++)
	{
		for (int j = 0; j < BINGOSIZE; j++)
		{
			printf("\t%d ", bingoBoard1[i][j]);
		}
		printf("\t|");
		for (int j = 0; j < BINGOSIZE; j++)
		{
			printf("\t%d ", bingoBoard2[i][j]);
		}
		printf("\n");
	}
	printf("\n■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
}

void SwapBingo(int bingoBoard[][BINGOSIZE], int swapTime)
{
	int randomNum1, randomNum2, randomNum3, randomNum4, temp;
	for (int i = 0; i < swapTime; i++)
	{
		randomNum1 = rand() % BINGOSIZE;
		randomNum2 = rand() % BINGOSIZE;
		randomNum3 = rand() % BINGOSIZE;
		randomNum4 = rand() % BINGOSIZE;
		temp = bingoBoard[randomNum1][randomNum2];
		bingoBoard[randomNum1][randomNum2] = bingoBoard[randomNum3][randomNum4];
		bingoBoard[randomNum3][randomNum4] = temp;
	}
}

void SelectBingoNumber(int selectNumber)
{
	printf("입력된 숫자: %d\n", selectNumber);
	if(!isDuplicate(selectNumber))
	{
		for (int i = 0; i < BINGOSIZE; i++)
		{
			for (int j = 0; j < BINGOSIZE; j++)
			{
				if (_bingoPlayer[i][j] == selectNumber)
				{
					_bingoPlayer[i][j] = 0;
					_selectedNumber[_tryNumber++] = selectNumber;
				}
				if (_bingoCom[i][j] == selectNumber)
				{
					_bingoCom[i][j] = 0;
					_selectedNumber[_tryNumber++] = selectNumber;
				}
			}
		}
	}
	else
	{
		printf("중복된 숫자를 입력하였습니다. 턴이 넘어갑니다.\n");
	}
}

bool isDuplicate(int selectNumber)
{
	for (int i = 0; i < BINGOSIZE * BINGOSIZE; i++)
	{
		if(_selectedNumber[i] == selectNumber)
		{
			return true;
		}
	}
	return false;
}

bool isBingo(int bingoBoard[][BINGOSIZE])
{
	bool complet = false;
	int completedNumber = 0;

	//가로 체크
	for (int i = 0; i < BINGOSIZE; i++)
	{
		bool bingo = true;
		for (int j = 0; j < BINGOSIZE; j++)
		{
			if (bingoBoard[i][j] != 0)
			{
				bingo = false;
				break;
			}
		}
		if (bingo)
		{
			completedNumber++;
		}
	}
	//세로체크
	for (int i = 0; i < BINGOSIZE; i++)
	{
		bool bingo = true;
		for (int j = 0; j < BINGOSIZE; j++)
		{
			if (bingoBoard[j][i] != 0)
			{
				bingo = false;
				break;
			}
		}
		if (bingo)
		{
			completedNumber++;
		}
	}
	//대각선체크
	//왼쪽 상단에서 오른쪽 하단으로 체크
	bool leftDiagBingo = true;
	for (int i = 0; i < BINGOSIZE; i++)
	{
		if (bingoBoard[i][i] != 0)
		{
			leftDiagBingo = false;
			break;
		}
	}
	if (leftDiagBingo)
	{
		completedNumber++;
	}
	//오른쪽 상단에서 왼쪽 하단으로 체크
	bool RightDiagBingo = true;
	for (int i = 0; i < BINGOSIZE; i++)
	{
		if (bingoBoard[i][BINGOSIZE - i - 1] != 0)
		{
			RightDiagBingo = false;
			break;
		}
	}
	if (RightDiagBingo)
	{
		completedNumber++;
	}
	//완성 조건 달성 확인
	if (completedNumber >= BINGOEND)//완성조건 달성 시 true 반환
	{
		complet = true;
		return complet;
	}
	else//완성조건 미달성 시 false 반환
	{
		return complet;
	}
}

void PrintResult()
{
	if (isBingo(_bingoPlayer))
	{
		PrintBingo(_bingoPlayer, _bingoCom);
		printf("플레이어가 빙고 %d줄을 완성하였습니다.\n- 끝 -", BINGOEND);
	}
	if (isBingo(_bingoCom))
	{
		PrintBingo(_bingoPlayer, _bingoCom);
		printf("컴퓨터가 빙고 %d줄을 완성하였습니다.\n- 끝 -", BINGOEND);
	}
}