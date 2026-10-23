class Solution {
    private int n;
    private long[] prefixRank;
    private List<Integer> candidates;


    public int sortableIntegers(int[] nums) {
        n = nums.length;
        // System.out.println(n);
        int answer = 0;
        candidates = new ArrayList<Integer>();
        int[][] numsWRank = new int[n][2];
        int[] ranks = new int[n];
        prefixRank = new long[n + 1];
        

        
        for (int i = 0; i < n; i++)
        {
            numsWRank[i][0] = nums[i];
            numsWRank[i][1] = i;
        }
        Arrays.sort(numsWRank, (a, b) -> {
            return a[0] - b[0];
        });
        // 여기서 rank를 다시 채운다
        // nums의 지금 값이 rank가 몇인지를 확인하는것

        for (int i = 0; i < n; i++)
        {
            ranks[numsWRank[i][1]] = i;
        }
        for (int i = 0; i < n; i++)
        {
            prefixRank[i + 1] = prefixRank[i] + ranks[i];
        }


        for (int i = 1; i <= n; i++)
        {
            if (n % i == 0)
            {
                candidates.add(i);
            }
        }
        // candidates들을 미리 본다
        // System.out.println(candidates);




        for (int candidate : candidates)
        {
            // st == start
            int isValidCandidate = 1;
            for (int st = 0; st < n; st += candidate)
            {
                if (prefixRank[st] != ((long) st * (st - 1)) / 2)
                {
                    isValidCandidate = 0;
                    break;
                }
                // 정해진 애들만 있다는것은 확인됨 
                int tolerance = 1;
                for (int pt = st; pt < st + candidate; pt++)
                {
                    int next = pt + 1 == st + candidate ? st : pt + 1;
                    if (
                        nums[pt] > nums[next] && 
                        tolerance == 0 
                    )
                    {
                        isValidCandidate = 0;
                        break;
                    }
                    else if (
                        nums[pt] > nums[next] &&
                        tolerance == 1
                    )
                    {
                        tolerance = 0;
                    }
                }
                if (isValidCandidate == 0)
                {
                    break;
                }
            }
            if (isValidCandidate == 1)
            {
                answer += candidate;
            }
        }

        return answer;
    }
}