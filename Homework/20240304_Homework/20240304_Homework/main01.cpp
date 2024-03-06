#include <iostream>
#include <time.h>

using namespace std;

int MakeBaseballNumber(); //중복되지 않는 랜덤한 숫자를 생성하는 함수 - [1023(최솟값) ~ 9876(최대값)]숫자를 반환해준다.
void PrintResult(int baseballNumber, int guess); //스트라이크와 볼 횟수를 출력해줄 함수
int _baseballNumber;

void main()
{
	srand(time(NULL));
	_baseballNumber = MakeBaseballNumber(); //숫자야구 숫자를 넣어준다.
	int guessNumber;
	bool correctGuess = false;
	printf("-숫자야구 게임-\n");
	printf("-비밀 숫자를 맞춰주세요(4개의 중복되지 않는 숫자)-\n");
	while (!correctGuess)
	{
		printf("추측할 숫자를 입력:");
		cin >> guessNumber;
		PrintResult(_baseballNumber, guessNumber);
		if (guessNumber == _baseballNumber)
		{
			correctGuess = true;
		}
	}
	printf("정답을 맞추셨습니다. 게임 끝\n");
}

//중복되지 않는 랜덤한 숫자를 생성하는 함수 - [1023(최솟값)~9876(최대값)]숫자를 반환해준다.
int MakeBaseballNumber()
{
	int randomNumber;//랜덤 숫자를 저장할 변수
	bool isUnique = false; //중복 판단
	while (!isUnique)//중복이 안될 때까지 반복
	{
		isUnique = true;//일단은 중복되지 않았다고 가정
		randomNumber = rand() % 9000 + 1000; //1000부터 9999까지 랜덤 숫자 생성
		int selectedNumber[10] = {0}; // 0부터 9까지의 숫자 사용 여부를 저장하는 배열
		int temp = randomNumber; //temp는 randomNumber를 검사하기위해 임시로 저장한 변수
		//검사 할 변수를 10을 나눈 후 나머지 숫자를 selectedNumber[10]에 사용된 숫자의 위치에 1로 저장
		// 예 1의 자릿수가 3일때
		// selectedNumber[3] = 1 저장 후
		// temp에 temp/10 저장후 반복
		// 로직
		// 예 - temp = 1231 -> 반복문 통과 selectedNumber[1] = 1, temp = 123 -> 반복문 통과 selectedNumber[1] = 1, selectedNumber[3] = 1, temp = 12
		//    -> 반복문 통과 selectedNumber[1] = 1, selectedNumber[3] = 1, selectedNumber[2] = 1, temp = 1 -> 반복문 실행 중 중복이 발견되어 다시 랜덤 숫자 생성
		while (temp > 0) //1번째 자리부터 4번자릿수 까지반복
		{
			int digit = temp % 10;//자릿수만 뽑아오기
			if (selectedNumber[digit] == 1) //이미 해당 자릿수 사용되었을 때
			{
				isUnique = false; //중복이므로 false로 바꿔줌
				break;//더이상 확인할 필요가 없기에 반복문 탈출
			}
			selectedNumber[digit] = 1; //해당 자릿수를 사용했다는 표시
			temp = temp / 10; //해당 자릿수를 통과했기에 다음 자릿수를 읽기위해 나누기 10 사용
		}
	}
	return randomNumber; //중복을 통과한 랜덤한 숫자 반환
}

//스트라이크와 볼 횟수를 출력해줄 함수
void PrintResult(int baseballNumber, int guess)
{
	int strikeNumber = 0; //스트라이크 횟수를 저장할 변수
	int ballNumber = 0; //볼 횟수를 저장할 변수
	int baseballDigits[4], guessDigits[4]; //비밀숫자와 추측할 숫자를 배열로 저장하기 위한 변수

	// 비밀 숫자의 각 자릿수를 배열에 저장
	for (int i = 3; i >= 0; --i) {
		baseballDigits[i] = baseballNumber % 10;
		baseballNumber /= 10;
	}

	// 추측 숫자의 각 자릿수를 배열에 저장
	for (int i = 3; i >= 0; --i) {
		guessDigits[i] = guess % 10;
		guess /= 10;
	}

	// 스트라이크와 볼 계산
	for (int i = 0; i < 4; ++i) {
		if (baseballDigits[i] == guessDigits[i]) // 숫자와 위치가 일치하는 경우 스트라이크
			strikeNumber++;
		else {
			for (int j = 0; j < 4; ++j) {
				if (i != j && baseballDigits[i] == guessDigits[j]) // 숫자는 일치하지만 위치가 다른 경우 볼
					ballNumber++;
			}
		}
	}
	printf("스트라이크: %d, 볼: %d\n", strikeNumber, ballNumber); //스트라이크 횟수, 볼 횟수 출력
}