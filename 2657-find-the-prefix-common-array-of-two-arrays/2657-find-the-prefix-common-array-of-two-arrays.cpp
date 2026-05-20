class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int> dpA(51, 0);
        vector<int> dpB(51, 0);

        vector<int> answer(A.size(), 0);
        
        for (int i = 0; i < A.size(); i++)
        {
            dpA[A[i]]++;
            dpB[B[i]]++;
            for (int j = 0; j <= 50; j++)
            {
                answer[i] += min(dpA[j], dpB[j]);
            }
        }
        return answer;
    }
};