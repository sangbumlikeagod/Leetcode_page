class Solution
{
public:
    bool isCircularSentence(string sentence)
    {
        if (sentence[0] != sentence[sentence.length() - 1])
            return false;

        char l1;
        char l2;

        int index = 0;
        while (index < sentence.length())
        {
            if (sentence[index] == ' ')
            {
                l1 = sentence[index - 1];
                l2 = sentence[index + 1];
                if (l1 != l2)
                    return false;
            }
            index++;
        }
        return true;
    }
};