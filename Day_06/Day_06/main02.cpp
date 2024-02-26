#include <iostream>

using namespace std;

//main01에서 10명으로 늘어날 때 배열로 하는것이 좋다.
//배열 - 똑같은 변수명으로 여러개의 변수를 선언하는 문법
int _arr[1000] = {};

void main()
{
	/*기능 나눠주기
	for (int i = 0; i < 1000; i++)
	{
		_arr[i] = (i + 1) * 2; //초기화
		printf("arr[%d] : %d\n", i, _arr[i]); //출력
	}
	*/

	//초기화
	for (int i = 0; i < 1000; i++)
	{
		_arr[i] = (i + 1) * 2;
	}

	//출력
	for (int i = 0; i < 1000; i++)
	{
		printf("arr[%d] : %d\n", i, _arr[i]);
	}
}