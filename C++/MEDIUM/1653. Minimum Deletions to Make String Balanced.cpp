class Solution {
public:
    int minimumDeletions(string s) {
        vector<int> shouldDb (s.length(), 0);
        vector<int> shouldDa (s.length(), 0);

        for (int a = 0; a < s.length(); a++)
        {
            shouldDb[a] = (a ? shouldDb[a - 1] : 0) + (s[a] == 'b');
        }
        for (int b = s.length() - 1; b >= 0; b--)
        {
            shouldDa[b] = b != s.length() - 1 ? shouldDa[b + 1] + (s[b + 1] == 'a') : 0;
        }

        // if (shouldDb[s.length() - 1] == s.length()) return 0;

        int deleteIndex = 0;
        int answer = 100001;
        for (int c = 0; c < s.length(); c++)
        {
            // cout << shouldDa[c] << ' ' << shouldDb[c] << '\n';
            if (shouldDa[c] + shouldDb[c] < answer) 
            {
                answer = shouldDa[c] + shouldDb[c];
                deleteIndex = c;
            }
        }
        // cout << deleteIndex << '\n';
        if (!deleteIndex && shouldDb[0] == 1)
        {
            answer--;
        }
        return answer;
    }
};