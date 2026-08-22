class Solution {
    public boolean checkDivisibility(int n) {
        int sS = 0;
        int sP = 1;
        int nx = n;
        while (nx > 0)
        {
            sS += nx % 10;
            sP *= nx % 10;
            nx /= 10;
        }
        return (n % (sS + sP)) == 0; 
    }
}