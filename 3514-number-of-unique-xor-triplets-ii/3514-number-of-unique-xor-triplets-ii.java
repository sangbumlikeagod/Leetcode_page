class Solution {
    public int uniqueXorTriplets(int[] nums) {
        int n = nums.length;
        int[] xxx = new int[2048];
        int[] answer = new int[2048];
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                xxx[nums[i] ^ nums[j]] = 1;
            }
        }
        for (int i = 0; i < 2048; i++)
        {
            if (xxx[i] == 1)
            {
                for (int j = 0; j < n; j++)
                {
                    answer[i ^ nums[j]] = 1;
                }
            }
        }
        return Arrays.stream(answer).sum();
    }
}