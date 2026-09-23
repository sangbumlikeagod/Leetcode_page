class Solution {
    private int BS(int target, List<Integer> arr)
    {
        // target == x - prefixVal 
        // 확실히 큰놈을 찾아서 걔 - 1 인덱스 
        int l = 0, r = arr.size();
        while (l < r)
        {
            int m = (l + r) / 2;
            if (arr.get(m) < target)
            {
                l = m + 1;
            }
            else
            {
                r = m;
            }
        }

        if (l == arr.size() || arr.get(l) != target)
        {
            return 10000000;
        }
        return l;
    }
    public int minOperations(int[] nums, int x) {
        List<Integer> prefixLeft = new ArrayList<>(Arrays.asList(0)); 
        List<Integer> prefixRight = new ArrayList<>(Arrays.asList(0)); 
        int n = nums.length;
        boolean leftFlag = true;
        boolean rightFlag = true;

        for (int i = 0; i < n; i++)
        {
            if (leftFlag && prefixLeft.getLast() + nums[i] <= x)
            {
                long arg = prefixLeft.getLast();
                arg += + nums[i];
                prefixLeft.add((int) arg);
            }
            else 
            {
                leftFlag = false;
            }

            if (rightFlag && prefixRight.getLast() + nums[n - 1 - i] <= x)
            {
                prefixRight.add(prefixRight.getLast() + nums[n - 1 - i]);
            }
            else
            {
                rightFlag = false;
            }
        }
        int answer = n + 1;
        for (int i = 1; i < prefixLeft.size(); i++)
        {
            answer = Math.min(answer, i + BS(x - prefixLeft.get(i), prefixRight));        
        }
        for (int i = 1; i < prefixRight.size(); i++)
        {
            answer = Math.min(answer, i + BS(x - prefixRight.get(i), prefixLeft));
        }

        return answer == n + 1 ? -1 : answer ;
    }
}