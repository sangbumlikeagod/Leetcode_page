class Solution {
public:
    int maximumSum(vector<int>& nums) {
        priority_queue<int> s[100];
        for (int num : nums)
        {
            int numC = num;
            int tmp = 0;
            while (numC)
            {
                tmp += numC % 10;
                numC /= 10;
            }
            s[tmp].push(num);
        }

        int answer = -1;
        for (int i = 0; i < 100; i++)
        {
            int tmp = -1;
            if (s[i].size() >= 2)
            {
                tmp = s[i].top();
                s[i].pop();
                tmp += s[i].top();
            }
            answer = max(answer, tmp);
        }
        return answer;
    }
};