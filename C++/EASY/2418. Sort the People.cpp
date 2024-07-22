class Solution
{
public:
    vector<string> sortPeople(vector<string> &names, vector<int> &heights)
    {
        vector<pair<string, int>> readies(names.size());
        for (int i = 0; i < names.size(); i++)
        {
            readies[i] = {names[i], heights[i]};
        }
        sort(readies.begin(), readies.end(), [&readies](pair<string, int> a, pair<string, int> b)
             { return a.second > b.second; });
        for (int i = 0; i < names.size(); i++)
        {
            names[i] = readies[i].first;
        }
        return names;
    }
};