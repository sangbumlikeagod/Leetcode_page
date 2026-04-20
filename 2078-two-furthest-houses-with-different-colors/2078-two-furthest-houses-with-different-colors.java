class Solution {
    public int maxDistance(int[] colors) {
        int answer = 0;
        int n = colors.length;

        for (int i = 0; i < n; i++)
        {
            for (int j = n - 1; j - i > answer; j--)
            {
                if (colors[i] != colors[j])
                {
                    answer = j - i;
                    break;
                }
            }
        }
        return answer;
    }
}