class Solution
{
    // unordered
public:
    bool areSentencesSimilar(string sentence1, string sentence2)
    {
        // s1이 더 큰걸로
        if (sentence1.length() < sentence2.length())
        {
            swap(sentence1, sentence2);
        }

        if (sentence1 == sentence2)
        {
            return true;
        }
        if (sentence2.length() == 1)
        {
            return (sentence1[0] == sentence2[0] && sentence1[1] == ' ') || (sentence1[sentence1.length() - 1] == sentence2[sentence2.length() - 1] && sentence1[sentence1.length() - 2] == ' ');
        }

        int s2 = 0, e2 = sentence2.length() - 1;
        int s1 = 0, e1 = sentence1.length() - 1;
        bool isSingleWord = true;
        while (s2 <= e2 && (sentence1[s1] == sentence2[s2] || sentence1[e1] == sentence2[e2]))
        {
            cout << s2 << ' ' << e2 << '\n';
            if (sentence1[s1] == sentence2[s2])
            {
                if (sentence2[s2] == ' ')
                    isSingleWord = false;
                if (s2 < sentence2.length())
                    s1++;
                s2++;
            }
            else
            {
                if (sentence2[s2] == ' ' || sentence1[s2] == ' ')
                    return false;
            }
            if (sentence1[e1] == sentence2[e2])
            {
                if (sentence2[e2] == ' ')
                    isSingleWord = false;
                if (e2 >= 0)
                    e2--;
                e1--;
            }
            else
            {
                if (sentence2[e2] == ' ' || sentence1[e2] == ' ')
                    return false;
            }
        }

        if (s2 > e2)
        {
            if (isSingleWord)
            {

                if (sentence2.length() == sentence1.length())
                {
                    return true;
                }
                if ((s2 == sentence2.length() || e2 == -1))
                {
                    // cout << s2 << ' ' << e2 << '\n';
                    if (s2 == sentence2.length())
                    {
                        return sentence1[s2] == ' ';
                    }
                    if (e2 == -1)
                    {
                        return sentence1[sentence1.length() - sentence2.length() - 1] == ' ';
                    }
                }
                else
                {
                    return false;
                }
                return sentence1 == sentence2;
            }
            else
            {
                if (s2 == 0)
                {
                    return sentence1[sentence1.length() - sentence2.length() - 1] == ' ';
                }
                else if (e2 == sentence2.length() - 1)
                {
                    return sentence1[s2] == ' ';
                }
                else
                {
                    return true;
                }
            }
        }
        return false;
    }
};