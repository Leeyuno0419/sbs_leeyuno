#include <iostream>

using namespace std;

void main() {
	//SWITCH ��
	//IF���� ���� �����ϰ� IF���� ��ü�� �� �ֽ��ϴ�.

	//SWITCH���� �������� �� ����.
	//�׸��� ���� �̼������� ��¦ �� ������.

	::printf("���� (0), ����(1), ��(2) �߿� �ϳ��� �Է�: \n");
	int hand;
	cin >> hand;

	cout << "���� ���� ����: ";
	switch (hand)
	{
	case 0:
		cout << "����" << endl;
		break;
	case 1:
		cout << "����" << endl;
		break;
	case 2:
		cout << "����" << endl;
		break;
	default:
		cout << "�߸� �̾ҽ��ϴ�." << endl;
		break;
	}
}