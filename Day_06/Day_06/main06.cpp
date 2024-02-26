#include <iostream>

using namespace std;

void main()
{
	//반복문 심화
	//for, while, do while
	for (int i = 0; i < 100; i++)
	{
		if (i % 2 == 0)
		{
			continue; //아래무시하고 포문 처음으로 다시감
		}


		if (i == 10)
		{
			break; //포문 탈출
		}
	}

	printf("break는 탈출");

}