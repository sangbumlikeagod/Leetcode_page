class Solution {
    public int bitwiseComplement(int n) {
        if (n == 0) return 1;
        int answer = 1;
        int k = n;
        while (k > 0)
        {
            answer <<= 1;
            k >>= 1;
        }
        answer--;
        return answer - n;
    }
}