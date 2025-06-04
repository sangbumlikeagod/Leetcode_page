class Solution {

    string cmp(string& a, string& b)
    {
        for (int i = 0; i < a.length(); i++)
            {
                if (a[i] < b[i])
                {
                    return b;
                }
                else if (a[i] > b[i])
                {
                    return a;
                }
            }
        return a;
    }
public:
    string answerString(string word, int numFriends) {
        if (numFriends == 1) return word;
        int length = word.length() - numFriends + 1;
        string answer = word.substr(0, length);
        for (int i = 1; i < word.length(); i++){
            string newString = word.substr(i, length);
            answer = cmp(answer, newString);
        }
        return answer;
    }
};