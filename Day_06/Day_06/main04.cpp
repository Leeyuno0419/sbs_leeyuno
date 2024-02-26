#include <iostream>

using namespace std;

void main()
{
	int arr[100] = {};
	for (int i = 0; i < 100; i++)
	{
		arr[i] = i;
	}
	
	for (int i = 0; i < 10000; i++)
	{
		int firstIndex = rand() % 100;
		int secondIndex = rand() % 100;

		int temp = arr[firstIndex];
		arr[firstIndex] = arr[secondIndex];
		arr[secondIndex] = temp;
	}

	for (int i = 0; i < 100; i++)
	{
		printf("arr[%d] = %d\n", i, arr[i]);
	}
}