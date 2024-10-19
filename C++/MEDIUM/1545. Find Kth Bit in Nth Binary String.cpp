class Solution
{
public:
    char findKthBit(int n, int k)
    {
        int indicator;
        int middle = pow(2, n - 1);
        if (n == 1)
        {
            indicator = 0;
        }
        else
        {
            if (k == middle)
            {
                indicator = 1;
            }
            else if (k > middle)
            {
                indicator = findKthBit(n - 1, middle - (k - middle)) == '0';
            }
            else if (k < middle)
            {
                indicator = findKthBit(n - 1, k) == '1';
            }
        }
        return '0' + indicator;
    }
};