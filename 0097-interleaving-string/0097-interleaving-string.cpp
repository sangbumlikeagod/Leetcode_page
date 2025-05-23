class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s3.length() != s1.length() + s2.length()) return false;
        // 같다는거 보장
        // dp[i][j] : bool = s1 i칸 , s2 j칸의 조합이 같은지에 대한 bool값
        if (s1.length() == 0) return s3 == s2;
        if (s2.length() == 0) return s3 == s1;
        vector<vector<int>> dp(s1.length() + 1, vector<int>(s2.length() + 1, 0));

        if (s1[0] == s3[0])
        {
            dp[1][0] = 1;
        }
        if (s2[0] == s3[0])
        {
            dp[0][1] = 1;
        }
        if (s1[0] != s3[0] && s2[0] != s3[0]) return false;

        for (int i = 0; i <= s1.length(); i++)
        {
            for (int j = 0; j <= s2.length(); j++)
            {
                if (dp[i][j])
                {
                    if (i != s1.length() && s1[i] == s3[i + j])
                    {
                        dp[i + 1][j] = true;
                    }
                    if (j != s2.length() && s2[j] == s3[i + j])
                    {
                        dp[i][j + 1] = true;
                    }
                }
            }
        }

        // for (int k = 0; k < s3.length(); k++)
        // {
        //     if (dp[k][s3.length() - k - 1])
        //     {
        //         return true;
        //     }
        // }
        return dp[s1.length()][s2.length()];
        // return dp[s1.length()][s2.length() - 1] || dp[s1.length() - 1][s2.length()] ;
    }
};