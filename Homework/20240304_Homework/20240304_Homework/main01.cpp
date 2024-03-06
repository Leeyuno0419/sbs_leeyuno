#include <iostream>
#include <time.h>

using namespace std;

int MakeBaseballNumber(); //�ߺ����� �ʴ� ������ ���ڸ� �����ϴ� �Լ� - [1023(�ּڰ�) ~ 9876(�ִ밪)]���ڸ� ��ȯ���ش�.
void PrintResult(int baseballNumber, int guess); //��Ʈ����ũ�� �� Ƚ���� ������� �Լ�
int _baseballNumber;

void main()
{
	srand(time(NULL));
	_baseballNumber = MakeBaseballNumber(); //���ھ߱� ���ڸ� �־��ش�.
	int guessNumber;
	bool correctGuess = false;
	printf("-���ھ߱� ����-\n");
	printf("-��� ���ڸ� �����ּ���(4���� �ߺ����� �ʴ� ����)-\n");
	while (!correctGuess)
	{
		printf("������ ���ڸ� �Է�:");
		cin >> guessNumber;
		PrintResult(_baseballNumber, guessNumber);
		if (guessNumber == _baseballNumber)
		{
			correctGuess = true;
		}
	}
	printf("������ ���߼̽��ϴ�. ���� ��\n");
}

//�ߺ����� �ʴ� ������ ���ڸ� �����ϴ� �Լ� - [1023(�ּڰ�)~9876(�ִ밪)]���ڸ� ��ȯ���ش�.
int MakeBaseballNumber()
{
	int randomNumber;//���� ���ڸ� ������ ����
	bool isUnique = false; //�ߺ� �Ǵ�
	while (!isUnique)//�ߺ��� �ȵ� ������ �ݺ�
	{
		isUnique = true;//�ϴ��� �ߺ����� �ʾҴٰ� ����
		randomNumber = rand() % 9000 + 1000; //1000���� 9999���� ���� ���� ����
		int selectedNumber[10] = {0}; // 0���� 9������ ���� ��� ���θ� �����ϴ� �迭
		int temp = randomNumber; //temp�� randomNumber�� �˻��ϱ����� �ӽ÷� ������ ����
		//�˻� �� ������ 10�� ���� �� ������ ���ڸ� selectedNumber[10]�� ���� ������ ��ġ�� 1�� ����
		// �� 1�� �ڸ����� 3�϶�
		// selectedNumber[3] = 1 ���� ��
		// temp�� temp/10 ������ �ݺ�
		// ����
		// �� - temp = 1231 -> �ݺ��� ��� selectedNumber[1] = 1, temp = 123 -> �ݺ��� ��� selectedNumber[1] = 1, selectedNumber[3] = 1, temp = 12
		//    -> �ݺ��� ��� selectedNumber[1] = 1, selectedNumber[3] = 1, selectedNumber[2] = 1, temp = 1 -> �ݺ��� ���� �� �ߺ��� �߰ߵǾ� �ٽ� ���� ���� ����
		while (temp > 0) //1��° �ڸ����� 4���ڸ��� �����ݺ�
		{
			int digit = temp % 10;//�ڸ����� �̾ƿ���
			if (selectedNumber[digit] == 1) //�̹� �ش� �ڸ��� ���Ǿ��� ��
			{
				isUnique = false; //�ߺ��̹Ƿ� false�� �ٲ���
				break;//���̻� Ȯ���� �ʿ䰡 ���⿡ �ݺ��� Ż��
			}
			selectedNumber[digit] = 1; //�ش� �ڸ����� ����ߴٴ� ǥ��
			temp = temp / 10; //�ش� �ڸ����� ����߱⿡ ���� �ڸ����� �б����� ������ 10 ���
		}
	}
	return randomNumber; //�ߺ��� ����� ������ ���� ��ȯ
}

//��Ʈ����ũ�� �� Ƚ���� ������� �Լ�
void PrintResult(int baseballNumber, int guess)
{
	int strikeNumber = 0; //��Ʈ����ũ Ƚ���� ������ ����
	int ballNumber = 0; //�� Ƚ���� ������ ����
	int baseballDigits[4], guessDigits[4]; //��м��ڿ� ������ ���ڸ� �迭�� �����ϱ� ���� ����

	// ��� ������ �� �ڸ����� �迭�� ����
	for (int i = 3; i >= 0; --i) {
		baseballDigits[i] = baseballNumber % 10;
		baseballNumber /= 10;
	}

	// ���� ������ �� �ڸ����� �迭�� ����
	for (int i = 3; i >= 0; --i) {
		guessDigits[i] = guess % 10;
		guess /= 10;
	}

	// ��Ʈ����ũ�� �� ���
	for (int i = 0; i < 4; ++i) {
		if (baseballDigits[i] == guessDigits[i]) // ���ڿ� ��ġ�� ��ġ�ϴ� ��� ��Ʈ����ũ
			strikeNumber++;
		else {
			for (int j = 0; j < 4; ++j) {
				if (i != j && baseballDigits[i] == guessDigits[j]) // ���ڴ� ��ġ������ ��ġ�� �ٸ� ��� ��
					ballNumber++;
			}
		}
	}
	printf("��Ʈ����ũ: %d, ��: %d\n", strikeNumber, ballNumber); //��Ʈ����ũ Ƚ��, �� Ƚ�� ���
}