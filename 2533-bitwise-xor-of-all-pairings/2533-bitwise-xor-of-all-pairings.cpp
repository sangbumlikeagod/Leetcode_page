class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        vector<int> answers(32, 0);
        int answer = 0;
        int l1 = nums1.size() % 2;
        int l2 = nums2.size() % 2;
        
        for (int num : nums1)
        {
            int index = 0;
            int idxVal = 1;

            while (num >= idxVal)
            {
                if (num & idxVal)
                {
                    if (l2)
                    {
                        answers[index] ^= 1;
                    }
                }
                idxVal <<= 1;
                index++;
            }
        }
        for (int num : nums2)
        {
            int index = 0;
            int idxVal = 1;

            while (num >= idxVal)
            {
                if (num & idxVal)
                {
                    if (l1)
                    {
                        answers[index] ^= 1;
                    }
                }
                idxVal <<= 1;
                index++;
            }
        }
        int val = 1;
        for (int i = 0; i < 32; i++)
        {
            if (answers[i])
            {
                answer += val;
            }
            val <<= 1;
        }
        return answer;
    }
};