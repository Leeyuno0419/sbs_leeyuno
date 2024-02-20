#include <iostream>
#include <time.h>

using namespace std;

int _attackDmg = 3;			//�÷��̾� ���ݷ� 3���� ���� �� ����
int _maxHp = 100, _nowHp = 100;		//�÷��̾� ü�� 100���� ���� �� ����
int _x = 0, _y = 0;			//�÷��̾� ��ġ 0, 0���� ���� �� ����
int _exp = 0, _level = 0;	//�÷��̾� ����ġ �� ���� 0���� ���� �� ����

void GameStartSelect();	//���Ӽ���(����, ����, ����)
void GameStart();		//���ӽ���
void GameExplain();		//���Ӽ���
void MoveRoom();
void InsertRoom(int x, int y);
void NormalMonster();
void BossMonster();
//void GameExit();		//��������

void main()
{
	srand(time(NULL));
	GameStartSelect();	
}

void GameStartSelect()
{
	int selectnum = 0;
	::printf("����������������������������������������\n");
	::printf("��    Text  RPG     ��\n");
	::printf("����������������������������������������\n");
	::printf("1. ���ӽ���\n");
	::printf("2. ���Ӽ���\n");
	::printf("3. ��������\n");
	::printf("��ȣ�Է�: ");
	cin >> selectnum;
	system("cls"); //�ܼ�â �ʱ�ȭ
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
		system("cls"); //�ܼ�â �ʱ�ȭ
		printf("�ùٸ��� ���� �Է��Դϴ�.\n");
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
		system("cls"); //�ܼ�â �ʱ�ȭ
		::printf("����������������������������������������\n");
		::printf("��    Text  RPG     ��\n");
		::printf("����������������������������������������\n");
		::printf("���� ü��: %d / %d\n", _nowHp, _maxHp);
		::printf("���� ���ݷ�: %d ~ %d\n", _attackDmg, _attackDmg + 2);
		::printf("���� ����: %d(%d/%d)\n", _level, _exp, _level*5 + 5);
		::printf("���� ��ġ: X(%d), Y(%d) - ������ġ(3, 3)\n", _x, _y);
		::printf("0(��), 1(��), 2(��), 3(��)�� ����: ");
		MoveRoom();
	}
}

void GameExplain()
{
	int userInput;
	::printf("������������������������������������������������������\n");
	::printf("��    Text  RPG  Explain   ��\n");
	::printf("������������������������������������������������������\n");
	::printf("������ �����ϸ� 0(��), 1(��), 2(��), 3(��)�� �����Ͽ� �̵��� �� �ִ�.\n");
	::printf("��ĭ ������ ������ �濡 �����Ѵ�.\n");
	::printf("�濡���� ���Ͱ� �����ϴµ� ���ݷ�(1~10)�� ü��(5~10)�� �������� �����Ǿ� �����Ѵ�.\n");
	::printf("���Ϳ��� �������� ���� �� ������������ ġ��Ÿ������(��), �⺻������(���), ���ѵ�����(�й�)�� ������.\n");
	::printf("�÷��̾��� ü���� 50 ���ݷ��� 3~5�̸� ���͸� ������ ���� ����ġ�� 2~5�������� ȹ���Ѵ�.\n");
	::printf("�������� ü���� �������� ���ݷ� 1, ü���� 5 �����Ѵ�.\n");
	::printf("x(3), y(3)�� �濡�� ������ ������ ������ ü���� 50 ���ݷ��� 20�̴�.\n");
	::printf("�¸�����: ������ �¸�\n");
	::printf("�й�����: ü���� 0���Ͻ� ����\n");
	::printf("�ƹ� ���ڸ� �Է��ϼ���: ");
	cin >> userInput;
	system("cls"); //�ܼ�â �ʱ�ȭ
	GameStartSelect();
}

void MoveRoom()
{
	int moveWay;
	cin >> moveWay;
	switch (moveWay)
	{
	case 0:	//��
		_y++;
		InsertRoom(_x, _y);
		break;
	case 1: //��
		_y--;
		InsertRoom(_x, _y);
		break;
	case 2: //��
		_x--;
		InsertRoom(_x, _y);
		break;
	case 3: //��
		_x++;
		InsertRoom(_x, _y);
		break;
	default:
		break;
	}
}

void InsertRoom(int x, int y)
{
	if (x == 3 && y == 3) //������ ����
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
	int mobHp = rand() % 6 + 5; // ���� ü�� 5~10
	int mobNowHp = mobHp;
	int mobDmg = rand() % 10 + 1; // ���� ���ݷ� 1~10
	while (_nowHp > 0 && mobNowHp > 0)
	{
		system("cls"); //�ܼ�â �ʱ�ȭ
		::printf("����������������������������������������������������������������������\n");
		::printf("��    Text  RPG  NormalMonster     ��\n");
		::printf("����������������������������������������������������������������������\n");
		::printf("���� ü��: %d / %d\n", _nowHp, _maxHp);
		::printf("���� ���ݷ�: %d ~ %d\n", _attackDmg, _attackDmg + 2);
		::printf("���� ����: %d(%d/%d))\n", _level, _exp, _level * 5 + 5);
		::printf("���� ü��: %d/%d ���ݷ�: %d\n", mobNowHp, mobHp, mobDmg);
		::printf("����(0), ����(1), ��(2) �Է�: ");
		cin >> myHand; //�÷��̾� ���������� �Է�
		mobHand = rand() % 3; //���� ���������� ���� ����
		::printf("�÷��̾ �� ��: ");
		switch (myHand)
		{
		case 0:
			::printf("����\n");
			break;
		case 1:
			::printf("����\n");
			break;
		case 2:
			::printf("��\n");
			break;
		default:
			break;
		}
		::printf("���Ͱ� �� ��: ");
		switch (mobHand)
		{
		case 0:
			::printf("����\n");
			break;
		case 1:
			::printf("����\n");
			break;
		case 2:
			::printf("��\n");
			break;
		default:
			break;
		}
		if (myHand == mobHand) {
			::printf("�����ϴ�. ������ %d�� �����ϴ�.\n", _attackDmg + 1);
			mobNowHp -= (_attackDmg + 1);
		}
		else if (myHand == 0) {
			if (mobHand == 1) {
				::printf("���Ͱ� �̰���ϴ�. ������ %d�� �����ϴ�.\n", _attackDmg);
				mobNowHp -= _attackDmg;
			}
			if (mobHand == 2) {
				::printf("�÷��̾ �̰���ϴ�. ������ %d�� �����ϴ�.\n", _attackDmg + 2);
				mobNowHp -= (_attackDmg + 2);
			}
		}
		else if (myHand == 1) {
			if (mobHand == 2) {
				::printf("���Ͱ� �̰���ϴ�. ������ %d�� �����ϴ�.\n", _attackDmg);
				mobNowHp -= _attackDmg;
			}
			if (mobHand == 0) {
				::printf("�÷��̾ �̰���ϴ�. ������ %d�� �����ϴ�.\n", _attackDmg + 2);
				mobNowHp -= (_attackDmg + 2);
			}
		}
		else if (myHand == 2) {
			if (mobHand == 1) {
				::printf("���Ͱ� �̰���ϴ�. ������ %d�� �����ϴ�.\n", _attackDmg);
				mobNowHp -= _attackDmg;
			}
			if (mobHand == 0) {
				::printf("�÷��̾ �̰���ϴ�. ������ %d�� �����ϴ�.\n", _attackDmg + 2);
				mobNowHp -= (_attackDmg + 2);
			}
		}
		if (mobNowHp > 0)
		{
			::printf("���Ͱ� ��Ƴ��� �÷��̾ �����ϴ�.\n");
			::printf("������ %d�� �Խ��ϴ�.\n", mobDmg);
			_nowHp -= mobDmg;
			if (_nowHp <= 0) //�÷��̾� ü�� 0 ����
			{
				::printf("��������������������������������������������������������\n");
				::printf("��    Text  RPG  LOSE!!!    ��\n");
				::printf("��������������������������������������������������������\n");
			}
		}
		else
		{
			expUp = rand() % 4 + 2;
			::printf("���͸� �׿����ϴ�.\n");
			::printf("����ġ %d ����\n", expUp);
			_exp += expUp;
			if (_exp >= (_level * 5) + 5)
			{
				_exp -= (_level * 5) + 5;
				_level++;
				_attackDmg++;
				_maxHp += 5;
				_nowHp += 10;
				::printf("!!!������!!!\n");
				::printf("���ݷ� +1, �ִ�ü�� +5, ü��ȸ�� +10\n");
			}
		}
		::printf("���� �� �����ϱ� - �ƹ� ���ڸ� �Է��ϼ���: ");
		cin >> userInput;
	}
}
void BossMonster()
{
	int userInput;
	int myHand = 0, mobHand = 0;
	int mobHp = 50; // �������� ü�� 50
	int mobNowHp = mobHp;
	int mobDmg = 10; // �������� ���ݷ� 10
	while (_nowHp > 0 && mobNowHp > 0)
	{
		system("cls"); //�ܼ�â �ʱ�ȭ
		::printf("����������������������������������������������������������������������\n");
		::printf("��    Text  RPG  BossMonster       ��\n");
		::printf("����������������������������������������������������������������������\n");
		::printf("���� ü��: %d / %d\n", _nowHp, _maxHp);
		::printf("���� ���ݷ�: %d ~ %d\n", _attackDmg, _attackDmg + 2);
		::printf("���� ����: %d(%d/%d))\n", _level, _exp, _level * 5 + 5);
		::printf("���� ü��: %d/%d ���ݷ�: %d\n", mobNowHp, mobHp, mobDmg);
		::printf("����(0), ����(1), ��(2) �Է�: ");
		cin >> myHand; //�÷��̾� ���������� �Է�
		mobHand = rand() % 3; //���� ���������� ���� ����
		::printf("�÷��̾ �� ��: ");
		switch (myHand)
		{
		case 0:
			::printf("����\n");
			break;
		case 1:
			::printf("����\n");
			break;
		case 2:
			::printf("��\n");
			break;
		default:
			break;
		}
		::printf("���Ͱ� �� ��: ");
		switch (mobHand)
		{
		case 0:
			::printf("����\n");
			break;
		case 1:
			::printf("����\n");
			break;
		case 2:
			::printf("��\n");
			break;
		default:
			break;
		}
		if (myHand == mobHand) {
			::printf("�����ϴ�. ������ %d�� �����ϴ�.\n", _attackDmg + 1);
			mobNowHp -= (_attackDmg + 1);
		}
		else if (myHand == 0) {
			if (mobHand == 1) {
				::printf("���Ͱ� �̰���ϴ�. ������ %d�� �����ϴ�.\n", _attackDmg);
				mobNowHp -= _attackDmg;
			}
			if (mobHand == 2) {
				::printf("�÷��̾ �̰���ϴ�. ������ %d�� �����ϴ�.\n", _attackDmg + 2);
				mobNowHp -= (_attackDmg + 2);
			}
		}
		else if (myHand == 1) {
			if (mobHand == 2) {
				::printf("���Ͱ� �̰���ϴ�. ������ %d�� �����ϴ�.\n", _attackDmg);
				mobNowHp -= _attackDmg;
			}
			if (mobHand == 0) {
				::printf("�÷��̾ �̰���ϴ�. ������ %d�� �����ϴ�.\n", _attackDmg + 2);
				mobNowHp -= (_attackDmg + 2);
			}
		}
		else if (myHand == 2) {
			if (mobHand == 1) {
				::printf("���Ͱ� �̰���ϴ�. ������ %d�� �����ϴ�.\n", _attackDmg);
				mobNowHp -= _attackDmg;
			}
			if (mobHand == 0) {
				::printf("�÷��̾ �̰���ϴ�. ������ %d�� �����ϴ�.\n", _attackDmg + 2);
				mobNowHp -= (_attackDmg + 2);
			}
		}
		if (mobNowHp > 0)
		{
			::printf("���Ͱ� ��Ƴ��� �÷��̾ �����ϴ�.\n");
			::printf("������ %d�� �Խ��ϴ�.\n", mobDmg);
			_nowHp -= mobDmg;
			if (_nowHp <= 0) //�÷��̾� ü�� 0 ����
			{
				::printf("��������������������������������������������������������\n");
				::printf("��    Text  RPG  LOSE!!!    ��\n");
				::printf("��������������������������������������������������������\n");
				::printf("�ƹ� ���ڸ� �Է��ϼ���: ");
				cin >> userInput;
			}
		}
		else
		{
			::printf("��������������������������������������������������������\n");
			::printf("��    Text  RPG  WIN!!!     ��\n");
			::printf("��������������������������������������������������������\n");
			::printf("�ƹ� ���ڸ� �Է��ϼ���: ");
			cin >> userInput;
		}
		::printf("���� �� �����ϱ� - �ƹ� ���ڸ� �Է��ϼ���: ");
		cin >> userInput;
	}
}