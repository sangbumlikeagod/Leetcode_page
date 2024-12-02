class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        char separator = ' ';    
        istringstream iss(sentence);
        string str_buf;
        int index = 1;
        while (getline(iss, str_buf, separator)) {
            // cout << str_buf << '\n';
            if (str_buf.length() >= searchWord.length())
            {
                string tmp = str_buf.substr(0, searchWord.length());
                // cout << tmp <<  (tmp.compare(searchWord) == 0) << '\n';
                if (tmp.compare(searchWord) == 0)
                {
                    return index;
                }
            }   
            index++;
        }
        return -1;

    }
};