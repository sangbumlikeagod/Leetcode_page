class Solution
{
    priority_queue<int> pq;

public:
    long long maxKelements(vector<int> &nums, int k)
    {
        for (int num : nums)
        {
            pq.push(num);
        }
        long long answer = 0;
        while (k)
        {
            int highest = pq.top();

            pq.pop();
            answer += highest;

            pq.push(highest / 3 + (highest % 3 != 0));
            k--;
        }
        return answer;
    }
};