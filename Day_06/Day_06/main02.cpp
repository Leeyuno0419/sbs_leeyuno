#include <iostream>
#include <time.h>

using namespace std;

//main01에서 10명으로 늘어날 때 배열로 하는것이 좋다.
//배열 - 똑같은 변수명으로 여러개의 변수를 선언하는 문법
int _arr[1000] = {};

void main()
{
	for (int i = 0; i < 1000; i++)
	{
		_arr[i] = (i + 1) * 2;
		printf("arr[%d] : %d\n", i, _arr[i]);
	}
}