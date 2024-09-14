class Solution
{
public:
    int longestSubarray(vector<int> &nums)
    {
        int cursor = 0;
        int answer = 1;
        int maxNum = 0;
        int cursorCount = 0;
        for (int num : nums)
        {
            if (num < cursor)
            {
                if (cursor >= maxNum)
                {
                    answer = cursor > maxNum ? cursorCount : max(answer, cursorCount);
                    maxNum = cursor;
                }
                cursorCount = 1;
            }
            else if (num == cursor)
            {
                cursorCount++;
            }
            else
            {
                cursorCount = 1;
            }
            cursor = num;
        }

        if (cursor >= maxNum)
        {
            answer = cursor > maxNum ? cursorCount : max(answer, cursorCount);
            maxNum = cursor;
        }
        return answer;
    }
};