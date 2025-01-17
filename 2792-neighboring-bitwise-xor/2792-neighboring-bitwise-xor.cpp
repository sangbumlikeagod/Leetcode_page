class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        if (derived.size() == 1) return !derived[0];

        int oneif = 1;
        int zeroif = 0;
        // 1일때 derived[0]뭔지 파악
        for (int i = 1; i <= derived.size(); i++)
        {
            if (derived[i - 1])
            {
                // 1이라면 
                if (zeroif == 1)
                {
                    zeroif = 0;
                }
                else
                {
                    zeroif = 1;
                }

                if (oneif == 1)
                {
                    oneif = 0;
                }
                else
                {
                    oneif = 1;
                }
            }
        }
        return zeroif == 0 || oneif == 1;
        
    }
};