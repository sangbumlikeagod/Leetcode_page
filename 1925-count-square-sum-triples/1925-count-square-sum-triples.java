class Solution {
    public int countTriples(int n) {
        int answer = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= i; j++)
            {
                for (int k = 1; k <= j; k++)
                {
                    if (i * i == j * j + k * k)
                    {
                        answer += 2;
                    }
                }
            }
        }
        return answer;
    }
}