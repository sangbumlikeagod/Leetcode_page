class Solution {
    public int minPartitions(String n) {
        int answer = 0;
        for (char c : n.toCharArray())
        {
            answer = Math.max(answer, (int) (c - '0'));
        }   
        return answer;
    }
}