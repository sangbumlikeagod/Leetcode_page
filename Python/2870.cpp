class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int, int> goog;
        for(int i : nums){
            goog[i]++;
        }
        int ans = 0;
        for(pair<int, int> arg: goog){
            while (arg.second > 4){
                arg.second -= 3;
                ans++;
            }
            if (arg.second == 4){
                ans += 2;
            } else if (arg.second == 3){
                ans++;
            } else if (arg.second == 2){
                ans++;
            } else {
                return -1;
            }
        }
        return ans;
    }
};