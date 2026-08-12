class Solution {
    public int maxSubarrayLength(int[] nums, int k) {
        int l = 0, r = 0;
        int n = nums.length;
        HashMap<Integer, Integer> hmap = new HashMap<>();
        
        // Queue<Integer> q = new LinkedList<>();

        int answer = 0;

        while (r < n)
        {
            int nn = hmap.getOrDefault(nums[r], 0) + 1;
            hmap.put(nums[r], nn);
            if (nn > k)
            {
                // System.out.println(" " + nn); 
                while (hmap.get(nums[r]) > k)
                {
                    hmap.put(nums[l], hmap.get(nums[l]) - 1);
                    l++;
                }
            }
            // hmap.put(nums[r], nn);
            r++;
            // System.out.println(l + " " + r + " " + hmap);
            answer = Math.max(answer, r - l);
        }
        answer = Math.max(answer, r - l);

        return answer;
    }
}