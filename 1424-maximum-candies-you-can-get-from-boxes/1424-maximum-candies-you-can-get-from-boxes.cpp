class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        unordered_map<int, int> keysMap;
        unordered_map<int, int> boxesMap;

        queue<int> q1, q2;

        
        int answer = 0;
        for (int arg : initialBoxes)
            {
                if (status[arg])
                {
                    q1.push(arg);
                }
                else
                {
                    boxesMap[arg]++;
                }
            }
        while (true)
            {
                while (q1.empty() == false)
                    {
                        int next = q1.front();
                        // cout << next << ' ';
                        answer += candies[next];
                        q1.pop();
                        // if (status[next] || keysMap.find(next) != keysMap.end())
                        {
                            for (int box : containedBoxes[next])
                                {
                                    // cout << box << '\t';
                                    if (status[box] || keysMap.find(box) != keysMap.end())
                                    {
                                        if (keysMap.find(box) != keysMap.end())
                                        {
                                            keysMap.erase(box);
                                        }
                                        // 열 수 있다 이러고 넣는거지 바로 넣는거 아님
                                        q2.push(box);
                                    }
                                    else
                                    {
                                        boxesMap[box]++;
                                    }
                                }

                            for (int key : keys[next])
                                {
                                    if (boxesMap.find(key) != boxesMap.end())
                                    {
                                        boxesMap.erase(key);
                                        q2.push(key);
                                        
                                    }
                                    else
                                    {
                                        keysMap[key]++;
                                    }
                                }
                        }
                        // else
                        // {
                        //     boxesMap[next]++;
                        // }
                    }
                // cout << '\n';
                swap(q1, q2);
                if (q1.empty()) break;
            }

        return answer;
    }
};