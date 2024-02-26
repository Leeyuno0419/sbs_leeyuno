#include <iostream>

using namespace std;

void main()
{
	//1. 별찍기 4종 (2중 포문을 활용)

	::printf("1종\n");
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < i + 1; j++)
		{
			::printf("*");
		}
		::printf("\n");
	}

	::printf("2종\n");
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 4 - i; j++)
		{
			::printf(" ");
		}
		for (int j = 0; j < i + 1; j++)
		{
			::printf("*");
		}
		::printf("\n");
	}

	::printf("3종\n");
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5 - i; j++)
		{
			::printf("*");
		}
		for (int j = 0; j < 4 - i; j++)
		{
			::printf(" ");
		}
		::printf("\n");
	}

	::printf("4종\n");
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < i; j++)
		{
			::printf(" ");
		}
		for (int j = 0; j < 5 - i; j++)
		{
			::printf("*");
		}	
		::printf("\n");
	}
}