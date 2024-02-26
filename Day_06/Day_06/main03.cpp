#include <iostream>

using namespace std;

void main()
{
	int a = 3;
	int b = 5;
	int temp = a; //잠시 담아 놓을 변수

	a = b;
	b = temp;

	printf("a : %d\n", a);
	printf("b : %d\n", b);
}
//20240226 숙제
//1. 로또생성기
// - 1 ~ 45까지 적힌 볼(array)을 만든다.
// - array를 섞는다.
// - 그중 7개를 뽑는다.
// 
//2. 가위바위보 하나빼기(배열사용)
// 
//3. 21일 숙제 심화버전
