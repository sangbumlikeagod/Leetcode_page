class Solution {
    public int totalWaviness(int num1, int num2) {
        int answer = 0;
        for (int i = num1; i <= num2; i++)
        {
            int stance = 0;
            int i2 = i;
            int prev = i2 % 10;
            int vallyness = 0;
            
            while (i2 != 0)
            {
                if (i2 % 10 > prev)
                {
                    if (stance == -1)
                    {
                        vallyness++;  
                    }
                    stance = 1;
                }
                else if (i2 % 10 < prev)
                {
                    // 이전보다 작아
                    if (stance == 1)
                    {
                        vallyness++;
                    }
                    stance = -1;
                }
                else
                {
                    stance = 0;
                }
                prev = i2 % 10;
                i2 /= 10;
            }
            answer += vallyness;
        }
        return answer;
    }
}