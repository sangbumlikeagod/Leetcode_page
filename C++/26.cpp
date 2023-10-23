#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int idx = nums.size();
        if (idx == 1){
            return 1;
        }
        int p1 = 1;
        while (p1 < idx){

            while (p1 < idx && nums[p1] > nums[p1 - 1]){
                p1++;
            }

            if (p1 == idx){
                break;
            }
            int p2 = p1 + 1;
            
            while (p2 < idx && nums[p2] <= nums[p1 - 1]){
                p2++;
            }
            // cout << p1 << p2 << endl;
            if (p2 == idx){
                break;
            }
            nums[p1] = nums[p1] ^ nums[p2];
            nums[p2] = nums[p1] ^ nums[p2];
            nums[p1] = nums[p1] ^ nums[p2];

        }
        // for (int i = idx - p1; i > 0; i--){
        //     cout << i << endl;
        //     nums.pop_back();
        // }
        return p1;
    }
};
