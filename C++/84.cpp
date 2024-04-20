class Solution
{
    int left[100001]{0};
    int right[100001]{0};

public:
    int largestRectangleArea(vector<int> &heights)
    {
        int siz = heights.size();
        int ans = 0;
        right[siz - 1] = siz - 1;
        for (int i = 1; i < siz; i++)
        {
            right[i] = i;
            left[i] = i;
            int hLeft = i;
            // 본인보다 크다면 왼쪽을 골라잉 이런걸 어떻게 빨리짜냐는거야
            while (hLeft >= 0 && heights[i] <= heights[hLeft])
            {
                left[i] = left[hLeft];
                // cout << left[hLeft] - 1 << '\n';
                hLeft = left[hLeft] - 1;
            }
        }

        for (int i = siz - 1; i >= 0; i--)
        {
            int hRight = i;
            // cout << '\t' << i << '\n';
            while (hRight < siz && heights[i] <= heights[hRight])
            {
                right[i] = right[hRight];
                // cout << right[hRight] + 1 << '\n';
                hRight = right[hRight] + 1;
            }
            ans = max(ans, heights[i] * (right[i] - left[i] + 1));
        }
        return ans;
    }
};