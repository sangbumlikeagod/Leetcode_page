class Solution
{
public:
    int trap(vector<int> &height)
    {
        int left = 0;
        vector<int> unRealizedStack{};
        vector<int> numOfUnRealizedStack{};
        int ans = 0;
        for (int arg : height)
        {
            int tmp = 0;
            int numOfSameHeight = 1;
            while (unRealizedStack.empty() == false)
            {
                if (unRealizedStack[unRealizedStack.size() - 1] > arg)
                    break;
                tmp += (arg - unRealizedStack[unRealizedStack.size() - 1]) * numOfUnRealizedStack[numOfUnRealizedStack.size() - 1];
                numOfSameHeight += numOfUnRealizedStack[numOfUnRealizedStack.size() - 1];
                numOfUnRealizedStack.pop_back();
                unRealizedStack.pop_back();
            }
            if (unRealizedStack.empty() == false)
            {
                ans += tmp;
            }
            unRealizedStack.push_back(arg);
            numOfUnRealizedStack.push_back(numOfSameHeight);
        }
        return ans;
    }
};