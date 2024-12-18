class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> answer (prices.size(), 0);
        for (int i = 0; i < prices.size(); i++)
        {
            int tmp =  prices[i];
            for (int j = i + 1; j < prices.size(); j++)
            {
                if (tmp >= prices[j])
                {
                    tmp -= prices[j];
                    break;
                }
            }
            answer[i] = tmp;
        }
        return answer;
    }
};