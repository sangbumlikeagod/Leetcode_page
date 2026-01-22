class Solution {
    public int minimumPairRemoval(int[] nums) {
        int answer = 0;



        while (true)
        {
            boolean stopQ = true;

            int n = nums.length;
            int tmp = Integer.MAX_VALUE;
            int idx = -1;



            for (int i = 1; i < n; i++)
            {
                if (nums[i - 1] > nums[i])
                {
                    stopQ = false;
                    break;
                }
            }

            // System.out.println(Arrays.toString(nums) + " " + stopQ);
            if (stopQ)
            {
                break;
            }

            int[] newData = new int[n - 1];

            for (int i = 0; i < n - 1; i ++)
            {
                if (nums[i] + nums[i + 1] < tmp)
                { 
                    tmp = nums[i] + nums[i + 1];
                    idx = i;
                }
            }

            // System.out.println(tmp + " " + idx);
            for (int i = 0; i < n; i++)
            {
                if (i == idx)
                {
                    newData[i] = tmp; 
                }
                else if (i == idx + 1)
                {
                    continue;
                }
                else
                {
                    newData[i > idx ? i - 1 : i] = nums[i];
                }
            }
            answer++;
            nums = newData;



        }
        


        return answer;
        

    }
}