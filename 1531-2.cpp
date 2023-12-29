#include <string>
using namespace std;
class Solution {
    pair<int, char> dp[101][101] = {};
    string str;
public:
    int getLengthOfOptimalCompression(string s, int k) {
        str = s;
        dp[1][1] = make_pair(0, '');
        dp[1][0] = make_pair(2, s[0] + '1');
        for (int i = 1; i < s.length(); i++)
        {
            for (int j = 0; j <= k; j++)
            {
                // j는 남은 횟수
                if (dp[i][j].first >= 2 && s[i + 1] == dp[i][j].second)
                {
                    // 둘이 같다면 
                    
                    dp[i + 1][j] = make_pair(dp[i][j].second)
                    // 다음 인덱스에서 
                }
                
            }
            
        }
        

    }
    
};