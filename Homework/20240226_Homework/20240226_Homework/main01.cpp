#include <iostream>

#define arraySize 45

using namespace std;

//1. �ζǻ�����
// - 1 ~ 45���� ���� ��(array)�� �����.
// - array�� ���´�.
// - ���� 7���� �̴´�.

int _arrBall[arraySize] = {}; //��(array)

void InitArray(); //�迭 �ʱ�ȭ �� ����
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



