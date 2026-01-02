class Solution {
    public int repeatedNTimes(int[] nums) {
        HashMap<Integer,Integer> maps = new HashMap<>();

        for (int num : nums)
            {
                if (maps.get(num) != null)
                {
                    return num;
                }
                else
                {
                    maps.put(num, 1);
                }
            }
        return -1;
    }
}