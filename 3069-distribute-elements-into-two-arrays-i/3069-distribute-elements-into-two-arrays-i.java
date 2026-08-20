class Solution {
    public int[] resultArray(int[] nums) {
        List<Integer> arr1 = new ArrayList<Integer>();
        List<Integer> arr2 = new ArrayList<Integer>();
        
        arr1.add(nums[0]);
        arr2.add(nums[1]);

        int n = nums.length;
        for (int i = 2; i < n; i++)
        {
            if (arr1.getLast() > arr2.getLast())
            {
                arr1.add(nums[i]);
            }
            else
            {
                arr2.add(nums[i]);
            }
        }
        arr1.addAll(arr2);
        int[] answer = arr1.stream().mapToInt(Integer::intValue).toArray();
        return answer;
    }
}