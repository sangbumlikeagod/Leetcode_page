struct subarray {
    unordered_map<int, int> arg;
    int count;
     subarray() {
        count = 0;
     }
     void put (int r) {
        if (arg.find(r) == arg.end())
        {
            arg[r] = 1;
        }
        else
        {
            count += arg[r];
            arg[r]++;
        }
     }

     void erase (int r) {
        count -= arg[r] - 1;
        arg[r]--;
        if (arg[r] == 0)
        {
            arg.erase(r);
        }
     }
};

class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        long long answer = 0;
        int l = 0, r = 0;
        subarray s;
        // 둘다 먹을예정으로 관리 
        while (l < nums.size() && r <= nums.size())
        {
            // cout << l << ' ' << r  << ' ' << s.count << '\n';
            if (s.count < k)
            {
                if (r != nums.size())
                {
                    s.put(nums[r]);
                }
                r++;
            }   
            else
            {
                // 둘중 하나를 고정해서 왼쪽이 l인 상태에서 (즉 중복되지 않음 이후부턴) r보다큰 모든 인덱스들은 정답에 해당함 
                answer += nums.size() - r + 1;
                s.erase(nums[l]);
                l++;
            }
        }

        return answer;
    }
};