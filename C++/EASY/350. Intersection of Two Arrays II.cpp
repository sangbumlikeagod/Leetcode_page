class Solution
{
    int intersection[1001] = {0};

public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> answer{};
        for (int num : nums1)
        {
            intersection[num]++;
        }
        for (int num : nums2)
        {
            if (intersection[num])
            {
                intersection[num]--;
                answer.push_back(num);
            }
        }
        return answer;
    }
};