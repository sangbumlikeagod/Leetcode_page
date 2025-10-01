class Solution {
    public int numWaterBottles(int numBottles, int numExchange) {
        int answer = 0;
        int remain = 0;
        while (numBottles > 0)
        {
            answer += numBottles;
            remain += numBottles % numExchange;
            numBottles /= numExchange;
            if (remain >= numExchange)
            {
                numBottles += (remain / numExchange);
                remain %= numExchange;
            }
        }
        return answer;
    }
}