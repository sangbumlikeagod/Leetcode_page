class Solution {
    public int numberOfSpecialChars(String word) {
        int[] arr = new int[26];
        int answer = 0;        
        for (char c : word.toCharArray())
        {
            if (c - 'a' >= 0)
            {
                arr[c - 'a'] |= 1;
            }
            else
            {
                arr[c - 'A'] |= 2;
            }
        }
        for (int ar : arr)
        {
            if (ar == 3)
            {
                answer++;
            }
        }
        return answer;
    }
}