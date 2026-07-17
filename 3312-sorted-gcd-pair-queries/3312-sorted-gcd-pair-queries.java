class Solution {
    public int[] gcdValues(int[] nums, long[] queries) {
        int mV = 0;
        for (int num : nums)
        {
            mV = Math.max(mV, num);
        }

        long[] cnts = new long[mV + 1];

        for (int num : nums)
        {
            cnts[num]++;
        }

        for (int i = 1; i <= mV; i++)
        {
            for (int j = i * 2; j <= mV; j += i)
            {
                cnts[i] += cnts[j];
            }
        }
        // System.out.println(Arrays.toString(cnts));


        // 조합을 만들고 
        for (int i = 1; i <= mV; i++)
        {
            cnts[i] = cnts[i] * (cnts[i] - 1) / 2;
        }
        // System.out.println(Arrays.toString(cnts));

        // 조합을 뺸다
        for (int i = mV; i > 0; i--)
        {
            if (cnts[i] != 0)
            {
                for (int j = i * 2; j <= mV; j += i)
                {
                    cnts[i] -= cnts[j];
                }
            }
        }
        
        // System.out.println(Arrays.toString(cnts));
        for (int i = 1; i <= mV; i++)
        {
            cnts[i] += cnts[i - 1];
        }
        // System.out.println(Arrays.toString(cnts));
        
        int[] answer = new int[queries.length];
        
        for (int i = 0; i < queries.length; i++)
        {
            long query = queries[i];
            int l = 1, r = mV;
            while (l < r)
            {
                int m = (l + r) / 2;
                // System.out.println(l + " " + r + " " + m + " " + query+ " " + cnts[i]);
                if (cnts[m] <= (long) query)
                {
                    l = m + 1;
                }
                else
                {
                    r = m;
                }
            }
            answer[i] = l;
        }
        return answer;

        

        
    }
}