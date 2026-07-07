class Solution {
    public long sumAndMultiply(int n) {
        long answer = 0;
        long digits = 1;
        long digit = 0;
        while (n != 0)
        {
            answer += (n % 10) * digits;
            digit += n % 10;
            if (n % 10 != 0)
            {
                digits *= 10;
            }
            n /= 10;
        }
        return answer * digit;

    }
}