class Solution {
    public int totalNumbers(int[] digits) {
        int[] digitss = new int[10];
        for (int digit : digits)
        {
            digitss[digit]++;
        }
        int answer = 0;

        for (int i = 100; i < 1000; i += 2)
        {
            int[] x = new int[10];
            x[i % 10]++;
            x[i % 100 / 10]++;
            x[i % 1000 / 100]++;
            boolean xx = true;
            for (int j = 0; j < 10; j++)
            {
                if (x[j] > digitss[j])
                {
                    xx = false;
                    break;
                }
            }   
            if (xx)
            {
                answer++;
            }
        }
        return answer;
    }
}