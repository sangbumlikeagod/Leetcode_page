class Solution {
    private long MAXI = (long) 1e9 + 7;
    public int numOfSubarrays(int[] arr) {
        int n = arr.length;
        long[][] ss = new long[n][2];

        
        for (int i = 0; i < n; i++)
        {
            int remainder = arr[i] % 2;
            ss[i][remainder] += 1;

            if (i != 0)
            {

                ss[i][
                    (1 + remainder) % 2
                ] += ss[i - 1][1];

                ss[i][
                    remainder
                ]
                 += ss[i - 1][0];

                ss[i][1] %= MAXI;
                ss[i][0] %= MAXI;
            }
        }
        // System.out.println(
        //     Arrays.deepToString(ss)
        // );
        long answer = 0;
        for (int i = 0; i < n; i++)
        {
            answer += ss[i][1];
            answer %= MAXI;
        }

        return (int) answer;

    }
}