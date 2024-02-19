#include <iostream>
#include <time.h>
using namespace std;

void main() {
	srand(time(NULL));
	//1.
	::printf("·£´ý ¼ö: %d\n", rand()%31);
	//2.
	int random1 = rand() % 101;
	//3.
	::printf("·£´ý ¼ö: %d\n", rand() % 16 + 25);
	//4.
	int random2 = rand() % 121 + 150;
	::printf("%d", random2);
}