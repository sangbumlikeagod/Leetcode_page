class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<int> garo {};
        vector<int> sero {};
        for (vector<int>& rectangle : rectangles)
        {
            garo.push_back(rectangle[0] * 2);
            garo.push_back((rectangle[2] * -2) + 1);
            sero.push_back(rectangle[1] * 2);
            sero.push_back((rectangle[3] * -2)  + 1);
        }

        sort(garo.begin(), garo.end(), [](int a, int b){
            if (a < 0) a *= -1;
            if (b < 0) b *= -1;
            return a < b;
        });
        sort(sero.begin(), sero.end(), [](int a, int b){
            if (a < 0) a *= -1;
            if (b < 0) b *= -1;
            return a < b;
        });
        int total = 0;
        int count = 0;
        for (int i = 0; i < garo.size(); i++)
        {
            int ga = garo[i];
            
            // cout << ga << '\n';
            if (ga >= 0) 
            {
                total++;
            }
            else
            {
                total--;
            }

            if (total == 0 && i != garo.size() - 1)
            {
                count++;
            }
        }
        if (count >= 2)
        {
            return true;
        }
        count = 0;
        total = 0;
        // cout << '\n';
        for (int i = 0; i < garo.size(); i++)
        {
            int se = sero[i];
            // cout << se << '\n';
            if (se >= 0) 
            {
                total++;
            }
            else
            {
                total--;
            }

            if (total == 0 && i != garo.size() - 1)
            {
                count++;
            }
        }
        if (count >= 2)
        {
            return true;
        }
        return false;
    }
};