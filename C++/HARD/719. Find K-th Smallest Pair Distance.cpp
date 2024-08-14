class Solution
{
    int twoPointer(int target, vector<int> &vec)
    {
        sort(vec.begin(), vec.end());
        int answer = 0;
        int right = vec.size() - 1;
        int left = right - 1;
        while (right)
        {
            cout << left << ' ' << right << '\n';
            if (left == -1)
            {
                answer += right;
                right--;
                continue;
            }
            while (left >= 0 && vec[right] - vec[left] <= target)
            {
                // cout << left << ' ' << right << '\n';
                left--;
            }
            answer += right - left - 1;
            right--;
        }
        return answer;
    }

public:
    int smallestDistancePair(vector<int> &nums, int k)
    {
        int left = 0;
        int right = 1000000;
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            int tmp = twoPointer(mid, nums);
            cout << '\t' << mid << '\t' << tmp << '\n';
            if (tmp >= k)
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
        }
        return left;
    }
};