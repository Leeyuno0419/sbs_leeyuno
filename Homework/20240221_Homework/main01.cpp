#include <iostream>

using namespace std;

void main()
{
	//1. ����� 4�� (2�� ������ Ȱ��)

	::printf("1��\n");
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < i + 1; j++)
		{
			::printf("*");
		}
		::printf("\n");
	}

	::printf("2��\n");
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

	::printf("3��\n");
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

	::printf("4��\n");
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