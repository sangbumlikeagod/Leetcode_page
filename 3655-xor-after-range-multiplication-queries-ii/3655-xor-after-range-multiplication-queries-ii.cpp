class Solution {

    const int mod = 1e9 + 7;
    using ll = long long;
    int pow(ll x, ll y)
    {
        // 처음 결과물 정하고
        ll res = 1;
        for (; y; y >>= 1)
        {
            // pow를 더하기로 하는게아니라 급수도 할 수 있음 
            if (y & 1) {
                res = res * x % mod;
            }
            // 곱하려는 수 x를 한번 제곱 
            x = x * x % mod;
        }
        // digit 만큼이나 
        return res;
    }

public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        // 기준을 세운다 
        int T = sqrt(n);
        // T개의 
        vector<vector<vector<int>>> groups(T);
        for (auto& q : queries) {
            int l = q[0], r = q[1], k = q[2], v = q[3];

            // T보다 작아야 
            if (k < T)
            {
                // 
                groups[k].push_back({l, r, v});
            } else {
                // 충분히 클경우는 그냥 계산 
                for (int i = l; i <= r; i += k)
                {
                    nums[i] = 1ll * nums[i] * v % mod;
                }
            }
        }

        vector<ll> dif(n + T);
        // 모든 간격을 찾아서 더한다
        for (int k = 1; k < T; k++)
        {
            if (groups[k].empty()){
                continue;
            }
            // 아까쌓아놨던 간격
            fill(dif.begin(), dif.end(), 1);
            for (auto& q : groups[k])
            {
                int l = q[0], r = q[1], v = q[2];
                // 위에서 하나 구하고 
                dif[l] = dif[l] * v % mod;

                // 간격의 끝을 구하고
                int R = ((r - l) / k + 1) * k + l;
                // 페르마 소정리로 구한 값

                // 맨오른쪽 (범위가 끝났다는 의미로 역원 곱하기) )
                dif[R] = dif[R] * pow(v, mod - 2) % mod;
            }

            // 그 간격별로 
            for (int i = k; i < n; i++)
            {
                // 고정된 범위로 하는 이유가 여기 나오는거같은데 
                dif[i] = dif[i] * dif[i - k] % mod;
            }

            for (int i = 0; i < n; i++)
            {
                // 간격별로 n전까지는 diff를 곱한값을 
                nums[i] = 1ll * nums[i] * dif[i] % mod;
            }
        }
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            res = res ^ nums[i];
        }
        return res;
        
    }
};