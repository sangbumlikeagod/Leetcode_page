#include <string>
#include <vector>
#include <iostream>

using namespace std;

int card_index[1001];
int pair_index[1001];

int solution(int coin, vector<int> cards)
{
    int answer = 0;
    int size = cards.size();
    for (int i = 0; i < size; i++)
    {
        card_index[cards[i]] = i;
    }
    for (int i = 0; i < size; i++)
    {
        pair_index[cards[i]] = card_index[size + 1 - cards[i]];
    }

    int life = 0;
    for (int i = 0; i < size / 3; i++)
    {
        if (pair_index[cards[i]] < size / 3)
        {
            life++;
        }
    }
    life /= 2;
    int idx = size / 3;
    int oneOone = 0;
    int oneOtwo = 0;
    while (idx < size)
    {
        answer++;
        if (pair_index[cards[idx + 1]] == idx)
        {
            oneOtwo++;
        }
        else
        {
            if (pair_index[cards[idx]] < idx)
            {
                if (pair_index[cards[idx]] < size / 3)
                {
                    oneOone++;
                }
                else
                {
                    oneOtwo++;
                }
            }
            if (pair_index[cards[idx + 1]] < idx)
            {
                if (pair_index[cards[idx + 1]] < size / 3)
                {
                    oneOone++;
                }
                else
                {
                    oneOtwo++;
                }
            }
        }

        if (!life)
        {
            if (!coin)
            {
                break;
            }
            if (oneOone)
            {
                oneOone--;
                coin--;
                life++;
            }
            else
            {
                if (coin > 1 && oneOtwo)
                {
                    oneOtwo--;
                    coin -= 2;
                    life++;
                }
                else
                {
                    break;
                }
            }
        }

        life--;
        idx += 2;
    }
    if (idx == size)
        answer++;
    return answer;
}