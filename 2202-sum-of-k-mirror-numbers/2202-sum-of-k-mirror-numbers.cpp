class Solution {
    bool translate(long long base, int digit)
    {
        vector<int> digits{};
        while(base)
        {
            digits.push_back(base % digit);
            base /= digit;
        }
        // cout << '\t';
        int l = 0, r = digits.size() - 1;
        // for (int i = 0; i <= r; i++)
        // {
        //     cout << digits[i];
        // }
        while (l < r)
        {
            if (digits[l] != digits[r])
            {
                
                // cout << '\n';
                return false;
            }
            l++;
            r--;
        }
        // cout <<'\n' << "\tsex" << '\n';
        return true;
    }
public:
    long long kMirror(int k, int n) {
        long long answer = 0;  
        long long degree = 10;
        int dig = 1;
        queue<long long> q;
        for (int i = 1; i < 10; i++)
        {
            q.push(i);
        } 

        while (n)
        {
            long long next = q.front();
            // cout << next << '\n';
            q.pop();
            if (next >= degree)
            {
                degree *= 10;
                dig++;   
            }
            if (translate(next, k))
            {
                answer += next;
                n--;
            }
            long long divider = pow(10, dig / 2);
            if (dig % 2)
            {
                    long long front = (next / divider) * divider * 10;
                    long long mid = ((next / divider) % 10) * divider;
                    long long back = (next % divider);
                    q.push(front + mid + back);  
            }
            else
            {
                for (int i = 0; i < 10; i++)
                {
                    long long front = (next / divider) * divider * 10;
                    long long mid = i * divider;
                    long long back = (next % divider);
                    q.push(front + mid + back);  
                }
            }
        }
        return answer;
    }
};