#include <iostream>
#include <time.h>

using namespace std;

int _firstComNumber = 0;
int _secondComNumber = 0;
int _thirdComNumber = 0;

void SelectRandomNumber(); //��ǻ�� ���� ���� ����
void PrintComNumber(); //�������
void PrintResult(); //������

void main()
{
	srand(time(NULL));
	printf("========== ��ǻ�� ���� ���� ���� ==========\n");
	SelectRandomNumber(); //��ǻ�� ���� ���� ����
	PrintComNumber(); //�������
	PrintResult(); //������

}

void SelectRandomNumber() //��ǻ�� ���� ���� ����
{
	_firstComNumber = rand() % 100; //0~99 ������������
	_secondComNumber = rand() % 100; //0~99 ������������
	_thirdComNumber = rand() % 100; //0~99 ������������
}

void PrintComNumber() //�������
{
	printf("��ǻ��1 ����: %d\n", _firstComNumber);
	printf("��ǻ��2 ����: %d\n", _secondComNumber);
	printf("��ǻ��3 ����: %d\n", _thirdComNumber);
}

void PrintResult() //������
{
	//ù ��° ��ǻ�Ͱ� �¸��� ��
	if (_firstComNumber > _secondComNumber && _firstComNumber > _thirdComNumber)
	{
		printf("��ǻ��1 �¸�!!!\n");
	}
	//�� ��° ��ǻ�Ͱ� �¸��� ��
	else if (_secondComNumber > _firstComNumber && _secondComNumber > _thirdComNumber)
	{
		printf("��ǻ��2 �¸�!!!\n");
	}
	//�� ��° ��ǻ�Ͱ� �¸��� ��
	else if (_thirdComNumber > _firstComNumber && _thirdComNumber > _secondComNumber)
	{
		printf("��ǻ��3 �¸�!!!\n");
	}
	//1 == 2 > 3
	else if (_firstComNumber == _secondComNumber && _firstComNumber > _thirdComNumber)
	{
		printf("��ǻ��1, ��ǻ��2 ���ý¸�!!!\n");
	}
	//1 == 3 > 2
	else if (_firstComNumber == _thirdComNumber && _firstComNumber > _secondComNumber)
	{
		printf("��ǻ��1, ��ǻ��3 ���ý¸�!!!\n");
	}
	//2 == 3 > 1
	else if (_secondComNumber == _thirdComNumber && _secondComNumber > _firstComNumber)
	{
		printf("��ǻ��2, ��ǻ��3 ���ý¸�!!!\n");
	}
	//1 == 2 == 3
	else if (_firstComNumber == _secondComNumber && _firstComNumber == _thirdComNumber)
	{
		printf("��ǻ�� 1, 2, 3 ���\n");
	}
	else
	{
		printf("!!!����!!!\n");
	}
}