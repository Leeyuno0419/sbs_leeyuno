#include <iostream>
#include <time.h>

using namespace std;

// 2. while���� Ȱ��
// - ���ڸ��߱� ����


int _userInput = 0;	//�����Է��� ������ ����
int _tryNumber = 0; //�õ�Ƚ���� ������ ����

void main()
{
	srand(time(NULL));
	int randomNumber = (rand() % 100) + 1; //1~100 ���� ���� ����


	while (_userInput != randomNumber) //���ڸ� ���� ������ �ݺ�
	{
		printf("���� �Է�: ");
		cin >> _userInput;
		_tryNumber++;
		if (_userInput == randomNumber)
		{
			printf("\n���ڸ� ���߼̽��ϴ�.\n");
			printf("�õ�Ƚ��: %d\n", _tryNumber);
			printf("�ƹ����� �Է�(����): ");
			cin >> _userInput;
			exit(0);
		}
		else if (_userInput > randomNumber) //�������ڰ� �� ���� ��
		{
			printf("\n�� DOWN ��\n");
		}
		else //�������ڰ� �� Ŭ ��
		{
			printf("\n�� UP ��\n");
		}
	}
}