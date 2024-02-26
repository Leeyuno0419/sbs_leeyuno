#include <iostream>
#include <time.h>

using namespace std;

// 3. ���������� �����
// ���� 5���Ҷ����� �ݺ�

// 4. ���������� �����
// 10�� �ݺ�

// (��ȭ)5. 3-4 ��ģ ���.
// 1. ���ӽ����ϸ� ���Ӹ�� ���ϱ� (�¼�������, �Ǽ�������)

int _userInput = 0; //�����Է��� ������ ����
int _userHand = 0; //���� ������������ ������ ����
int _comHand = 0; //��ǻ�� ������������ ������ ����
int _tryNumber = 0; //�õ�Ƚ���� ������ ����
int _winNumber = 0; //�¸�Ƚ���� ������ ����
int _loseNumber = 0; //�й�Ƚ���� ������ ����
int _drawNumber = 0; //���º�Ƚ���� ������ ����

enum eRSP
{
	ROCK,
	SCISSOR,
	PAPER
};

void SelectGame(); //���Ӽ��� �Լ�
void PlayWinFiveTimesGame(); //5�� �̱� ������ �ݺ���� �Լ�
void PlayRepeatTenTimesGame(); //10�� �ݺ���� �Լ�
void PlayRockScissorPaperGame(); //�������������� �Լ�
void PrintResult(); //���������� ��� ��� �� ó�� �Լ�

void main()
{
	srand(time(NULL));
	SelectGame();
}

void SelectGame()
{
	printf("������������������������������������������������������������������\n");
	printf("��    ROCK SCISSOR PAPER GAME    ��\n");
	printf("������������������������������������������������������������������\n");
	printf("���Ӹ�� ����\n");
	printf("1. 5�� �̱� ������ �ݺ�\n");
	printf("2. 10�� �ݺ�\n");
	printf("���Ӹ�� �Է�(1 OR 2): ");
	cin >> _userInput;
	while (_userInput != 1 && _userInput != 2) //1, 2�߿� �ϳ��� �Է��ϵ��� ����
	{
		printf("1�� 2�߿� �����Ͽ� �Է����ּ���.\n");
		printf("���Ӹ�� �Է�(1 OR 2): ");
		cin >> _userInput;
	}
	if (_userInput == 1) //���Ӹ�� 1�� - 5���̱� ������ �ݺ����
	{
		PlayWinFiveTimesGame();
	}
	else if (_userInput == 2) //���Ӹ�� 2�� - 10�� �ݺ����
	{
		PlayRepeatTenTimesGame();
	}
}

void PlayWinFiveTimesGame() //���Ӹ�� 1�� - 5�� �̱� ������ �ݺ����
{
	while (_winNumber < 5) //5�� �̱� ������ �ݺ�
	{
		system("cls"); //�ܼ�â �ʱ�ȭ
		printf("������������������������������������������������������������������\n");
		printf("��    ROCK SCISSOR PAPER GAME    ��\n");
		printf("������������������������������������������������������������������\n");
		printf("���Ӹ�� - 5���̱� ������ �ݺ����\n");
		printf("���� �¸�Ƚ��: %d, �й�Ƚ��: %d\n", _winNumber, _loseNumber);
		printf("���� ���º�Ƚ��: %d, �ݺ�Ƚ��: %d\n", _drawNumber, _tryNumber);
		PlayRockScissorPaperGame();
	}
	system("cls"); //�ܼ�â �ʱ�ȭ
	printf("����������������������������������������������������������������������\n");
	printf("��    ROCK SCISSOR PAPER Result    ��\n");
	printf("����������������������������������������������������������������������\n");
	printf("���Ӹ�� - 5���̱� ������ �ݺ����\n");
	printf("���� �¸�Ƚ��: %d, �й�Ƚ��: %d\n", _winNumber, _loseNumber);
	printf("���� ���º�Ƚ��: %d, �ݺ�Ƚ��: %d\n", _drawNumber, _tryNumber);
}

void PlayRepeatTenTimesGame() //���Ӹ�� 2�� - 10�� �ݺ����
{
	while (_tryNumber < 10) //10�� �ݺ��� ������ �ݺ�
	{
		system("cls"); //�ܼ�â �ʱ�ȭ
		printf("������������������������������������������������������������������\n");
		printf("��    ROCK SCISSOR PAPER GAME    ��\n");
		printf("������������������������������������������������������������������\n");
		printf("���Ӹ�� - 10�� �ݺ����\n");
		printf("���� �¸�Ƚ��: %d, �й�Ƚ��: %d\n", _winNumber, _loseNumber);
		printf("���� ���º�Ƚ��: %d, �ݺ�Ƚ��: %d\n", _drawNumber, _tryNumber);
		PlayRockScissorPaperGame(); //���ӽ���
	}
	system("cls"); //�ܼ�â �ʱ�ȭ
	printf("����������������������������������������������������������������������\n");
	printf("��    ROCK SCISSOR PAPER Result    ��\n");
	printf("����������������������������������������������������������������������\n");
	printf("���Ӹ�� - 10�� �ݺ����\n");
	printf("���� �¸�Ƚ��: %d, �й�Ƚ��: %d\n", _winNumber, _loseNumber);
	printf("���� ���º�Ƚ��: %d, �ݺ�Ƚ��: %d\n", _drawNumber, _tryNumber);
}

void PlayRockScissorPaperGame() //�������������� ����
{
	printf("����(0), ����(1), ��(2) �Է�: ");
	cin >> _userHand;
	while (_userHand != 0 && _userHand != 1 && _userHand != 2) //0, 1, 2�߿� �ϳ��� �Է��ϵ��� ����
	{
		printf("0, 1, 2�߿� �����Ͽ� �Է����ּ���.\n");
		printf("����(0), ����(1), ��(2) �Է�: ");
		cin >> _userHand;
	}
	_comHand = rand() % 3;
	PrintResult();
}

void PrintResult() //��� ��� �� ó��
{
	++_tryNumber; //�õ�Ƚ�� +1;
	//�ϴ� ������ �´��� ���
	if (_userHand == ROCK)
	{
		printf("�÷��̾�: ����\n");
	}
	else if (_userHand == SCISSOR)
	{
		printf("�÷��̾�: ����\n");
	}
	else if (_userHand == PAPER)
	{
		printf("�÷��̾�: ��\n");
	}
	if (_comHand == ROCK)
	{
		printf("��ǻ��: ����\n");
	}
	else if (_comHand == SCISSOR)
	{
		printf("��ǻ��: ����\n");
	}
	else if (_comHand == PAPER)
	{
		printf("��ǻ��: ��\n");
	}
	//��� ��� �� ó��
	if (_userHand == _comHand)
	{
		_drawNumber++; //���º�Ƚ�� +1
		printf("�����ϴ�.\n");
	}
	else if ((_userHand == ROCK && _comHand == SCISSOR) ||
		(_userHand == SCISSOR && _comHand == PAPER) ||
		(_userHand == PAPER && _comHand == ROCK)) //�÷��̾ �̰��� ��
	{
		_winNumber++; //�¸�Ƚ�� +1
		printf("�̰���ϴ�.\n");
	}
	else if ((_comHand == ROCK && _userHand == SCISSOR) ||
		(_comHand == SCISSOR && _userHand == PAPER) ||
		(_comHand == PAPER && _userHand == ROCK)) //��ǻ�Ͱ� �̰��� ��
	{
		_loseNumber++; //�й�Ƚ�� +1
		printf("�����ϴ�.\n");
	}
	printf("�ƹ����� �Է�(���� ��): ");
	cin >> _userInput;
}