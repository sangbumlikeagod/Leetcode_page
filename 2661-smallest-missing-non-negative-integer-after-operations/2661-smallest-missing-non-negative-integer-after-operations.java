class Solution {
    public int findSmallestInteger(int[] nums, int value) {
        int answer = 0;

        int n = nums.length;
        Map<Integer, Integer> maps = new HashMap<>();
        for (int i = 0; i < n; i++)
        {
            // while (nums[i] < 0)
            // {
            //     nums[i] += value;
            // }
            if (nums[i] < 0)
            {
                // System.out.println(nums[i] / value + " " + nums[i] % value + " " + ((nums[i] / value) - 1));
                nums[i] -= ((nums[i] / value) - 1) * value;
                // System.out.println(nums[i] + " " + nums[i] % value);
                // System.out.println(nums[i]);
            }

            int next = maps.get(nums[i] % value) != null ? maps.get(nums[i] % value) + 1 : 1;
            maps.put((nums[i] + value) % value, next);
        }
        int start = 0;

        while (true)
        {
            
            if (maps.get(start) != null && maps.get(start) != 0)
            {
                maps.put(Integer.valueOf(start), maps.get(start) - 1);
            }
            else
            {
                break;
            }
            start = (start + 1) % value;
            answer++;
        }
        return answer;
    }
}