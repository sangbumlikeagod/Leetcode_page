class Solution {
    public int minimumPushes(String word) {
        int[] cnts = new int[26];
        for (char c : word.toCharArray())
        {
            cnts[c - 'a'] ++;
        }
        int answer = 0;
        Arrays.sort(cnts);
        for (int i = 25; i > 17; i--)
        {
            answer += cnts[i];
        }
        for (int i = 17; i > 9; i--)
        {
            answer += cnts[i] * 2;
        }
        for (int i = 9; i > 1; i--)
        {
            answer += cnts[i] * 3;
        }
        answer += cnts[1] * 4;
        answer += cnts[0] * 4;
        return answer;
    }
}