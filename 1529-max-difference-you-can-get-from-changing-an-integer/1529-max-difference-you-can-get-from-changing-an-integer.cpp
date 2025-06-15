class Solution {
    int diff(int num, int lal, int target)
    {
        int digit = 1;
        int answer = 0;
        while (num) 
        {
            if (num % 10 == target )
            {
                if (num > 10 || lal != 0)
                {
                    answer += (lal - num % 10) * digit;
                }
                else 
                {
                    return INT_MIN + 1;
                }
            }
            digit *= 10;
            num /= 10;
        }
        return answer;
    }
    // 923456, 023456 이거 아니라고? 
public:
    int maxDiff(int num) {
        int minn = INT_MAX;
        int maxx = INT_MIN;
        for (int i = 0;i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                // cout << i << j << '\n';
                int tmp = diff(num, i, j);
                if (num == -tmp || tmp == INT_MIN + 1)
                {
                    continue;
                }
                // cout << tmp << '\n';
                minn = min(minn, tmp);
                maxx = max(maxx, tmp);
            }
        }

        return maxx - minn;
    }
};