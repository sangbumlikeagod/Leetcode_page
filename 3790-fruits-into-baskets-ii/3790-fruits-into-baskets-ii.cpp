class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        int indexes[101] = {0,};
        int answer = 0;
        for (int i = 0; i < n; i++)
        {
            int j = 0;
            for (; j < n; j++)
            {
                if (indexes[j]) continue;
                if (baskets[j] >= fruits[i])
                {
                    indexes[j] = 1;
                    break;
                }
            }
            if (j == n)
            {
                answer++;
            }
        }
        return answer;
    }
};