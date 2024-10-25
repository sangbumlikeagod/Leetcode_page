class Solution
{
    unordered_map<string, int> roots;

public:
    vector<string> removeSubfolders(vector<string> &folder)
    {
        sort(folder.begin(), folder.end(), [](string &a, string &b)
             { return a.length() < b.length(); });
        vector<string> answer;
        for (string a : folder)
        {
            string byFar;
            bool root = true;
            for (int i = 1; i < a.length(); i++)
            {
                if (a[i] == '/')
                {
                    if (roots.find(byFar) != roots.end())
                    {
                        root = false;
                        break;
                    }
                }
                byFar += a[i];
            }
            if (!root)
                continue;
            roots[byFar]++;
            answer.push_back('/' + byFar);
        }
        return answer;
    }
};