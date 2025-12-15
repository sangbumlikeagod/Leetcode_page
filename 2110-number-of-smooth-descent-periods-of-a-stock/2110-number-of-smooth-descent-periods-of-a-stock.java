class Solution {
    public long getDescentPeriods(int[] prices) {
        long answer = 0;
        int chunk = 1;
        int last = -1;
        for (int price : prices)
        {
            if (price == last - 1)
            {
                chunk++;
            }
            else
            {
                answer += ((long) chunk * (chunk + 1)) / 2;
                chunk = 1;
            }
            last = price;
        }
        answer += ((long) chunk * (chunk + 1)) / 2;
        return answer - 1;
    }
}