#include <iostream>
#include <ctime>

using namespace std;

enum eBet
{
    HIGH,
    LOW,
    SEVEN
};

struct Card
{
    int Index;

    void Print();
    void PrintHideNumber();
    void Swap(Card& another);
};

void PrintFiveCard();
void BetMoney();
void EvaluateResult();
int CalculatePoints(int hiddenCardIndex, eBet bet);

Card _card[52] = {};
int _gameMoney = 1000;
int _round = 0;
int _betMoney = 0;
int _betPosition = -1;

int main()
{
    srand(time(NULL));

    for (int i = 0; i < 52; i++)
    {
        _card[i].Index = i;
    }
    //����
    for (int i = 0; i < 10000; i++)
    {
        int src = rand() % 52;
        int dst = rand() % 52;

        _card[src].Swap(_card[dst]);
    }

    while (_gameMoney > 0 && _round < 47)
    {
        PrintFiveCard();
        BetMoney();
        EvaluateResult();
    }

    cout << "���� ����" << endl;
    return 0;
}

void Card::Print()
{
    // Index�� ����
    // 0 ~ 12 �����̽� A ~ �����̽� K ����  (13���� ���������� 0)
    // 13 ~ 25 ���̾� A ~ ���̾� K ����    (13���� ���������� 1)
    // 26 ~ 38 ��Ʈ A ~ ��Ʈ K ����        (13���� ���������� 2)
    // 39 ~ 51 Ŭ�ι� A ~ Ŭ�ι� K ����   (13���� ���������� 3)

    //���� ���
    switch (Index / 13)
    {
    case 0:
        cout << "\t��";
        break;
    case 1:
        cout << "\t��";
        break;
    case 2:
        cout << "\t��";
        break;
    case 3:
        cout << "\t��";
        break;
    }

    //���� (A ~ k)
    switch (Index % 13 + 1)
    {
    case 1:
        cout << " A";
        break;
    case 11:
        cout << " J";
        break;
    case 12:
        cout << " Q";
        break;
    case 13:
        cout << " K";
        break;
    default:
        cout << " " << Index % 13 + 1;
        break;
    }
}

void Card::PrintHideNumber()
{
    //���� ���
    switch (Index / 13)
    {
    case 0:
        cout << "\t��";
        break;
    case 1:
        cout << "\t��";
        break;
    case 2:
        cout << "\t��";
        break;
    case 3:
        cout << "\t��";
        break;
    }
    //���ڴ� ������ ���
    cout << " XX";
}

void Card::Swap(Card& another)
{
    int temp = this->Index;
    this->Index = another.Index;
    another.Index = temp;
}

void PrintFiveCard()
{
    cout << "������:";
    for (int i = 0; i < 5; i++)
    {
        if (i == 4)
        {
            _card[i + _round].PrintHideNumber();
        }
        else
        {
            _card[i + _round].Print();
        }
    }
    cout << endl;
    _round++;
}

void BetMoney()
{
    do
    {
        cout << "���� �����ݾ�: " << _gameMoney << "��" << endl;
        cout << "������ �ݾ��� �Է�:";
        cin >> _betMoney;
        if (_betMoney > _gameMoney)
        {
            cout << "������ �ݾ��� �����ݾ׺��� ���� �Է����ּ���." << endl;
        }
    } while (_betMoney > _gameMoney);

    do
    {
        cout << "������ ������ �Է�(����(0), �ο�(1), ����(2)):";
        cin >> _betPosition;
    } while (_betPosition < 0 || _betPosition > 2);
}

void EvaluateResult()
{
    int hiddenCardIndex = _round + 3;

    switch (_betPosition)
    {
    case HIGH:
        if (_card[hiddenCardIndex].Index % 13 + 1 >= 7)
        {
            _gameMoney += CalculatePoints(hiddenCardIndex, HIGH);
        }
        else
        {
            _gameMoney -= _betMoney;
        }
        break;
    case LOW:
        if (_card[hiddenCardIndex].Index % 13 + 1 <= 7)
        {
            _gameMoney += CalculatePoints(hiddenCardIndex, LOW);
        }
        else
        {
            _gameMoney -= _betMoney;
        }
        break;
    case SEVEN:
        if (_card[hiddenCardIndex].Index % 13 + 1 == 7)
        {
            _gameMoney += CalculatePoints(hiddenCardIndex, SEVEN);
        }
        else
        {
            _gameMoney -= _betMoney;
        }
        break;
    }

    cout << "���� �����ݾ�: " << _gameMoney << "��" << endl;
}

int CalculatePoints(int hiddenCardIndex, eBet bet)
{
    switch (bet)
    {
    case HIGH:
        return _betMoney * 2;
    case LOW:
        return _betMoney * 2;
    case SEVEN:
        return _betMoney * 10;
    default:
        return 0;
    }
}