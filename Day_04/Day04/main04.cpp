#include <iostream>

using namespace std;

void main() {
	//SWITCH 문
	//IF문과 아주 유사하고 IF문에 대체될 수 있습니다.

	//SWITCH문이 가독성이 더 좋다.
	//그리고 아주 미세하지만 살짝 더 빠르다.

	::printf("가위 (0), 바위(1), 보(2) 중에 하나를 입력: \n");
	int hand;
	cin >> hand;

	cout << "내가 뽑은 것은: ";
	switch (hand)
	{
	case 0:
		cout << "가위" << endl;
		break;
	case 1:
		cout << "바위" << endl;
		break;
	case 2:
		cout << "바위" << endl;
		break;
	default:
		cout << "잘못 뽑았습니다." << endl;
		break;
	}
}