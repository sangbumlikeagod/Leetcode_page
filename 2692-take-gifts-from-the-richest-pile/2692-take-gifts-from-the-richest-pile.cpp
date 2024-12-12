class Solution {
    priority_queue<int> q;
public:
    long long pickGifts(vector<int>& gifts, int k) {
        for (int gift : gifts)
        {
            q.push(gift);
        }

        while(k)
        {
            int next = (int) sqrt(q.top());
            // cout << next << '\n';
            q.pop();
            q.push(next);
            k--;
        }
        long long answer = 0;
        while (!q.empty())
        {
            answer += q.top();
            q.pop();
        }
        return answer;
    }
};