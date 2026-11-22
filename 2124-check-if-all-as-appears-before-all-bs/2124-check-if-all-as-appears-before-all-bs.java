class Solution {
    public boolean checkString(String s) {
        int n = s.length();
        int bC = 0;
        for (int i = 0; i < n; i++)
        {
            if (s.charAt(i) == 'b')
            {
                bC++;
            }
            else
            {
                if (bC != 0)
                {
                    return false;
                }
            }
        }
        return true;
        
    }
}