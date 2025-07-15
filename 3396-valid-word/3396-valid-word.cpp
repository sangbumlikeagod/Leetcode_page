class Solution {
public:
    bool isValid(string word) {
        if (word.length() < 3) return false;
        bool c3 = false;
        bool c2 = false;
        for (char c : word)
        {
            int n1 = c - 'a';
            int n2 = c - '0';
            int n3 = c - 'A';
            // cout << c << '\n';
            if (0 <= n1 && n1 <= 26)
            {
                if (c == 'a' || \
                    c == 'A' || \
                    c == 'e' || \
                    c == 'E' || \
                    c == 'i' || \
                    c == 'I' || \
                    c == 'o' || \
                    c == 'O' || \
                    c == 'u' || \
                    c == 'U' \ 
                ) {c3 = true;}
                else{
                    c2 = true;
                }
            }
            else if (0 <= n2 && n2 <= 10)
            {

            }
            else if (0 <= n3 && n3 <= 26)
            {
                if (c == 'a' || \
                    c == 'A' || \
                    c == 'e' || \
                    c == 'E' || \
                    c == 'i' || \
                    c == 'I' || \
                    c == 'o' || \
                    c == 'O' || \
                    c == 'u' || \
                    c == 'U' \ 
                ) {c3 = true;}
                else{
                    c2 = true;
                }
            }
            else return false;
        }
        return c2 && c3;
    }
};