#include <iostream>
#include <time.h>
using namespace std;

void main() {
	srand(time(NULL));
	int input1 = 0;
	int input2 = 0;
	::printf("ù��° ���� �Է�: ");
	::scanf_s("%d\n", &input1);
	::printf("�ι�° ���� �Է�: ");
	::scanf_s("%d\n", &input2);
	::printf("%d", rand() % (input2 - input1 + 1) + input1);
}
