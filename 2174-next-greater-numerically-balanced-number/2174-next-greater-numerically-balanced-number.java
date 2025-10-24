class Solution {
    private boolean isMatched(int[] arr)
    {
        boolean ans = true;
        for (int i = 0; i < 7; i++)
            {
                if(arr[i] != 0 &&  arr[i] != i )
                {
                    ans = false;   
                }
                arr[i] = 0;
            }
        return ans;
    }

    public int nextBeautifulNumber(int n) {
        int[] digits = new int[7] ;
        n++;
        while (n <= 1224444)
            {
                int x = n;
                while (x > 0)
                {
                    if (x % 10 >= 7)
                    {
                        break;
                    }
                    digits[x % 10]++;
                    x /= 10;
                }
                if (x % 10 >= 7)
                {
                    n++;
                    continue;
                }
                
                if (isMatched(digits))
                {
                    break;
                }
                n++;
            }
        return n;
    }
}