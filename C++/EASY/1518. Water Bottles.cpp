class Solution
{
public:
    int numWaterBottles(int numBottles, int numExchange)
    {
        int answer = numBottles - numBottles % numExchange;

        int remain = numBottles % numExchange + numBottles / numExchange;

        while (remain >= numExchange)
        {
            answer += remain - remain % numExchange;
            remain = remain % numExchange + remain / numExchange;
        }
        return answer + remain;
    }
};