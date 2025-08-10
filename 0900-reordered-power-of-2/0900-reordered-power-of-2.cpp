class Solution {
    const int LIMIT = 1e9;
public:
    bool reorderedPowerOf2(int n) {
        vector<vector<int>> pOTD(31, vector<int>(10));
        int i = 1, idx = 0;
        while(i <= LIMIT)
        {
            int iC = i;
            while (iC)
            {
                pOTD[idx][iC % 10]++;
                iC /= 10;
            }
            i <<= 1;
            idx++;
        }
        vector<int> PTD(10, 0);
        int nC = n;
        while(nC)
        {
            PTD[nC % 10]++;
            nC /= 10;
        }

        for (int j = 0; j < 31; j++)
        {
            int isMatch = 1;
            for (int k = 0; k < 10; k++)
            {
                if (PTD[k] != pOTD[j][k])
                {
                    isMatch = 0; break;
                }
            }
            if (isMatch)
            {
                return true;
            }
        }

        return false;

    }
};