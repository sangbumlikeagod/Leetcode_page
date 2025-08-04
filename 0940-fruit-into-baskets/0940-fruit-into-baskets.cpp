class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> maps;

        int l = 0, r = 0, answer = 0;
        int n = fruits.size();
        while (r < n)
        {
            maps[fruits[r++]]++;
            while (maps.size() > 2)
            {
                maps[fruits[l]]--;
                if (maps[fruits[l]] == 0)
                {
                    maps.erase(fruits[l]);
                }
                l++;
            }
            answer = max(answer, r - l);
        }
        return answer;
    }
};