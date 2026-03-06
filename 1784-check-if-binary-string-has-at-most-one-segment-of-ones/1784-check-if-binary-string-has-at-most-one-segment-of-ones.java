class Solution {
    public boolean checkOnesSegment(String s) {
        int n = s.length();

        boolean chance = true;
        for (int i = 0; i < n; i++)
        {
            if (s.charAt(i) == '0')
            {
                chance = false;
            }
            else
            {
                 if (!chance)
                {
                    return false;
                }
            }
        }
        return true;
    }
}