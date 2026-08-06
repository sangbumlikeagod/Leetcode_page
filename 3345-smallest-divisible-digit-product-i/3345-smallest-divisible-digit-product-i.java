class Solution {
    public int smallestNumber(int n, int t) {
        while (true)
        {
            int x = n;
            int y = 1;
            while (x > 0)
            {
                y *= (x % 10);
                x /= 10;
            }
            if (y % t == 0)
            {
                break;
            }
            n++;
        }
        return n;
    }
}