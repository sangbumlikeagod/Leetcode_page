class Solution {
public: 
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> answer;

        unordered_set<int> current;
        for (int x : arr)
        {
            unordered_set<int> nexts;
            nexts.insert(x);

            // 전의 인덱스만 보면돼용
            for (int y : current)
            {
                nexts.insert(y | x);
            }

            answer.insert(nexts.begin(), nexts.end());
            current = nexts;
        }
        return answer.size();
    }
};