class Solution {
    public boolean uniformArray(int[] nums1) {
        Arrays.sort(nums1);

        int n = nums1.length;
        int[] odd = new int[n]; 
        int[] even = new int[n]; 

        for (int i = n - 1; i >= 0; i--)
        {
            if (nums1[i] % 2 == 1)
            {
                if (i != n - 1 && even[i + 1] == 0)
                {
                    even[i + 1] = 1;
                }
                // odd[i] = i == 0 ? 1 : odd[i - 1];
                odd[i] = 1;
                // 난 홀순데 이전에 홀수가 있었네?     
            }
            else
            {
                if (i != n - 1 && odd[i + 1] == 0)
                {
                    odd[i + 1] = 1;
                }

                even[i] = i == n - 1 ? 1 : even[i + 1];
            }
        }

        return (odd[0] | even[0]) == 1;
    }
}