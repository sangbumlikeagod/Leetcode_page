class Solution {    
    private long getDigitsRet(long b){
        // ptr은 이거보다 작은수로 정함 
        long ptr = 1;
        long digits = 1;
        long ret = 0;
        while (digits <= b)
        {
            // if (digits <= a && a < digits * 4)
            // {
            //     ret += ptr * (digits * 4 - a);
            // }
            // else if (a <= digits && digits * 4 < b)
            // {
            //     ret += (3 * digits) * ptr;
            // }
            if (digits * 4 <= b)
            {
                ret += (3 * digits) * ptr;
            }
            else if (digits <= b && b < digits * 4)
            {
                ret += ptr * (b - digits + 1);
            }
            digits *= 4;
            ptr++;
        }
        // System.out.println(" " + b + " " + ret);
        return ret;
    }
    public long minOperations(int[][] queries) {
        long answer = 0;    
        for (int[] query : queries)
        {
            long left = getDigitsRet((long) query[1]);
            long right = getDigitsRet((long) query[0] - 1);
                
            answer += (
                left
                -
                right
            ) / 2 + (left - right) % 2; 
        }
        return answer;
    }
}