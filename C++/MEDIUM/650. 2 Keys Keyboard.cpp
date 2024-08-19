class Solution
{
public:
    int minSteps(int n)
    {
        if (n == 1)
            return 0;
        vector<int> primes{};
        vector<int> underThousand(1000, 0);
        for (int i = 1; i < 1000; i++)
        {
            underThousand[i] = i;
        }
        for (int i = 2; i < 1000; i++)
        {
            if (underThousand[i])
            {
                primes.push_back(i);
            }
            int del = i;
            while (del < 1000)
            {
                underThousand[del] = 0;
                del += i;
            }
        }

        vector<int> primeDivisionList(primes.size(), 0);
        for (int i = 0; i < primes.size(); i++)
        {
            int av = n;
            while (!(av % primes[i]))
            {
                av /= primes[i];
                primeDivisionList[i]++;
            }
        }

        int answer = 0;
        for (int i = 0; i < primes.size(); i++)
        {
            if (primeDivisionList[i])
            {
                answer += primeDivisionList[i] * primes[i];
            }
        }
        return answer;
    }
};