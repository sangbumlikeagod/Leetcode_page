class Solution {
    private int score(String str, int[] weights) {
        int answer = 0;
        for (char c : str.toCharArray())
        {
            answer += weights[c - 'a'];
        }
        return answer % 26;
    }
    public String mapWordWeights(String[] words, int[] weights) {
        StringBuffer strBuffer = new StringBuffer();
        for (String word : words)
        {
            strBuffer.append((char) ('z' - score(word, weights)));
        }
        return strBuffer.toString();
    }
}