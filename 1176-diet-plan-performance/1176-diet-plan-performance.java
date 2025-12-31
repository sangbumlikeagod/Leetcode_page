class Solution {
    public int dietPlanPerformance(int[] calories, int k, int lower, int upper) {
        int n = calories.length;
        int init = 0;
        int answer = 0;
        for (int i = 0; i < k; i++)
        {
            init += calories[i];
        }
        if (init > upper) {answer = 1;}
        if (init < lower) {answer = -1;}

        for (int i = k; i < n; i++)
        {
            init += calories[i];
            init -= calories[i - k];
            if (init > upper) {answer++;}
            if (init < lower) {answer--;}
        }
        return answer;
    }
}