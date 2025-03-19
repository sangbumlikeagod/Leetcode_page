class Solution {
public:
    int minOperations(vector<int>& nums) {
        
        // 처음을 그냥 둔다
        vector<int> nums2(nums.begin(), nums.end());
        int cnt1 = 0, cnt2 = 0;
        for (int i = 1; i < nums.size() - 2; i++ )
        {
            if (nums[i] == 0)
            {
                for (int j = i; j < i + 3; j++)
                {
                    nums[j] ^= 1;
                }
                cnt1++;
            }
        }
        if (nums[nums.size() - 2] == 0|| nums[nums.size() - 1] == 0 || nums[0] == 0) 
        {
            cnt1 = 100001;
        }

        nums2[0]^= 1;
        nums2[1]^= 1;
        nums2[2]^= 1;
        cnt2 = 1;
        for (int i = 0; i < nums.size() - 2; i++)
        {
             if (nums2[i] == 0)
            {
                for (int j = i; j < i + 3; j++)
                {
                    nums2[j] ^= 1;
                }
                cnt2++;
            }
        }

        if (nums2[nums.size() - 2] == 0 || nums2[nums.size() - 1] == 0) 
        {
            cnt2 = 100001;
        }
        
        if (cnt2 == 100001 && cnt1 == 100001) return -1;
        return min(cnt1, cnt2);
    }
};