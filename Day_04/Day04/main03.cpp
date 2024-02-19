#include <iostream>

using namespace std;

void main() {
	//IF문 실습
	//1. 점수 4개를 입력받는다.
	//2. 점수의 총합이 400 이상이면 A를 출력.
	//3. 점수의 총합이 350 이상이면 B를 출력
	//4. 점수의 총합이 300 이상이면 C를 출력
	//5. 그미만이면 D를 출력.

	int score = 0;
	int input = 0;

	for (int i = 0; i < 4; i++)
	{
		//::printf("점수를 입력: ");
		//::scanf_s("%d", &input);
		cout << i+1 << "번째 점수를 입력: ";
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
	
	//TIP 변수명 바꾸기(ctrl + R + R)

}