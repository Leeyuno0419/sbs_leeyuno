#include <iostream>
#include <time.h>

using namespace std;

int _attackDmg = 3;			//플레이어 공격력 3으로 선언 및 정의
int _maxHp = 100, _nowHp = 100;		//플레이어 체력 100으로 선언 및 정의
int _x = 0, _y = 0;			//플레이어 위치 0, 0으로 선언 및 정의
int _exp = 0, _level = 0;	//플레이어 경험치 및 레벨 0으로 선언 및 정의

void GameStartSelect();	//게임선택(시작, 설명, 종료)
void GameStart();		//게임시작
void GameExplain();		//게임설명
void MoveRoom();
void InsertRoom(int x, int y);
void NormalMonster();
void BossMonster();
//void GameExit();		//게임종료

void main()
{
	srand(time(NULL));
	GameStartSelect();	
}

void GameStartSelect()
{
	int selectnum = 0;
	::printf("┌──────────────────┐\n");
	::printf("│    Text  RPG     │\n");
	::printf("└──────────────────┘\n");
	::printf("1. 게임시작\n");
	::printf("2. 게임설명\n");
	::printf("3. 게임종료\n");
	::printf("번호입력: ");
	cin >> selectnum;
	system("cls"); //콘솔창 초기화
	switch (selectnum)
	{
	case 1:
		GameStart();
		break;
	case 2:
		GameExplain();
		break;
	case 3:
		//GameExit();
		break;
	default:
		system("cls"); //콘솔창 초기화
		printf("올바르지 않은 입력입니다.\n");
		selectnum = 0;
		GameStartSelect();
		break;
	}
}

void GameStart()
{
	int moveNum;
	while (_nowHp > 0)
	{
		system("cls"); //콘솔창 초기화
		::printf("┌──────────────────┐\n");
		::printf("│    Text  RPG     │\n");
		::printf("└──────────────────┘\n");
		::printf("현재 체력: %d / %d\n", _nowHp, _maxHp);
		::printf("현재 공격력: %d ~ %d\n", _attackDmg, _attackDmg + 2);
		::printf("현재 레벨: %d(%d/%d)\n", _level, _exp, _level*5 + 5);
		::printf("현재 위치: X(%d), Y(%d) - 보스위치(3, 3)\n", _x, _y);
		::printf("0(상), 1(하), 2(좌), 3(우)로 선택: ");
		MoveRoom();
	}
}

void GameExplain()
{
	int userInput;
	::printf("┌─────────────────────────┐\n");
	::printf("│    Text  RPG  Explain   │\n");
	::printf("└─────────────────────────┘\n");
	::printf("게임이 시작하면 0(상), 1(하), 2(좌), 3(우)로 선택하여 이동할 수 있다.\n");
	::printf("한칸 움직일 때마다 방에 입장한다.\n");
	::printf("방에서는 몬스터가 등장하는데 공격력(1~10)과 체력(5~10)이 랜덤으로 지정되어 등장한다.\n");
	::printf("몬스터에게 데미지를 입힐 시 가위바위보로 치명타데미지(승), 기본데미지(비김), 약한데미지(패배)를 입힌다.\n");
	::printf("플레이어의 체력은 100 공격력은 3~5이며 몬스터를 잡을때 마다 경험치를 2~5랜덤으로 획득한다.\n");
	::printf("레벨업시 체력이 가득차며 공격력 1, 체력이 10 증가한다.\n");
	::printf("x(3), y(3)의 방에는 보스가 있으며 보스의 체력은 50 공격력은 20이다.\n");
	::printf("승리조건: 보스방 승리\n");
	::printf("패배조건: 체력이 0이하시 실패\n");
	::printf("아무 숫자를 입력하세요: ");
	cin >> userInput;
	system("cls"); //콘솔창 초기화
	GameStartSelect();
}

void MoveRoom()
{
	int moveWay;
	cin >> moveWay;
	switch (moveWay)
	{
	case 0:	//상
		_y++;
		InsertRoom(_x, _y);
		break;
	case 1: //하
		_y--;
		InsertRoom(_x, _y);
		break;
	case 2: //좌
		_x--;
		InsertRoom(_x, _y);
		break;
	case 3: //우
		_x++;
		InsertRoom(_x, _y);
		break;
	default:
		break;
	}
}

void InsertRoom(int x, int y)
{
	if (x == 3 && y == 3) //보스방 입장
	{
		BossMonster();
	}
	else
	{
		NormalMonster();
	}
}

void NormalMonster()
{
	int userInput;
	int expUp;
	int myHand = 0, mobHand = 0;
	int mobHp = rand() % 6 + 5; // 몬스터 체력 5~10
	int mobNowHp = mobHp;
	int mobDmg = rand() % 10 + 1; // 몬스터 공격력 1~10
	while (_nowHp > 0 && mobNowHp > 0)
	{
		system("cls"); //콘솔창 초기화
		::printf("┌─────────────────────────────────┐\n");
		::printf("│    Text  RPG  NormalMonster     │\n");
		::printf("└─────────────────────────────────┘\n");
		::printf("현재 체력: %d / %d\n", _nowHp, _maxHp);
		::printf("현재 공격력: %d ~ %d\n", _attackDmg, _attackDmg + 2);
		::printf("현재 레벨: %d(%d/%d))\n", _level, _exp, _level * 5 + 5);
		::printf("몬스터 체력: %d/%d 공격력: %d\n", mobNowHp, mobHp, mobDmg);
		::printf("가위(0), 바위(1), 보(2) 입력: ");
		cin >> myHand; //플레이어 가위바위보 입력
		mobHand = rand() % 3; //몬스터 가위바위보 랜덤 지정
		::printf("플레이어가 고른 손: ");
		switch (myHand)
		{
		case 0:
			::printf("가위\n");
			break;
		case 1:
			::printf("바위\n");
			break;
		case 2:
			::printf("보\n");
			break;
		default:
			break;
		}
		::printf("몬스터가 고른 손: ");
		switch (mobHand)
		{
		case 0:
			::printf("가위\n");
			break;
		case 1:
			::printf("바위\n");
			break;
		case 2:
			::printf("보\n");
			break;
		default:
			break;
		}
		if (myHand == mobHand) {
			::printf("비겼습니다. 데미지 %d를 입힙니다.\n", _attackDmg + 1);
			mobNowHp -= (_attackDmg + 1);
		}
		else if (myHand == 0) {
			if (mobHand == 1) {
				::printf("몬스터가 이겼습니다. 데미지 %d를 입힙니다.\n", _attackDmg);
				mobNowHp -= _attackDmg;
			}
			if (mobHand == 2) {
				::printf("플레이어가 이겼습니다. 데미지 %d를 입힙니다.\n", _attackDmg + 2);
				mobNowHp -= (_attackDmg + 2);
			}
		}
		else if (myHand == 1) {
			if (mobHand == 2) {
				::printf("몬스터가 이겼습니다. 데미지 %d를 입힙니다.\n", _attackDmg);
				mobNowHp -= _attackDmg;
			}
			if (mobHand == 0) {
				::printf("플레이어가 이겼습니다. 데미지 %d를 입힙니다.\n", _attackDmg + 2);
				mobNowHp -= (_attackDmg + 2);
			}
		}
		else if (myHand == 2) {
			if (mobHand == 1) {
				::printf("몬스터가 이겼습니다. 데미지 %d를 입힙니다.\n", _attackDmg);
				mobNowHp -= _attackDmg;
			}
			if (mobHand == 0) {
				::printf("플레이어가 이겼습니다. 데미지 %d를 입힙니다.\n", _attackDmg + 2);
				mobNowHp -= (_attackDmg + 2);
			}
		}
		if (mobNowHp > 0)
		{
			::printf("몬스터가 살아남아 플레이어를 때립니다.\n");
			::printf("데미지 %d를 입습니다.\n", mobDmg);
			_nowHp -= mobDmg;
			if (_nowHp <= 0) //플레이어 체력 0 이하
			{
				::printf("┌──────────────────────────┐\n");
				::printf("│    Text  RPG  LOSE!!!    │\n");
				::printf("└──────────────────────────┘\n");
			}
		}
		else
		{
			expUp = rand() % 4 + 2;
			::printf("몬스터를 죽였습니다.\n");
			::printf("경험치 %d 증가\n", expUp);
			_exp += expUp;
			if (_exp >= (_level * 5) + 5)
			{
				_exp -= (_level * 5) + 5;
				_level++;
				_attackDmg++;
				_maxHp += 5;
				_nowHp += 10;
				::printf("!!!레벨업!!!\n");
				::printf("공격력 +1, 최대체력 +5, 체력회복 +10\n");
			}
		}
		::printf("다음 턴 시작하기 - 아무 숫자를 입력하세요: ");
		cin >> userInput;
	}
}
void BossMonster()
{
	int userInput;
	int myHand = 0, mobHand = 0;
	int mobHp = 50; // 보스몬스터 체력 50
	int mobNowHp = mobHp;
	int mobDmg = 10; // 보스몬스터 공격력 10
	while (_nowHp > 0 && mobNowHp > 0)
	{
		system("cls"); //콘솔창 초기화
		::printf("┌─────────────────────────────────┐\n");
		::printf("│    Text  RPG  BossMonster       │\n");
		::printf("└─────────────────────────────────┘\n");
		::printf("현재 체력: %d / %d\n", _nowHp, _maxHp);
		::printf("현재 공격력: %d ~ %d\n", _attackDmg, _attackDmg + 2);
		::printf("현재 레벨: %d(%d/%d))\n", _level, _exp, _level * 5 + 5);
		::printf("몬스터 체력: %d/%d 공격력: %d\n", mobNowHp, mobHp, mobDmg);
		::printf("가위(0), 바위(1), 보(2) 입력: ");
		cin >> myHand; //플레이어 가위바위보 입력
		mobHand = rand() % 3; //몬스터 가위바위보 랜덤 지정
		::printf("플레이어가 고른 손: ");
		switch (myHand)
		{
		case 0:
			::printf("가위\n");
			break;
		case 1:
			::printf("바위\n");
			break;
		case 2:
			::printf("보\n");
			break;
		default:
			break;
		}
		::printf("몬스터가 고른 손: ");
		switch (mobHand)
		{
		case 0:
			::printf("가위\n");
			break;
		case 1:
			::printf("바위\n");
			break;
		case 2:
			::printf("보\n");
			break;
		default:
			break;
		}
		if (myHand == mobHand) {
			::printf("비겼습니다. 데미지 %d를 입힙니다.\n", _attackDmg + 1);
			mobNowHp -= (_attackDmg + 1);
		}
		else if (myHand == 0) {
			if (mobHand == 1) {
				::printf("몬스터가 이겼습니다. 데미지 %d를 입힙니다.\n", _attackDmg);
				mobNowHp -= _attackDmg;
			}
			if (mobHand == 2) {
				::printf("플레이어가 이겼습니다. 데미지 %d를 입힙니다.\n", _attackDmg + 2);
				mobNowHp -= (_attackDmg + 2);
			}
		}
		else if (myHand == 1) {
			if (mobHand == 2) {
				::printf("몬스터가 이겼습니다. 데미지 %d를 입힙니다.\n", _attackDmg);
				mobNowHp -= _attackDmg;
			}
			if (mobHand == 0) {
				::printf("플레이어가 이겼습니다. 데미지 %d를 입힙니다.\n", _attackDmg + 2);
				mobNowHp -= (_attackDmg + 2);
			}
		}
		else if (myHand == 2) {
			if (mobHand == 1) {
				::printf("몬스터가 이겼습니다. 데미지 %d를 입힙니다.\n", _attackDmg);
				mobNowHp -= _attackDmg;
			}
			if (mobHand == 0) {
				::printf("플레이어가 이겼습니다. 데미지 %d를 입힙니다.\n", _attackDmg + 2);
				mobNowHp -= (_attackDmg + 2);
			}
		}
		if (mobNowHp > 0)
		{
			::printf("몬스터가 살아남아 플레이어를 때립니다.\n");
			::printf("데미지 %d를 입습니다.\n", mobDmg);
			_nowHp -= mobDmg;
			if (_nowHp <= 0) //플레이어 체력 0 이하
			{
				::printf("┌──────────────────────────┐\n");
				::printf("│    Text  RPG  LOSE!!!    │\n");
				::printf("└──────────────────────────┘\n");
				::printf("아무 숫자를 입력하세요: ");
				cin >> userInput;
			}
		}
		else
		{
			::printf("┌──────────────────────────┐\n");
			::printf("│    Text  RPG  WIN!!!     │\n");
			::printf("└──────────────────────────┘\n");
			::printf("아무 숫자를 입력하세요: ");
			cin >> userInput;
		}
		::printf("다음 턴 시작하기 - 아무 숫자를 입력하세요: ");
		cin >> userInput;
	}
}
