class Solution {
public:
    long long distributeCandies(int n, int limit) {
        // 2명이라면 둘이 썼을때 합계가 2limit 미만이 되도록 
        if (limit >= n) return (long long) (n + 2) * (n + 1) / 2;
        long long answer = 0;
        for (int i = max(0, n - 2 * limit); i <= limit; i++){
            int nn = n - i;
            int j = max(0, nn - limit);
            answer += min(nn, limit) - j + 1;
            // cout << i <<' '<< j << ' ' << nn << ' '<< answer << '\n';
        }

        return answer;
    }
};