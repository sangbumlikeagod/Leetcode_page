class Solution {
    private int gets(int n, int k){
        if (n == 1) return 0;
        int l = (1 << n) - 1;
        if (k == l / 2)
        {
            return 1;
        }
        else if (k < l / 2)
        {
            return gets(n - 1, k);
        }
        else
        {
            return (
            // 여기서 한번 뒤집어줘야하는구나 
            gets(n - 1, 
            ((l >> 1) - 1) - (k - (l / 2 + 1))) + 1) % 2;
        }
    }
    public char findKthBit(int n, int k) {
        return(char) ('0' + gets(n, k - 1));
    }
}