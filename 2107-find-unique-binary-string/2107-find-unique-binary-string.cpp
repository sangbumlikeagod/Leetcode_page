class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        string answer = "";
        for (int i = 0; i < n; i++)
        {
            if (nums[i][i] == '1')
            {
                answer += '0';
            }
            else
            {
                answer += '1';
            }
        }
        return answer;
    }
};