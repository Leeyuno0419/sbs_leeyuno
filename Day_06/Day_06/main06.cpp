#include <iostream>

using namespace std;

void main()
{
	//�ݺ��� ��ȭ
	//for, while, do while
	for (int i = 0; i < 100; i++)
	{
		if (i % 2 == 0)
		{
			continue; //�Ʒ������ϰ� ���� ó������ �ٽð�
		}


		if (i == 10)
		{
			break; //���� Ż��
		}
	}

	printf("break�� Ż��");

}