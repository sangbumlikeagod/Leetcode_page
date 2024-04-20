#include <string>
#include <vector>
#include <iostream>

using namespace std;

int card_index[1001];
int pair_index[1001];
vector<vector<int>> google[1001];

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
    google[0].push_back(vector<int>{life, coin});
    while (idx < size)
    {
        answer++;

        for (vector<int> i : google[answer])
        {
            int initlife = life;
            if (pair_index[cards[idx]] < idx + 1 && coin)
            {
                coin--;
                initlife++;
            }

            if (pair_index[cards[idx + 1]] < idx + 2 && coin)
            {
                coin--;
                if (pair_index[cards[idx + 1]] == idx)
                {
                    if (coin)
                    {
                        google[answer].push_back(vector<int>{life - 1, coin + 1});
                        initlife++;
                        coin--;
                    }
                }
                else
                {
                    initlife++;
                }
            }

            if (!initlife)
            {
                break;
            }
            initlife--;
            google[answer].push_back(vector<int>{initlife, coin});
            cout << initlife << coin << '\n';
        }
        idx += 2;
    }
    if (idx == size)
        answer++;

    return answer;
}