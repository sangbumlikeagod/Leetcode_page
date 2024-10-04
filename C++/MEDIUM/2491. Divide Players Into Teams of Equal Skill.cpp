class Solution
{
public:
    long long dividePlayers(vector<int> &skill)
    {
        int wantedVal = 0;
        long long answer = 0;
        for (int arg : skill)
        {
            wantedVal += arg;
        }
        wantedVal /= skill.size() / 2;
        sort(skill.begin(), skill.end());
        int s = 0, e = skill.size() - 1;
        while (s < e)
        {
            if (skill[s] + skill[e] == wantedVal)
            {
                answer += skill[s++] * skill[e--];
            }
            else
            {
                return -1;
            }
        }
        return answer;
    }
};