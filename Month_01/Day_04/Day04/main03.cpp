#include <iostream>

using namespace std;

void main() {
	//IF�� �ǽ�
	//1. ���� 4���� �Է¹޴´�.
	//2. ������ ������ 400 �̻��̸� A�� ���.
	//3. ������ ������ 350 �̻��̸� B�� ���
	//4. ������ ������ 300 �̻��̸� C�� ���
	//5. �׹̸��̸� D�� ���.

	int score = 0;
	int input = 0;

	for (int i = 0; i < 4; i++)
	{
		//::printf("������ �Է�: ");
		//::scanf_s("%d", &input);
		cout << i+1 << "��° ������ �Է�: ";
		cin >> input;
		score += input;
	}

	if (score >= 400)
	{
		//::printf("A\n");
		cout << "A\n" << endl;
	}
	else if (score >= 350)
	{
		//::printf("B\n");
		cout << "B\n" << endl;
	}
	else if (score >= 300)
	{
		//::printf("C\n");
		cout << "C\n" << endl;
	}
	else
	{
		//::printf("D\n");
		cout << "D\n" << endl;
	}
	
	//TIP ������ �ٲٱ�(ctrl + R + R)

}