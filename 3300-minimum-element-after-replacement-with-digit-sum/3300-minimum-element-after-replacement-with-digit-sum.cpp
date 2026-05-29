class Solution {
public:
    int minElement(vector<int>& nums) {
        int answer = 100;
        for (int num : nums)
        {
            int local = 0;
            while (num)
            {
                local += num % 10;
                num /= 10;
            }
            answer = min(answer, local);
        }
        return answer;
    }
};