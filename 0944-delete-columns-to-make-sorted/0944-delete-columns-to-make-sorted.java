class Solution {
    public int minDeletionSize(String[] strs) {
        int answer = 0;
        int l = strs[0].length();
        for (int i = 0; i < l; i++)
        {
            char last = 'a';
            for (String str : strs)
            {
                if (last > str.charAt(i))
                {
                    answer++;
                    break;
                }
                last = str.charAt(i);
            }
        }
        return answer;
    }
}