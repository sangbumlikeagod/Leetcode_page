class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        int minn = 0, maxx = 0;
        int curr = 0, answer = 0;
        for (int diff : differences)
        {
            curr += diff;
            if (abs(curr) > upper - lower)
            {
                return answer;
            }
            minn = min(minn, curr);
            maxx = max(maxx, curr);
        }
        // int h = upper, l = lower;
        if (maxx > 0)
        {
            //h = upper - maxx;
        }

        
        int h = upper - maxx , l = lower - minn;
        cout << h << ' ' << l;
        if (l <= h)
        {
        answer = h - l + 1;
        }
        return answer;
    }
};