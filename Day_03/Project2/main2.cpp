#include <iostream>
#include <time.h>
using namespace std;

void main() {
	srand(time(NULL));
	int input1 = 0;
	int input2 = 0;
	::printf("첫번째 숫자 입력: ");
	::scanf_s("%d\n", &input1);
	::printf("두번째 숫자 입력: ");
	::scanf_s("%d\n", &input2);
	::printf("%d", rand() % (input2 - input1 + 1) + input1);
}
