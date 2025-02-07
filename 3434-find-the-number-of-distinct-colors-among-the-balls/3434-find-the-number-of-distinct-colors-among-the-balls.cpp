class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        vector<int> answer {};
        // vector<int> checkLS(limit + 1, -1);
        unordered_map<int, int> checkLS;
        unordered_map<int, int> colored;
        for (vector<int>& query : queries)
        {
            int prev;
            if (checkLS.find(query[0]) != checkLS.end())
            {
                prev = checkLS[query[0]];
                if (colored.find(prev) != colored.end())
                {
                    if (colored[prev] == 1)
                    {
                        colored.erase(prev);
                    }
                    else
                    {
                        colored[prev]--;
                    }
                }
            }

            checkLS[query[0]] = query[1];
            colored[query[1]]++;
            answer.push_back(colored.size());
        }
        return answer;
    }
};