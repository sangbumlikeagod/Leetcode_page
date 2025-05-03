class Solution {
public:
    string pushDominoes(string dominoes) {
        dominoes = dominoes;
        vector<char> ssss(dominoes.length(), '.');
        vector<pair<int, int>> monotonicStack {};

        int lastR = -1;
        for (int i = 0; i < dominoes.length(); i++)
        {
            char c = dominoes[i];
            if (c == 'R')
            {
                if (lastR != -1)
                {
                    while (monotonicStack.empty() == false)
                    {
                        if (monotonicStack.back().first == -1 ) break;
                        ssss[monotonicStack.back().second] = 'R';
                        monotonicStack.pop_back();
                    }
                }
                lastR = i;
                ssss[i] = 'R';
                monotonicStack.push_back({-1, i});
            }
            else if (c == 'L')
            {
                ssss[i] = 'L';
                int distance = 1;
                while (monotonicStack.empty() == false)
                {
                    if (monotonicStack.back().first == -1)
                    {
                        break;
                    }
                    if (distance > monotonicStack.back().first)
                    {
                        ssss[monotonicStack.back().second] = 'R';
                    }
                    else if (distance < monotonicStack.back().first)
                    {
                        ssss[monotonicStack.back().second] = 'L';
                    }
                    monotonicStack.pop_back();
                    distance++;
                }
                lastR = -1;
            }
            else
            {
                if (lastR != -1)
                {
                    monotonicStack.push_back({i - lastR, i});
                }
                else
                {
                    monotonicStack.push_back({100001, i});
                }
            }
        }
        if (lastR != -1)
        {
            while (monotonicStack.empty() == false)
            {
                if (monotonicStack.back().first == -1 ) break;
                ssss[monotonicStack.back().second] = 'R';
                monotonicStack.pop_back();
            }
        }
        return string(ssss.begin(), ssss.end());
    }
};