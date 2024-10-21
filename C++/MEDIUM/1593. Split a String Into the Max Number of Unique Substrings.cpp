class Solution
{
    int N;
    int publicService(int st, string &s, unordered_map<string, int> &mapp)
    {
        int answer = -1;
        string str;
        if (st == N)
        {
            return 0;
        }
        while (st < N)
        {
            str += s[st];
            st++;
            if (answer >= 1 + N - st)
                break;
            if (mapp.find(str) != mapp.end())
                continue;
            mapp[str]++;
            int tmp = publicService(st, s, mapp);
            mapp.erase(str);
            if (tmp == -1)
                continue;
            if (tmp + 1 > answer)
                answer = tmp + 1;
        }
        return answer;
    }

public:
    int maxUniqueSplit(string s)
    {
        N = s.length();
        unordered_map<string, int> mapp;
        return publicService(0, s, mapp);
    }
};