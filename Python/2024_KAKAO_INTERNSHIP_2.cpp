#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> pointout[1000001] = {};
int pointed[1000001] = {0};
int dfs(int init_num, int isEight, int num)
{
    if (pointout[num].empty())
    {
        if (isEight)
        {
            return 3;
        }
        if (init_num == num)
        {
            return 1;
        }
        else
        {
            return 2;
        }
    }
    else if (pointout[num].size() >= 2)
    {
        int nextval = pointout[num][pointout[num].size() - 1];
        pointout[num].pop_back();
        return 3;
    }
    else
    {
        int nextval = pointout[num][pointout[num].size() - 1];
        pointout[num].pop_back();
        return isEight ? dfs(init_num, 1, nextval) : dfs(init_num, 0, nextval);
    }
}

vector<int> solution(vector<vector<int>> edges)
{
    vector<int> answer{0, 0, 0, 0};
    int maxsize = 0;

    for (vector<int> edge : edges)
    {
        pointout[edge[0]].push_back(edge[1]);
        pointed[edge[1]]++;
        maxsize = max(maxsize, edge[0]);
        maxsize = max(maxsize, edge[1]);
    }
    cout << maxsize;
    vector<int> zero_pointed = {};
    for (int i = 0; i <= maxsize; i++)
    {
        if (!pointed[i])
        {
            zero_pointed.push_back(i);
        }
    }

    if (zero_pointed.size() > 1)
    {
        for (int i : zero_pointed)
        {
            if (pointout[i].size() > 1)
            {
                answer[0] = i;
                break;
            }
        }
    }
    else
    {
        answer[0] = zero_pointed[0];
    }

    for (int i : pointout[answer[0]])
    {
        if (!pointout[i].size())
        {
            answer[2]++;
            continue;
        }
        answer[dfs(i, 0, i)]++;
    }

    return answer;
}