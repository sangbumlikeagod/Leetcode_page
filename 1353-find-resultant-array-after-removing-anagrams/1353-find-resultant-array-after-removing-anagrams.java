class Solution {
    private boolean isAnagram(int[] a, int[] b)
    {
        for (int i = 0; i < 26; i++)
        {
            if (a[i] != b[i])
            {
                return false;
            }
        }
        return true;
    }
    private void strToArrays(String word, int[] base)
    {
        // 자바에서 iterable가능?
        for (char c : word.toCharArray())
            {
                base[c - 'a']++;
            }
    }
    
    public List<String> removeAnagrams(String[] words) {
        int m = words.length;
        List<String> answer = new ArrayList<>();
        
        int[][] wordList = new int[m + 1][26];
        for (int i = 0; i < m; i++)
            {
                strToArrays(words[i], wordList[i]);
                if (i != 0)
                {
                    if (!isAnagram(wordList[i], wordList[i - 1]))
                    {
                        answer.add(words[i]);
                    }
                }
                else
                {
                    answer.add(words[i]);
                }
            }
        return answer;
        
    }
}