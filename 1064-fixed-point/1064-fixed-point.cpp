class Solution {
public:
    int fixedPoint(vector<int>& arr) {
        for (int i = 0; i < arr.size(); i++)
        {
            int ar = arr[i];
            if (ar == i) return i;
        }
        return -1;
    }
};