class Solution
{
    vector<string> sentences = {};
    vector<int> sentencesOV = vector<int>(1000, 0);

public:
    string replaceWords(vector<string> &dictionary, string sentence)
    {

        sort(dictionary.begin(), dictionary.end());
        string word = "";
        for (char c : sentence)
        {
            if (c != ' ')
            {
                word += c;
            }
            else
            {
                // string newword = word;
                cout << word << '\n';
                sentences.push_back(word);
                word = "";
            }
        }
        sentences.push_back(word);

        for (string root : dictionary)
        {
            for (int idx = 0; idx < sentences.size(); idx++)
            {
                bool isDeriviated = true;
                if (sentencesOV[idx] == 1 || root.length() > sentences[idx].length())
                {
                    continue;
                }
                for (int c = 0; c < root.length(); c++)
                {
                    if (sentences[idx][c] != root[c])
                    {
                        isDeriviated = false;
                        break;
                    }
                }
                if (isDeriviated)
                {
                    sentences[idx] = root;
                    sentencesOV[idx] = 1;
                }
            }
        }
        string ans = "";
        for (int wordindex = 0; wordindex < sentences.size(); wordindex++)
        {
            ans += sentences[wordindex];
            if (wordindex == sentences.size() - 1)
                break;
            ans += ' ';
        }
        return ans;
    }
};