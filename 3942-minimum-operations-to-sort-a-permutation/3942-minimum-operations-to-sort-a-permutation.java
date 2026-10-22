class Solution {
    public int minOperations(int[] nums) {
        int n = nums.length;
        int startIdx = -1;
        int isIncreasing = 0;

        // increasing의 경우 
        for (int i = 0; i < n; i++)
        {
            // 0이 아니면서 1차이가 안나 
            if (nums[(i + 1) % n] != 0 && 
                nums[i] != 0 && 
                Math.abs(nums[i] -nums[(i + 1) % n]) != 1)
            {
                return -1;
            }
            else if (nums[(i + 1) % n] == 0)
            {
                if (startIdx != -1 && startIdx != (i + 1) % n)
                {
                    return -1;
                }
                startIdx = (i + 1) % n;
            }
            else if (nums[i] == 0)
            {
                if (startIdx != -1 && startIdx != i)
                {
                    return -1;
                }
                startIdx = i;
            }
            else
            {
                int direction = nums[(i + 1) % n] - nums[i];
                if (isIncreasing == 0)
                {
                    isIncreasing = direction;
                }
                else if (isIncreasing * direction == -1)
                {
                    return -1;
                }
            }
        }
        // System.out.println(
        //     "direction: " +  isIncreasing + "\n" +
        //     "startIdx " + startIdx + "\n"
        // );
        // 다음은 
        if (isIncreasing == -1)
        {
            return Math.min(
                startIdx + 2,
                n - startIdx
            );
        }
        return Math.min(
            startIdx,
            n - startIdx + 2
        );

    }
}