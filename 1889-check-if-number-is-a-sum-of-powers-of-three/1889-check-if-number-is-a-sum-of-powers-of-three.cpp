class Solution {
public:
    bool checkPowersOfThree(int n) {
        while (n)
        {
            if (n % 3)
            {
                if ((n - 1) % 3 == 0)
                {
                    n--;
                }
                else
                {
                    return false;
                }
            }
            n /= 3; 
        }
        return true;
    }
};