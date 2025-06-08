class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> answer;
        for (int i = 0; i < n; i++)
        {
            answer.emplace_back(i + 1);
        }
        sort(answer.begin(), answer.end(), [](int& a, int& b){
            string ac = to_string(a), bc = to_string(b);
            for (int i = 0; i < min(ac.length(), bc.length()); i++)
            {
                if (ac[i] != bc[i])
                {
                    return ac[i] < bc[i];
                }
            }
            return ac.length() < bc.length();
        });
        return answer;
    }
};