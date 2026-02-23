class Solution {
    public boolean hasAllCodes(String s, int k) {
        
        if (k > s.length()) return false;
        HashSet<Integer> hashSet = new HashSet();

        int x = 1 << (k - 1);
        int x2 = 1 << (k);
        while (x2 > 0)
        {
            hashSet.add(--x2);
        }
        int value = 0;
        int i = 0;
        for (; i < k; i++)
        {
            value <<= 1;
            value |= s.charAt(i) == '1' ? 1 : 0;
        }
        hashSet.remove(value);
        for (; i < s.length(); i++)
        {
            value ^= s.charAt(i - k) == '1' ? x : 0;
            value <<= 1;
            value |= s.charAt(i) == '1' ? 1 : 0;
            hashSet.remove(value);
        }
        

        
        return hashSet.isEmpty();
    }
}