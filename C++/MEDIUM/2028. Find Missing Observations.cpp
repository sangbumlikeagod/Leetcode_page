class Solution
{
public:
    vector<int> missingRolls(vector<int> &rolls, int mean, int n)
    {
        int total = mean * (rolls.size() + n);
        int subTotal = 0;
        for (int roll : rolls)
        {
            subTotal += roll;
        }

        int remain = total - subTotal;
        if (remain < n || remain > n * 6)
        {
            return vector<int>{};
        }

        vector<int> answer(n, 0);
        int index = 0;
        while (remain)
        {
            answer[index]++;
            remain--;
            index = index == n - 1 ? 0 : index + 1;
        }
        return answer;
    }
};