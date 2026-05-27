class Solution {
    public int numberOfSpecialChars(String word) {
        int[] args = new int[26]; 
        int[] first = new int[26];

        int answer = 0;
        for (char c : word.toCharArray())
        {
            if (c <= 'Z')
            {
                first[c - 'A'] = 1;
            }
            else
            {
                if (first[c - 'a'] == 1)
                {
                    args[c - 'a'] = 0;
                }
                else
                {
                    args[c - 'a'] = 1;
                }
            }
        }
        for (int i = 0; i < 26; i++)
        {
            answer += args[i] & first[i];
        }
        return answer;
    }
}