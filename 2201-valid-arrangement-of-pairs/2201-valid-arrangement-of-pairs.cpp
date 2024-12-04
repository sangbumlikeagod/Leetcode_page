class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int, vector<int>> adjList;
        unordered_map<int, int> in;
        unordered_map<int, int> out;

        for (vector<int> pair : pairs)
        {
            adjList[pair[1]].push_back(pair[0]);
            in[pair[1]]++;
            out[pair[0]]++;
        }
        int s = pairs[0][0];
        auto node = adjList.begin();
        while (node != adjList.end())
        {
            int idx = node -> first;
            if (in[idx]== out[idx] + 1)
            {
                s = idx;
                break;
            }
            node++;
        }
        vector<vector<int>> answer {};
        vector<int> answer_1 {};
        vector<int> stackTop {s};

        while (stackTop.empty() == false)
        {
            s = stackTop.back();
            if (!in[s])
            {
                answer_1.push_back(s);
                stackTop.pop_back();
            }
            else
            {
                in[s]--;
                int tmp = adjList[s].back();
                stackTop.push_back(tmp);
                adjList[s].pop_back();
            }
        }

        for (int i = 1; i < answer_1.size(); i++)
        {
            answer.push_back(vector<int> {answer_1[i - 1], answer_1[i]});
        }
        return answer;

    }
};