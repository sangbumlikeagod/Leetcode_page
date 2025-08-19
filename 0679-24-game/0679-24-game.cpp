class Solution {

private:
    pair<int, int> calc(pair<int, int> first, pair<int, int>second, int way)
    {
        pair<int, int> firstC = first;
        pair<int, int> secondC = second;
        // cout << firstC
        if (way == 0)
        {
            first.second *= secondC.second;
            first.first *= secondC.second;
            second.second *= firstC.second;
            second.first *= firstC.second;

            first.first += second.first;
            
        }
        else if (way == 1)
        {
            first.second *= secondC.second;
            first.first *= secondC.second;
            second.second *= firstC.second;
            second.first *= firstC.second;

            first.first -= second.first;
        }
        else if (way == 2)
        {
            first.second *= secondC.second;
            first.first *= secondC.first;
        }
        else
        {
            first.second *= secondC.first;
            first.first *= secondC.second;
        }
        return first;
        
    }
public:
    int arg[24][4] = {
        {0, 1, 2, 3},
        {0, 1, 3, 2},
        {0, 2, 1, 3},
        {0, 2, 3, 1},
        {0, 3, 1, 2},
        {0, 3, 2, 1},
        {1, 0, 2, 3},
        {1, 0, 3, 2},
        {1, 2, 0, 3},
        {1, 2, 3, 0},
        {1, 3, 0, 2},
        {1, 3, 2, 0},
        {2, 0, 1, 3},
        {2, 0, 3, 1},
        {2, 1, 0, 3},
        {2, 1, 3, 0},
        {2, 3, 1, 0},
        {2, 3, 0, 1},
        {3, 0, 1, 2},
        {3, 0, 2, 1},
        {3, 1, 0, 2},
        {3, 1, 2, 0},
        {3, 2, 0, 1},
        {3, 2, 1, 0}
    };
    bool judgePoint24(vector<int>& cards) {
        for(int xx = 0; xx < 24; xx++)
        {
            vector<int> cardsC(4, 0);
            for (int x = 0; x < 4; x++)
            {
                cardsC[x] = cards[arg[xx][x]];
            }
            for (int i = 1; i <= 3; i++)
            {
                vector<pair<int, int>> cardsCopy(4, {1, 1});
                for (int x = 0; x <4; x++)
                {
                    cardsCopy[x].first = cardsC[x];
                }
    
                for (int x = 0; x < 4; x++)
                {    
                    vector<pair<int, int>> cardsCC(cardsCopy.begin(), cardsCopy.end());
                    pair<int, int> first = cardsCC[i - 1];
                    pair<int, int> second = cardsCC[i];
                    pair<int, int> res = calc(first, second, x);
                    cardsCC[i - 1] = cardsCC[i] = res;
                    for (int j = 1; j <= 3; j++)
                    {
                        if (j == i) continue;
                        for (int y = 0; y < 4; y++)
                        {        
                            vector<pair<int, int>> cardsCCC(cardsCC.begin(), cardsCC.end());
                            pair<int, int> third = cardsCCC[j - 1];
                            pair<int, int> fourth = cardsCCC[j];
                            pair<int, int> res = calc(third, fourth, y);
                            cardsCCC[j - 1] = cardsCCC[j] = res;
                            if (i == j - 1)
                            {
                                cardsCCC[i - 1] = res;
                            }
                            else if (i - 1 == j)
                            {
                                cardsCCC[i] = res;
                            }
                            
                            for (int k = 1; k <= 3; k++)
                            {
                                if (k == i || k == j) continue;
                                pair<int, int> fifth = cardsCCC[k - 1];
                                pair<int, int> sex = cardsCCC[k];
    
                                for (int z = 0; z < 4; z++)
                                {
                                        pair<int, int> answer = calc(fifth, sex, z);
                                        if (answer.second && answer.first % answer.second == 0 && answer.first / answer.second == 24)
                                        {   
                                            return true;
                                        }
                                }
                            }
                            
                        }
                    }
                    
                }
            }
        }
        return false;
    }
};