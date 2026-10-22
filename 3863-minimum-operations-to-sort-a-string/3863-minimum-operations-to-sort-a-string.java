class Solution {
    public int minOperations(String s) {
        int n = s.length();
        int small = 0;
        int big = 0;
        int startSmallest = 0;
        int endBiggest = 0;
        int nonDecreasing = 0;
        int[] cnt = new int[26];
        for (int i = 0; i < n; i++)
        {
            int x = s.charAt(i) - 'a';
            cnt[x]++;
            if (i < n - 1 && x > ((int) s.charAt(i + 1) - 'a'))
            {
                nonDecreasing++;
            }
        }
        for (int i = 0; i < 26; i++)
        {
            if (cnt[i] != 0)
            {
                small = i;
                startSmallest = (int) (s.charAt(0) - 'a') == small ? 1 : 0;
                break;
            }
        }
        for (int i = 25; i >= 0; i--)
        {
            if (cnt[i] != 0)
            {
                big = i;
                endBiggest = (int) (s.charAt(n - 1) - 'a') == big ? 1 : 0;
                break;
            }
        }
        // System.out.println(startSmallest + " " + endBiggest + " " + nonDecreasing);

        if (nonDecreasing == 0)
        {
            return 0;
        }
        if (nonDecreasing == n - 1)
        {   
            return n == 2 ? -1 : 3;
        }
        if (startSmallest == 1 || endBiggest == 1)
        {
            return 1;
        }
        if (
            cnt[big] == 1 &&
            cnt[small] == 1 && 
            (int) s.charAt(n - 1) - 'a' == small && (int) (s.charAt(0) - 'a') == big) 
        {
            return 3;
        }
        return 2;
    }
}