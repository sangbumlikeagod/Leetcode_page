class Solution {
    public int longestBalanced(int[] nums) {
        int n = nums.length;

        HashMap<Integer, Integer> oddCache = new HashMap<>();
        HashMap<Integer, Integer> evenCache = new HashMap<>();

        int answer = n;
        while (answer > 0)
        {
            oddCache.clear();
            evenCache.clear();

            for (int r = 0; r < answer; r++)
            {
                if (nums[r] % 2 == 1)
                {
                    oddCache.put(nums[r], oddCache.getOrDefault(nums[r], 0) + 1);
                }
                else
                {
                    evenCache.put(nums[r], evenCache.getOrDefault(nums[r], 0) + 1);
                }
            }
            for (int i = 0; i < n - answer; i++)
            {
                if (evenCache.size() == oddCache.size())
                {
                    return answer;
                }
                if (nums[i] % 2 == 1)
                {
                    oddCache.put(nums[i], oddCache.get(nums[i]) - 1);
                    if (oddCache.get(nums[i]) == 0)
                    {
                        System.out.println("get rid of " + nums[i]);
                        oddCache.remove(nums[i]);
                    }
                }
                else
                {
                    evenCache.put(nums[i], evenCache.get(nums[i]) - 1);
                    if (evenCache.get(nums[i]) == 0)
                    {
                        evenCache.remove(nums[i]);
                    }
                }

                if (nums[i + answer] % 2 == 1)
                {
                    oddCache.put(nums[i + answer], oddCache.getOrDefault(nums[i + answer], 0) + 1);
                }
                else
                {
                    evenCache.put(nums[i + answer], evenCache.getOrDefault(nums[i + answer], 0) + 1);
                }
            }

            if (evenCache.size() == oddCache.size())
            {
                return answer;
            }
            answer--;
        }
        return answer;
    }
}