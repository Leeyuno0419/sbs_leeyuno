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
    //섞기
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

    cout << "게임 종료" << endl;
    return 0;
}

void Card::Print()
{
    // Index의 값이
    // 0 ~ 12 스페이스 A ~ 스페이스 K 까지  (13으로 나누었을때 0)
    // 13 ~ 25 다이아 A ~ 다이아 K 까지    (13으로 나누었을때 1)
    // 26 ~ 38 하트 A ~ 하트 K 까지        (13으로 나누었을때 2)
    // 39 ~ 51 클로버 A ~ 클로버 K 까지   (13으로 나누었을때 3)

    //문양 출력
    switch (Index / 13)
    {
    case 0:
        cout << "\t♤";
        break;
    case 1:
        cout << "\t◆";
        break;
    case 2:
        cout << "\t♥";
        break;
    case 3:
        cout << "\t♧";
        break;
    }

    //숫자 (A ~ k)
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
    //문양 출력
    switch (Index / 13)
    {
    case 0:
        cout << "\t♤";
        break;
    case 1:
        cout << "\t◆";
        break;
    case 2:
        cout << "\t♥";
        break;
    case 3:
        cout << "\t♧";
        break;
    }
    //숫자는 가려서 출력
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
    cout << "전광판:";
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
        cout << "현재 보유금액: " << _gameMoney << "원" << endl;
        cout << "베팅할 금액을 입력:";
        cin >> _betMoney;
        if (_betMoney > _gameMoney)
        {
            cout << "베팅할 금액을 보유금액보다 적게 입력해주세요." << endl;
        }
    } while (_betMoney > _gameMoney);

    do
    {
        cout << "베팅할 포지션 입력(하이(0), 로우(1), 세븐(2)):";
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

    cout << "현재 보유금액: " << _gameMoney << "원" << endl;
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