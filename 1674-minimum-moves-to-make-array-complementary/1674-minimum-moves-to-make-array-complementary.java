class Solution {
    private int upperBound(int target, List<Integer> args){
        int l = 0, r = args.size();
        while (l < r)
        {
            int m = (l + r) / 2;
            if (args.get(m) <= target)
            {
                l = m + 1;
            }
            else
            {
                r = m;
            }
        }
        return l;
    }
    public int minMoves(int[] nums, int limit) {
        Map<Integer, Integer> sums = new HashMap<>();
        int n = nums.length;
        for (int i = 0; i < n / 2; i++)
        {
            int sm = nums[i] + nums[n - i - 1];
            sums.put(sm, sums.getOrDefault(sm, 0) + 1);
        }
        int answer = n / 2;
        // 하나만 바꾸는 걸로 안될 수도 있음
        // map iter은 뭐냐

        List<Integer> minCoverage = new ArrayList<>();
        List<Integer> maxCoverage = new ArrayList<>();

        for (int i = 0; i < n / 2; i++)
        {

            minCoverage.add(Math.min(nums[i], nums[n - i - 1]) + 1);
            maxCoverage.add(Math.max(nums[i], nums[n - i - 1]) + limit);
        }
        Collections.sort(minCoverage);
        Collections.sort(maxCoverage);
        // 어차피 중간에 있을거라는 생각 
        // Collections.binarySearch(arg0, arg1)
        // System.out.println(minCoverage);
        // System.out.println(maxCoverage);
        
        for (Integer key : sums.keySet())
        {
            // key 쪽 빼고는 전부 1개씩은 바꿔야된다고 가정한 것 
            int base = (n / 2) - sums.get(key);
            // 내 합, 자신의 min coverage보다 확실히 작은 애들은 두개씩 더해줘야한다
            int idx = Collections.binarySearch(minCoverage, key + 1);
            // System.out.println(base + " " + key);
            if (idx < 0) {
                // 나보다 확실히 작은놈이 몇개인가? 
                idx *= -1;
                idx --;
                base += (n / 2) - idx;
            }
            else
            {
                base += (n / 2) - idx;
            }
            // System.out.print(" minCoverage에서 내 합보다 확실히 오른족에 있는 놈의 개수 " + idx + " ");
            int idx2 = upperBound(key - 1, maxCoverage);
            // if (idx2 < 0) {
            //     // 나보다 확실히 작은놈들 개수 
            //     idx2 *= -1;
            //     idx2--;
            //     base += idx2;
            // }
            // else
            // {
            //     idx2--;
            //     base += idx2;
            // }
            {
                base += idx2;
            }
            // System.out.println(idx2 + " " + base);

            answer = Math.min(answer, base);
        }
        return answer;
    }
}