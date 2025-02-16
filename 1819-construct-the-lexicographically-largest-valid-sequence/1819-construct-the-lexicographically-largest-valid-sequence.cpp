class Solution {
    bool backTrcaking(int index, vector<int>& answer, vector<int>& visited, int n)
    {
        // cout << index << '\t';
        // for (int i = 0; i < 2 * n - 1; i++)
        // {
        //     cout << answer[i] << ' ';
        // }
        // cout << '\n';
        if (index == 2 * n - 1)
        {
            return true;
        }
        if (answer[index] != 0)
        {
            return backTrcaking(index + 1, answer, visited, n);
        }
        for (int i = n; i > 0; i--)
        {
            if (visited[i] == 0 && (i == 1 || index + i < answer.size()) && (i == 1 || answer[index + i] == 0))
            {
                visited[i] = 1;
                answer[index] =  i;
                if (i != 1)
                {
                    answer[index + i] = i;
                }
                int tmp = backTrcaking(index + 1, answer, visited, n);
                if (tmp == true) return true;
                visited[i] = 0;
                answer[index] = 0;
                if (i != 1)
                {
                    answer[index + i] = 0;
                }
            }
        }
        return false;
    }
public:
    vector<int> constructDistancedSequence(int n) {
        vector<int> answer (2 * n - 1, 0);
        vector<int> visited (n + 1, 0);
        backTrcaking(0, answer, visited, n);
        return answer;
    }
};