class Solution {
    public int furthestDistanceFromOrigin(String moves) {

        int answer = 0;
        int oneSide = 0;
        int mid = 0;
        for (char c : moves.toCharArray())
        {
            if (c == '_')
            {
                mid++;
            }
            else
            {
                oneSide += c == 'L' ? 1 : -1;
            }
        }
        answer = Math.max(answer, Math.abs(oneSide) + mid);
        return answer;
    }
}