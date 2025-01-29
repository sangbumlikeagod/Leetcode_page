class Solution {
public:
    int trap(vector<int>& height) {
        vector<pair<int, int>> stack {};

        int answer = 0;
        for (int i = 0; i < height.size(); i++)
        {
            if (stack.empty() == false)
            {
                while (height[i] >= stack.back().first)
                {
                    auto tmp = stack.back();
                    stack.pop_back();
                    if (stack.empty()) break;
                    answer += (i - stack.back().second - 1) * (min(stack.back().first, height[i]) - tmp.first);
                }
            }
            stack.push_back({height[i], i});
        }
        return answer;
    }
};