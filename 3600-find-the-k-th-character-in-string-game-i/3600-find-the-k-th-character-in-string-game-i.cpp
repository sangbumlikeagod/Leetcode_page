class Solution {
public:
    char kthCharacter(int k) {
        int ans = 0;

        int level = 0, rem = 0; 
        
        int c = 1;
        while (c < k)
        {
            c *= 2;
        }
        c /= 2;

        int answer = 0;
        while (c)
        {
            if (k > c)
            {
                k -= c;
                answer += 1;
            }
            c /= 2;
        }
        return 'a' + answer;
    }
};