#include <iostream>

using namespace std;

//main01���� 10������ �þ �� �迭�� �ϴ°��� ����.
//�迭 - �Ȱ��� ���������� �������� ������ �����ϴ� ����
int _arr[1000] = {};

void main()
{
	/*��� �����ֱ�
	for (int i = 0; i < 1000; i++)
	{
		_arr[i] = (i + 1) * 2; //�ʱ�ȭ
		printf("arr[%d] : %d\n", i, _arr[i]); //���
	}
	*/

	//�ʱ�ȭ
	for (int i = 0; i < 1000; i++)
	{
		_arr[i] = (i + 1) * 2;
	}

	//���
	for (int i = 0; i < 1000; i++)
	{
		printf("arr[%d] : %d\n", i, _arr[i]);
	}
}