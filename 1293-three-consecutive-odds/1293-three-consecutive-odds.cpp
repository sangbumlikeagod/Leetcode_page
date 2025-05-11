class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int mod = 0;
        for (int ar : arr)
        {
            if (ar % 2)
            {
                mod ++;
                if (mod == 3) return true;
            }
            else
            {
                mod = 0;
            }
        }
        return false;
    }
};