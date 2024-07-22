class Solution
{
public:
    vector<string> sortPeople(vector<string> &names, vector<int> &heights)
    {
        vector<int> readies(names.size(), 0);
        for (int i = 0; i < names.size(); i++)
        {
            readies[i] = i;
        }
        sort(names.begin(), names.end(), [&readies, &mapps](string a, string b)
             { return heights[mapps[a]] > heights[mapps[b]]; });

        return names;
    }
};