class Solution {
    public boolean checkStrings(String s1, String s2) {
        int n = s1.length();
        int[] evens1 = new int[26];
        int[] odds1 = new int[26];


        for (int i = 0; i < n; i += 2)
        {
            evens1[s1.charAt(i) - 'a']++;
            evens1[s2.charAt(i) - 'a']--;
        }
        for (int i = 1; i < n; i += 2)
        {
            odds1[s1.charAt(i) - 'a']++;
            odds1[s2.charAt(i) - 'a']--;
        }

        for (int i = 0; i < 26; i++)
        {
            if (evens1[i] != 0 || odds1[i] != 0)
            {
                return false;
            }
        }
        return true;
    }
}