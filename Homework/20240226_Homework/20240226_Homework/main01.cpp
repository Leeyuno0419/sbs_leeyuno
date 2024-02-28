#include <iostream>

#define arraySize 45

using namespace std;

//1. 로또생성기
// - 1 ~ 45까지 적힌 볼(array)을 만든다.
// - array를 섞는다.
// - 그중 7개를 뽑는다.

int _arrBall[arraySize] = {}; //볼(array)

void InitArray(); //배열 초기화 및 정의
void SwapArray();
void PrintArray();

void main()
{
	srand(time(NULL));
	InitArray();
	SwapArray();
	PrintArray();
}

void InitArray()
{
	for (int i = 0; i < arraySize; i++)
	{
		_arrBall[i] = i+1;
	}
}

void SwapArray()
{
	for (int i = 0; i < 10000; i++)
	{
		int firstIndex = rand() % arraySize;
		int secondIndex = rand() % arraySize;
		int temp = _arrBall[firstIndex];
		_arrBall[firstIndex] = _arrBall[secondIndex];
		_arrBall[secondIndex] = temp;
	}
}

void PrintArray()
{
	for (int i = 0; i < 7; i++)
	{
		printf("Ball[%d] : %d\n", i + 1, _arrBall[i]);
	}
}



