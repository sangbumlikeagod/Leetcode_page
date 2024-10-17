class Solution
{
public:
    int maximumSwap(int num)
    {
        vector<int> ansArr;
        while (num)
        {
            ansArr.push_back(num % 10);
            num /= 10;
        }
        for (int i = ansArr.size() - 1; i; i--)
        {
            int localM = i;
            for (int j = i - 1; j >= 0; j--)
            {
                if (ansArr[i] < ansArr[j])
                {
                    if (ansArr[localM] <= ansArr[j])
                    {
                        localM = j;
                    }
                }
            }
            if (localM != i)
            {
                swap(ansArr[i], ansArr[localM]);
                break;
            }
        }

        int answer = 0;
        while (!ansArr.empty())
        {
            answer *= 10;
            answer += ansArr.back();
            ansArr.pop_back();
        }
        return answer;
    }
};