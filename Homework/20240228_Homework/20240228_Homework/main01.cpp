#include <iostream>
#include <time.h>

#define BINGOSIZE 4 //������ ũ�� BINGOSIZE * BINGOSIZE
#define BINGOEND 3 //���� �ϼ����� (��: 3�ϰ�� 3�ٿϼ� �� ����)

using namespace std;

void InitBingo(int bingoBoard[][BINGOSIZE]); //BINGOSIZE*BINGOSIZE ũ���� ������ �ʱ���� �Լ� - (1 ~ BINGOSIZE*BINGOSIZE)
void PrintBingo(int bingoBoard1[][BINGOSIZE], int bingoBoard2[][BINGOSIZE]);//������1, ������2 ��� �Լ�
void SwapBingo(int bingoBoard[][BINGOSIZE], int swapTime);//�������� swapTime��ŭ ���� �Լ�
void SelectBingoNumber(int selectNumber); //������ ���� �Է��Լ�
bool isDuplicate(int number); //�ߺ��� �Է��� Ȯ���ϴ� �Լ� (�ߺ��Է½� true��ȯ, �ߺ��Է��� �ƴ� �� false ��ȯ)
bool isBingo(int bingoBoard1[][BINGOSIZE]); //����ϼ� ���� �޼����� Ȯ���ϴ� �Լ�(�ϼ����� �޼� �� true��ȯ)
void PrintResult(); //���� ���� �� �ڵ� ���

int _bingoPlayer[BINGOSIZE][BINGOSIZE]; //�÷��̾� ������ 2���� �迭 BINGOSIZE * BINGOSIZE
int _bingoCom[BINGOSIZE][BINGOSIZE]; //��ǻ�� ������ 2���� �迭 BINGOSIZE * BINGOSIZE
int _selectedNumber[BINGOSIZE * BINGOSIZE] = {}; //�Էµ� ���ڸ� �����ϴ� ����
int _tryNumber = 0; //�Էµ� ������ Ƚ���� �����ϴ� ����

void main()
{
	int playerInput = 0;

	srand(time(NULL));

	InitBingo(_bingoPlayer);
	InitBingo(_bingoCom);
	SwapBingo(_bingoPlayer, 1000);
	SwapBingo(_bingoCom, 1000);
	while (!isBingo(_bingoPlayer) && !isBingo(_bingoCom)) //���߿� �Ѹ��̶� �ϼ����� �޼� �� �׸� �մϴ�.
	{
		PrintBingo(_bingoPlayer, _bingoCom);
		printf("���ڸ� �Է�: ");
		cin >> playerInput;
		SelectBingoNumber(playerInput);
		PrintBingo(_bingoPlayer, _bingoCom);
		PrintResult();
		printf("��ǻ�� ��\n");
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
	printf("���������������������������������������������������������������������������������������������������\n\n");
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
	printf("\n���������������������������������������������������������������������������������������������������\n");
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
	printf("�Էµ� ����: %d\n", selectNumber);
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
		printf("�ߺ��� ���ڸ� �Է��Ͽ����ϴ�. ���� �Ѿ�ϴ�.\n");
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

	//���� üũ
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
	//����üũ
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
	//�밢��üũ
	//���� ��ܿ��� ������ �ϴ����� üũ
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
	//������ ��ܿ��� ���� �ϴ����� üũ
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
	//�ϼ� ���� �޼� Ȯ��
	if (completedNumber >= BINGOEND)//�ϼ����� �޼� �� true ��ȯ
	{
		complet = true;
		return complet;
	}
	else//�ϼ����� �̴޼� �� false ��ȯ
	{
		return complet;
	}
}

void PrintResult()
{
	if (isBingo(_bingoPlayer))
	{
		PrintBingo(_bingoPlayer, _bingoCom);
		printf("�÷��̾ ���� %d���� �ϼ��Ͽ����ϴ�.\n- �� -", BINGOEND);
	}
	if (isBingo(_bingoCom))
	{
		PrintBingo(_bingoPlayer, _bingoCom);
		printf("��ǻ�Ͱ� ���� %d���� �ϼ��Ͽ����ϴ�.\n- �� -", BINGOEND);
	}
}