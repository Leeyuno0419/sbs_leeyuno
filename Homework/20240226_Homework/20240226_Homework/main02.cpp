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

//2. ���������� �ϳ�����(�迭���)

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
	printf("������������������������������������������������������������������\n");
	printf("��    ROCK SCISSOR PAPER GAME    ��\n");
	printf("������������������������������������������������������������������\n");
	for (int i = 0; i < END_Hand; i++) // �޼�, ������ ������ ���� 2�� �ݺ�
	{
		printf("%d ��° - ����(0), ����(1), ��(2) �Է�: ", i);
		cin >> _arrMyHand[i];
		while (_arrMyHand[i] != ROCK_RSP && _arrMyHand[i] != SCISSOR_RSP && _arrMyHand[i] != PAPER_RSP) //0, 1, 2�߿� �ϳ��� �Է��ϵ��� ����
		{
			printf("0, 1, 2�߿� �����Ͽ� �Է����ּ���.\n");
			printf("����(0), ����(1), ��(2) �Է�: ");
			cin >> _arrMyHand[i];
		}
	}
}

void SelectComRSP()
{
	_arrComHand[LEFT_Hand] = rand() % END_RSP; //��ǻ�� �޼� ����
	_arrComHand[RIGHT_Hand] = rand() % END_RSP; //��ǻ�� �����ռ� ����
}

void PrintHand()
{
	system("cls");
	printf("������������������������������������������������������������������\n");
	printf("��    ROCK SCISSOR PAPER GAME    ��\n");
	printf("������������������������������������������������������������������\n");
	//�÷��̾�
	if (_arrMyHand[LEFT_Hand] == ROCK_RSP)
	{
		printf("�÷��̾��� �޼�: ����\n");
	}
	else if (_arrMyHand[LEFT_Hand] == SCISSOR_RSP)
	{
		printf("�÷��̾��� �޼�: ����\n");
	}
	else
	{
		printf("�÷��̾��� �޼�: ��\n");
	}
	if (_arrMyHand[RIGHT_Hand] == ROCK_RSP)
	{
		printf("�÷��̾��� ������: ����\n");
	}
	else if (_arrMyHand[RIGHT_Hand] == SCISSOR_RSP)
	{
		printf("�÷��̾��� ������: ����\n");
	}
	else
	{
		printf("�÷��̾��� ������: ��\n");
	}
	//��ǻ��
	if (_arrComHand[LEFT_Hand] == ROCK_RSP)
	{
		printf("��ǻ���� �޼�: ����\n");
	}
	else if (_arrComHand[LEFT_Hand] == SCISSOR_RSP)
	{
		printf("��ǻ���� �޼�: ����\n");
	}
	else
	{
		printf("��ǻ���� �޼�: ��\n");
	}
	if (_arrComHand[RIGHT_Hand] == ROCK_RSP)
	{
		printf("��ǻ���� ������: ����\n");
	}
	else if (_arrComHand[RIGHT_Hand] == SCISSOR_RSP)
	{
		printf("��ǻ���� ������: ����\n");
	}
	else
	{
		printf("��ǻ���� ������: ��\n");
	}
}

void TakeOneMyHand()
{
	printf("���⸦ �� �� ����(�޼�(0), ������(1)) �Է�: ");
	cin >> _takedMyHand;
}

void TakeOneComHand()
{
	_takedComHand = rand() % END_Hand;
}

void PrintResult()
{
	printf("�÷��̾ �� �� - ");
	if (_takedMyHand == LEFT_Hand)
	{
		printf("�޼�\n");
	}
	else
	{
		printf("������\n");
	}
	printf("��ǻ�Ͱ� �� �� - ");
	if (_takedComHand == LEFT_Hand)
	{
		printf("�޼�\n");
	}
	else
	{
		printf("������\n");
	}
	if (_takedMyHand == LEFT_Hand)
	{
		//�÷��̾�: ������, ��ǻ��: ������ 
		if (_takedComHand == LEFT_Hand)
		{
			if ((_arrMyHand[RIGHT_Hand] == ROCK_RSP && _arrComHand[RIGHT_Hand] == SCISSOR_RSP) ||
				(_arrMyHand[RIGHT_Hand] == SCISSOR_RSP && _arrComHand[RIGHT_Hand] == PAPER_RSP) ||
				(_arrMyHand[RIGHT_Hand] == PAPER_RSP && _arrComHand[RIGHT_Hand] == ROCK_RSP))
			{
				printf("�̰���ϴ�.\n");
			}
			else if ((_arrMyHand[RIGHT_Hand] == ROCK_RSP && _arrComHand[RIGHT_Hand] == PAPER_RSP) ||
				(_arrMyHand[RIGHT_Hand] == SCISSOR_RSP && _arrComHand[RIGHT_Hand] == ROCK_RSP) ||
				(_arrMyHand[RIGHT_Hand] == PAPER_RSP && _arrComHand[RIGHT_Hand] == SCISSOR_RSP))
			{
				printf("�����ϴ�.\n");
			}
			else
			{
				printf("�����ϴ�.\n");
			}
		}
		//�÷��̾�: ������, ��ǻ��: �޼� 
		else
		{
			if ((_arrMyHand[RIGHT_Hand] == ROCK_RSP && _arrComHand[LEFT_Hand] == SCISSOR_RSP) ||
				(_arrMyHand[RIGHT_Hand] == SCISSOR_RSP && _arrComHand[LEFT_Hand] == PAPER_RSP) ||
				(_arrMyHand[RIGHT_Hand] == PAPER_RSP && _arrComHand[LEFT_Hand] == ROCK_RSP))
			{
				printf("�̰���ϴ�.\n");
			}
			else if ((_arrMyHand[RIGHT_Hand] == ROCK_RSP && _arrComHand[LEFT_Hand] == PAPER_RSP) ||
				(_arrMyHand[RIGHT_Hand] == SCISSOR_RSP && _arrComHand[LEFT_Hand] == ROCK_RSP) ||
				(_arrMyHand[RIGHT_Hand] == PAPER_RSP && _arrComHand[LEFT_Hand] == SCISSOR_RSP))
			{
				printf("�����ϴ�.\n");
			}
			else
			{
				printf("�����ϴ�.\n");
			}
		}
	}
	else
	{
		//�÷��̾�: �޼�, ��ǻ��: ������ 
		if (_takedComHand == LEFT_Hand)
		{
			if ((_arrMyHand[LEFT_Hand] == ROCK_RSP && _arrComHand[RIGHT_Hand] == SCISSOR_RSP) ||
				(_arrMyHand[LEFT_Hand] == SCISSOR_RSP && _arrComHand[RIGHT_Hand] == PAPER_RSP) ||
				(_arrMyHand[LEFT_Hand] == PAPER_RSP && _arrComHand[RIGHT_Hand] == ROCK_RSP))
			{
				printf("�̰���ϴ�.\n");
			}
			else if ((_arrMyHand[LEFT_Hand] == ROCK_RSP && _arrComHand[RIGHT_Hand] == PAPER_RSP) ||
				(_arrMyHand[LEFT_Hand] == SCISSOR_RSP && _arrComHand[RIGHT_Hand] == ROCK_RSP) ||
				(_arrMyHand[LEFT_Hand] == PAPER_RSP && _arrComHand[RIGHT_Hand] == SCISSOR_RSP))
			{
				printf("�����ϴ�.\n");
			}
			else
			{
				printf("�����ϴ�.\n");
			}
		}
		//�÷��̾�: �޼�, ��ǻ��: �޼� 
		else
		{
			if ((_arrMyHand[LEFT_Hand] == ROCK_RSP && _arrComHand[LEFT_Hand] == SCISSOR_RSP) ||
				(_arrMyHand[LEFT_Hand] == SCISSOR_RSP && _arrComHand[LEFT_Hand] == PAPER_RSP) ||
				(_arrMyHand[LEFT_Hand] == PAPER_RSP && _arrComHand[LEFT_Hand] == ROCK_RSP))
			{
				printf("�̰���ϴ�.\n");
			}
			else if ((_arrMyHand[LEFT_Hand] == ROCK_RSP && _arrComHand[LEFT_Hand] == PAPER_RSP) ||
				(_arrMyHand[LEFT_Hand] == SCISSOR_RSP && _arrComHand[LEFT_Hand] == ROCK_RSP) ||
				(_arrMyHand[LEFT_Hand] == PAPER_RSP && _arrComHand[LEFT_Hand] == SCISSOR_RSP))
			{
				printf("�����ϴ�.\n");
			}
			else
			{
				printf("�����ϴ�.\n");
			}
		}
	}
}
