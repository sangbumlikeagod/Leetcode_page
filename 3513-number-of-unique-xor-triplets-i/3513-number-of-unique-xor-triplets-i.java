class Solution {
    public int uniqueXorTriplets(int[] nums) {

        int n = nums.length;
        if (n <= 2)
        {
            return n;
        }

        int answer = 1;
        while (n >= 1)
        {
            n >>= 1;
            answer <<= 1;
        }
        return answer;
    }
}