class Solution {
public:
    int findLucky(vector<int>& arr) {
        vector<int> _freq(501);

        for (int ar : arr)
        {
            _freq[ar]++;
        }
    
        for (int i = 500; i > 0; --i)
        {
            if (_freq[i] == i)
                return i;

        }
        return -1;
    }
};