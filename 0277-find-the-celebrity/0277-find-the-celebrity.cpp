/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
public:
    int findCelebrity(int n) {
        vector<int> vec {};
        vector<int> vec2 {};
        for (int i = 0; i < n; i++)
        {
            vec.push_back(i);
        }

        for (int i = 0; i < n; i++)
        {
            // cout << i << '\n';
            for (int num : vec)
            {
                if (knows(i, num))
                {
                    vec2.push_back(num);
                }
            }
            if (vec2.size() == 1)
            {
                cout << vec2[0] << '\n';
                for (int j = 0; j < n; j++)
                {
                    if (vec2[0] == j) continue;
                    if (knows(vec2[0], j))
                    {
                        return -1;
                    }
                }
                for (int j = 0; j < n; j++)
                {
                    if (vec2[0] == j) continue;
                    if (!knows(j, vec2[0]))
                    {
                        return -1;
                    }
                }
                return vec2[0];
            }
            vec.clear();
            swap(vec, vec2);
        }
        return -1;
    }
};