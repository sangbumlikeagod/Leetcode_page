class Solution
{

    int firstStep(string s)
    {
        int ans = 0;
        for (char c : s)
        {
            int z = c - 'a' + 1;
            ans += z % 10 + z / 10;
        }
        return ans;
    }

public:
    int getLucky(string s, int k)
    {
        int tmp = firstStep(s);
        k--;
        int answer = 0;
        while (k)
        {
            if (tmp < 10)
            {
                return tmp;
            }

            while (tmp)
            {
                answer += tmp % 10;
                tmp /= 10;
            }
            tmp = answer;
            answer = 0;
            k--;
        }
        return tmp;
    }
};