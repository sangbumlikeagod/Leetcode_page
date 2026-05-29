class Solution {
public:
    bool confusingNumber(int n) {
        vector<int> dazed(10) ;
        vector<int> confused(10) ;
        dazed[0] = dazed[1] = dazed[8] = 1;
        confused[6] = confused[9] = 1;
        int confuses = 0;
        int n2 = n;
        while (n)
        {
            if (dazed[n % 10] == 0 && confused[n % 10] == 0)
            {
                return false;
            }
            confuses *= 10;
            if (dazed[n % 10])
            {
                confuses += n % 10;
            }
            else
            {
                confuses += n % 10 == 6 ? 9 : 6;
            }
            n /= 10;
        }
        // 916의 경우 돌려도 916임 쉣
        return confuses != n2;

    }
};