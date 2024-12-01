class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        for (int i = 0; i < arr.size(); i++)
        {
            auto vun = lower_bound(arr.begin(), arr.end(), arr[i] * 2);
            if (vun != arr.end() && (*vun) == arr[i] * 2 && vun - arr.begin() != i)
            {
                return true;
            }
        }
        return false;
    }
};