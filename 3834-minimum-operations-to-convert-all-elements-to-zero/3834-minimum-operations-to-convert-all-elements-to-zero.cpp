class Solution {
public:
    int minOperations(vector<int>& nums) {

        nums.push_back(0);
        vector<int> stacks {};
        int answer = 0;
        for (int num : nums)
            {
                int last = -1;
                while (stacks.empty() == false && stacks.back() > num)
                    {
                        if (last != stacks.back())
                        {
                            answer++;
                            last = stacks.back();
                        }
                        stacks.pop_back();
                    }
                stacks.push_back(num);
            }
        return answer;
    }
    
};