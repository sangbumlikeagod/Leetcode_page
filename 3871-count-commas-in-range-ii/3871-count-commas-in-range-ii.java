class Solution {
    public long countCommas(long n) {
        
        long a = 999999999999L;
        long b = 999999999999999L;
        long c = 999999999999999999L;
        return ( 
            (long) Math.max(n - 999, 0) + 
            (long) Math.max(n - 999999, 0) +
            (long) Math.max(n - 999999999, 0) + 
            (long) Math.max(n - a, 0) + 
            (long) Math.max(n - b, 0) +
            (long) Math.max(n - c, 0)
        );

    }
}