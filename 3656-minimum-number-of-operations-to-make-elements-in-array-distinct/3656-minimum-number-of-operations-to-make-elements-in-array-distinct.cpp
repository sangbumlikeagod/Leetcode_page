class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_map<int, int> uom;
        int nod = 0;
        for (int num : nums)
        {
            if (uom.find(num) != uom.end())
            {
                if (uom[num] == 1)
                {
                    nod++;
                }
            }
            uom[num]++;
        }
        int answer = 0;
        int idx = 0;
        while(nod > 0)
        {
            for (int i = 0; i < 3; i++)
            {
                if (idx < nums.size())
                {
                    int num = nums[idx];
                    uom[num]--;
                    if (uom[num] == 1)
                    {
                        nod--;
                    }
                    idx++;
                }
            }
            answer++;
        }
        return answer;
    }
};