class Solution {
    public int smallestNumber(int n) {
        int answer = 1;
        while (answer < n)
        {
            answer <<= 1;
            answer |= 1;
        }
        return answer;
    }
}