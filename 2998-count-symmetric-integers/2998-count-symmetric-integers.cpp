class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int answer = 0;
        while (low <= high)
        {
            int digit = 0, l = 0, r = 0;
            int t = low, c = low;
            
            while (t > 0)
            {
                digit++;
                t /= 10;
            }

            low++; 
            if (digit % 2 == 1)
            {
                continue;
            }

            for (int i = 0; i < digit; i++)
            {

                if (i >= digit / 2)
                {
                    r += c % 10;
                }
                else
                {
                    l += c % 10;
                }
                c /= 10;
            }
            if (l == r)
            {
                answer++;
            }
        }
        return answer;
    }
};