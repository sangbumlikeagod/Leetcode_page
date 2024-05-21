struct cmp
{
    bool operator()(pair<int, int> a, pair<int, int> b)
    {
        return a.first * b.second < a.second * b.first; 
    }
};
class Solution {
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> queue;
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        for (int i = 0; i < arr.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                queue.push({arr[j], arr[i]});
            }
        }

        while (--k)
        {
            queue.pop();
        }
        return vector<int> {queue.top().first, queue.top().second};
    }
};