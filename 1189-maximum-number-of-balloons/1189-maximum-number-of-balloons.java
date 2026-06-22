class Solution {
    int[][] digitPrefixes = new int[10001][26];
    public int maxNumberOfBalloons(String text) {
        int n = text.length();


        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < 26; j++)
            {
                digitPrefixes[i + 1][j] = digitPrefixes[i][j];
            }
            int ne = text.charAt(i) - 'a';
            digitPrefixes[i + 1][ne] = digitPrefixes[i][ne] + 1;
        }
        int answer = 10000;
        answer = Math.min(answer, digitPrefixes[n]['a' - 'a']);
        answer = Math.min(answer, digitPrefixes[n]['b' - 'a']);
        answer = Math.min(answer, digitPrefixes[n]['l' - 'a'] / 2);
        answer = Math.min(answer, digitPrefixes[n]['o' - 'a'] / 2);
        answer = Math.min(answer, digitPrefixes[n]['n' - 'a']);
        return answer;
    }
}