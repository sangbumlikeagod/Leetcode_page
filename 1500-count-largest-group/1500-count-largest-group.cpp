class Solution {
public:
    int ans[40];
    int countLargestGroup(int n) {
        for (int i = 1; i <= n; i++)
        {
            int iC = i, tmp = 0;
            while (iC)
            {
                tmp += iC % 10;
                iC /= 10;
            }
            // cout << i << ' ' << tmp << '\n';
            ans[tmp]++;
        }
        int answer = 0;
        int size = 0;
        for (int i = 1; i < 40; i++)
        {
            // cout << i << ' ' << ans[i] << '\n';
            if (ans[i] > ans[answer])
            {
                answer = i;
                size = 1;
            }
            else if (ans[i] == ans[answer])
            {
                size++;
            }
            
        }
        return size;
    }
};