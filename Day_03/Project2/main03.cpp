#include <iostream>
#include <time.h>
using namespace std;

void main() {
	srand(time(NULL));
	int input1 = 0;
	int input2 = 0;
	int input3 = 0;
	int input4 = 0;
	::printf("첫번째 숫자 입력: ");
	::scanf_s("%d\n", &input1);
	::printf("두번째 숫자 입력: ");
	::scanf_s("%d\n", &input2);
	::printf("세번째 숫자 입력: ");
	::scanf_s("%d\n", &input3);
	::printf("네번째 숫자 입력: ");
	::scanf_s("%d\n", &input4);
	::printf("%d", (rand() % (input2 - input1 + 1) + input1 - input3) * input4);
}