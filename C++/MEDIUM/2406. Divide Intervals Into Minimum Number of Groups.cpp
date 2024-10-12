class Solution
{
    map<int, vector<int>> container;

public:
    int minGroups(vector<vector<int>> &intervals)
    {
        int answer = 0;

        for (vector<int> interval : intervals)
        {
            container[interval[0]].push_back(interval[1]);
        }
        while (!container.empty())
        {
            map<int, vector<int>>::iterator begin;
            auto n_begin = container.begin();
            while (n_begin != container.end())
            {
                begin = n_begin;
                int next = (begin->second).back();
                begin->second.pop_back();
                if ((begin->second).empty())
                {
                    container.erase(begin->first);
                }
                n_begin = container.upper_bound(next);
            }
            answer++;
        }

        return answer;
        ;
    }
};