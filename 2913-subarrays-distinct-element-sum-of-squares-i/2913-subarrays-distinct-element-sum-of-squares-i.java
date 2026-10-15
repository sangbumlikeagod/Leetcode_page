class Solution {
    public int sumCounts(List<Integer> nums) {
        // HashMap<Integer, Integer> hmap = new HashMap<>();
        int n = nums.size();
        int[][] args = new int[n + 1][101];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= 100; j++)
            {
                args[i + 1][j] = args[i][j];
            }
            args[i + 1][nums.get(i)]++;
        }
        int answer = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                int c = 0;
                for (int k = 0; k <= 100; k++)
                {
                    if (args[j + 1][k] - args[i][k] != 0)
                    {
                        c++;
                    }
                }
                answer += c * c;
            }
        }
        return answer;
    }
}