class Solution
{
    unordered_map<int, int> exists;

public:
    vector<int> singleNumber(vector<int> &nums)
    {

        vector<int> answer{};
        for (int num : nums)
        {
            if (exists.find(num) != exists.end())
            {
                exists.erase(num);
            }
            else
            {
                exists[num]++;
            }
        }

        for (unordered_map<int, int>::iterator begin = exists.begin(); begin != exists.end(); begin++)
        {
            answer.push_back(begin->first);
        }
        return answer;
    }
};