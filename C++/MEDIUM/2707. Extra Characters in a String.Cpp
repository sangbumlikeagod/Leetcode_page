class Trie
{

public:
    bool endOfWord;
    vector<Trie *> arr;
    Trie()
    {
        arr = vector<Trie *>(26, nullptr);
        endOfWord = false;
    }

    void search(vector<int> &DP, int index, int &length, string &s)
    {
        if (endOfWord)
        {
            // cout << "찾았는데 " << index << ' ' << length << ' ' << DP[index] << '\n';
            DP[index + length] = min(DP[index + length], DP[index] - length);
        }
        if (index + length < s.length() && arr[s[index + length] - 'a'])
        {
            // cout << s[index + length] << '\n';
            length++;
            index;
            arr[s[index + length - 1] - 'a']->search(DP, index, length, s);
        }
    }
};

class Solution
{
public:
    int minExtraChar(string s, vector<string> &dictionary)
    {
        Trie *original = new Trie();
        vector<int> DP(51, s.length());
        for (string word : dictionary)
        {
            Trie *a = original;
            int index = 0;
            while (index < word.length())
            {
                if (a->arr[word[index] - 'a'] == nullptr)
                {
                    a->arr[word[index] - 'a'] = new Trie();
                }
                a = a->arr[word[index] - 'a'];
                index++;
            }
            a->endOfWord = true;
        }
        int answer = s.length();
        for (int i = 0; i < s.length(); i++)
        {
            int length = 0;
            original->search(DP, i, length, s);
            // cout << '\t' << DP[i] << '\n';
            DP[i + 1] = min(DP[i + 1], DP[i]);
        }
        for (int i = 0; i <= s.length(); i++)
        {
            answer = min(answer, DP[i]);
        }
        return answer;
    }
};