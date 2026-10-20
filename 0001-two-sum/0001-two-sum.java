class Solution {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer> maps = new HashMap<>();
        Set<Integer> sets = new HashSet<>();
        int n = nums.length;
        maps.put(1, 1);
        sets.add(1);
        for (int i = 0; i < nums.length; i++)
        {  
            maps.put(nums[i], i);
        }
        for (int i = 0; i < n; i++)
        {
            int complement = target - nums[i];
            if (maps.containsKey(complement) && maps.get(complement) != i)
            {
                return new int[] {i, maps.get(complement)};
            }
        }
        return new int[] {};
 
    }
}