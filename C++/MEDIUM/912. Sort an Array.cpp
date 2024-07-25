class Solution
{

public:
    vector<int> sortArray(vector<int> &nums)
    {
        vector<int> answer{};
        vector<int> countNumP50000(100001, 0);
        int maxNum = -50000;
        int minNum = 50000;
        for (int num : nums)
        {
            countNumP50000[num + 50000]++;
            minNum = minNum > num ? num : minNum;
            maxNum = maxNum < num ? num : maxNum;
        }

        for (int i = minNum + 50000; i <= maxNum + 50000; i++)
        {
            for (int j = 0; j < countNumP50000[i]; j++)
            {
                answer.push_back(i - 50000);
            }
        }
        return answer;
    }
};