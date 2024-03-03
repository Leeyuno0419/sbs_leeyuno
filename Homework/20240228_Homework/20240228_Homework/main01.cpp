//빙고게임(Player vs Com)
// 5*5빙고판을 만들어주고
// 1~25까지 랜덤한 숫자가 적혀있음
// 내가 숫자를 입력시
// 내빙고판 한개 상대 빙고판 한개 지워짐
// 그다음 상대가 랜덤숫자 입력
// 그때 상대빙고판 내빙고판 한개 지워짐
// 3줄이 빙고가 되면 해당 유저승리

#include <iostream>

#define BINGOSIZE 5

using namespace std;

void MakeBingoPlayer();
void MakeBingoCom();
void SwapBingo(int swapint[][BINGOSIZE], int swapNumber);
void PrintBingoPlayer();
void PrintBingoCom();

int _bingoPlayer[BINGOSIZE][BINGOSIZE];
int _bingoCom[BINGOSIZE][BINGOSIZE];

void main()
{
	srand(time(NULL));
	MakeBingoPlayer();
	MakeBingoCom();
	SwapBingo(_bingoPlayer[BINGOSIZE][BINGOSIZE], 3333);
	PrintBingoPlayer();
	PrintBingoCom();
}

void MakeBingoPlayer()
{
	//1~25까지 빙고판 넣어주기
	int temp = 1;
	for (int i = 0; i < BINGOSIZE; i++)
	{
		for (int j = 0; j < BINGOSIZE; j++)
		{
			_bingoPlayer[i][j] = temp++;
		}
	}
}

void MakeBingoCom()
{
	//1~25까지 빙고판 넣어주기
	int temp = 1;
	for (int i = 0; i < BINGOSIZE; i++)
	{
		for (int j = 0; j < BINGOSIZE; j++)
		{
			_bingoCom[i][j] = temp++;
		}
	}
}

void SwapBingo(int swapint[][BINGOSIZE], int swapNumber)
{
	int temp = 0;

	for (int i = 0; i < swapNumber; i++)
	{
		int randomNum1 = rand() % BINGOSIZE;
		int randomNum2 = rand() % BINGOSIZE;
		temp = swapint[randomNum1][randomNum2];
		swapint[randomNum1][randomNum2] = swapint[randomNum2][randomNum1];
		swapint[randomNum2][randomNum1] = temp;
	}
}

void PrintBingoPlayer()
{
	printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n\t\t      PLAYER\n");
	for (int i = 0; i < BINGOSIZE; i++)
	{
		
		for (int j = 0; j < BINGOSIZE; j++)
		{
			printf("\t%d ", _bingoPlayer[i][j]);
		}
		printf("\n");
	}
	printf("\n■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
}

void PrintBingoCom()
{
	printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n\t\t     COMPUTER\n");
	for (int i = 0; i < BINGOSIZE; i++)
	{

		for (int j = 0; j < BINGOSIZE; j++)
		{
			printf("\t%d ", _bingoCom[i][j]);
		}
		printf("\n");
	}
	printf("\n■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
}