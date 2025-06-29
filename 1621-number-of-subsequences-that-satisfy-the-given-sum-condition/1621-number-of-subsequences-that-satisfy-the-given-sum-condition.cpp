class Solution {
    int MODULO = 1e9 + 7;
    // 2의 2 ^ x승의 값
    vector<long long> powerOfTwo;
    
    void init() {
        powerOfTwo[0] = 1;
        powerOfTwo[1] = 2;
        for (int i = 2; i < 20; i++)
            {
                 powerOfTwo[i] = (powerOfTwo[i - 1] * powerOfTwo[i - 1]) % MODULO;
            }
    }
    int calc(int n)
    {
        long long ret = 1;
        int t = 1;
        for (int i = 1; i < 20; i++)
            {
                if (n & t)
                {
                    ret *= powerOfTwo[i];
                    ret %= MODULO;
                }
                t *= 2;
            }
        return (int) ret;
    }
public:
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        powerOfTwo.resize(20);
        init();
        // for (int i = 0; i < 20; i++)
        //     {
        //         cout << powerOfTwo[i] << ' '; 
        //     }
        // cout <<'\n';
        sort(nums.begin(), nums.end());
        int answer = 0;
        for (int i = 0; i < n; i++)
            {
                int possible = n - i - 1;
                possible -= (int) (nums.end() - upper_bound(nums.begin(), nums.end(), target - nums[i]));
                // cout << i << ' ' << nums.end() - upper_bound(nums.begin(), nums.end(), target - nums[i]) << ' '<< possible << '\n';
                if (possible < 0) break;
                answer += calc(possible);
                answer %= MODULO;
            }
        return answer;
        
    }
};