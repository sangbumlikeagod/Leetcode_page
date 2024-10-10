class Solution
{
    unordered_map<int, int> maps;

public:
    int countDistinctIntegers(vector<int> &nums)
    {
        int answer = 0;

        for (int num : nums)
        {
            if (maps.find(num) == maps.end())
            {
                answer++;
                maps[num]++;
            }
            int rep = 0;
            while (num)
            {
                rep *= 10;
                rep += num % 10;
                num /= 10;
            }
            if (maps.find(rep) == maps.end())
            {
                answer++;
                maps[rep]++;
            }
        }
        return answer;
    }
};