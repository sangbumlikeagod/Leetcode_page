class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int i = 0; 
        int n = bits.size();
        int last = -1;
        while (i < n)
        {
            if (bits[i] == 0)
            {
                i ++;
                last = 1;
            }
            else
            {
                i += 2;
                last = 0;
            }
        }
        return last;
    }
};