class Solution {
    public int reverseDegree(String s) {
        int answer = 0;
        for (int i = 0; i < s.length(); i++)
        {
            answer += ('z' - s.charAt(i) + 1) * (i + 1);
        }
        return answer;
    }
}