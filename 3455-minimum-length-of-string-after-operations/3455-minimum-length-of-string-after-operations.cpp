class Solution {
public:
    int minimumLength(string s) {
        vector<int> asc(26, 0);
        for (char c : s)
        {
            asc[c - 'a']++;
        }
        // 2나 1이 될때까지 2가 된다고 볼 수 있고. 
        int answer = 0;
        for (int i = 0; i < asc.size(); i++)
        {
            if (asc[i] == 0) continue;
            if (asc[i] % 2)
            {
                answer += 1;
            }
            else
            {
                answer += 2;
            }
        }
        return answer;
    }
};