class Solution {
public:
    int minMaxDifference(int num) {
        int minV = 1e8 + 1, maxV = 0;
        int digit = 1;
        // while (num > digit)
        //     {
        //         lastDigit = num / digit;
        //         digit *= 10;
        //     }
        // cout << lastDigit << '\n';
        for (int i = 0; i < 10; i++)
            {
                digit = 1;
                int tmpM = 0, tmpm = 0;
                while (num >= digit)
                    {
                        int next = num % (digit * 10) / digit;
                        if (next == i)
                        {
                            tmpM += digit * 9;
                        }
                        else
                        {
                            tmpM += digit * (next);
                            tmpm += digit * (next);
                        }
                        digit *= 10;
                    }
                minV = min(minV, tmpm);
                maxV = max(maxV, tmpM);
            }
        return maxV - minV;
    }
};