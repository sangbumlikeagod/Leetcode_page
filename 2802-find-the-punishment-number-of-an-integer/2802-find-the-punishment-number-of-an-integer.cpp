class Solution {

    bool backTracking(int& answer, string& str, string& goal, int index, int byfar, int byfarS)
    {
        if (index == str.length())
        {
            if (to_string(byfar + byfarS) == goal)
            {
                // cout << str << ' ' << byfar + byfarS << '\n';
                return true;
            }
            return false;
        }
        else if (byfar + byfarS > stoi(goal))
        {    
            return false;
        }
        // cout << index << '\n';
        int thT = str[index] - '0';
        if (backTracking(answer, str, goal, index + 1, byfar + byfarS, thT)) return true;
        if (backTracking(answer, str, goal, index + 1, byfar, byfarS * 10 + thT)) return true;
        return false;
    }
public:
    int punishmentNumber(int n) {
        int answer = 0;
        for (int i = 0; i <= n; i++)
        {
            int tmp = i * i;

            int tnp = 0;
            string str = to_string(tmp);
            string goal = to_string(i);
            if (backTracking(tnp, str, goal, 0, 0, 0)) answer += tmp;
        }
        return answer;
    }
};