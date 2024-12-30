class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> args (high + 1, 0);
        int MODULO = 1000000007;
        args[0] = 1;
        int answer = 0;
        for (int i = 0; i < high; i++)
        {
            if (args[i])
            {
                if (i + zero <= high)
                {
                    args[i + zero] += args[i];
                    args[i + zero] %= MODULO;
                }
                if (i + one <= high)
                {
                    args[i + one] += args[i];
                    args[i + one] %= MODULO;
                }
                if (i >= low)
                {
                    answer += args[i];
                    answer %= MODULO;
                }
            }
        }
        answer += args[high];
        answer %= MODULO;
        return answer;
    }
};