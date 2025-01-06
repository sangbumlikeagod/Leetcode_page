class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> left(boxes.length(), 0);
        vector<int> right(boxes.length(), 0);
        int ballCount = 0;
        for (int i = 0; i < boxes.length() - 1; i++)
        {
            if (boxes[i] == '1')
            {
                ballCount++;
            }
            left[i + 1] = left[i] + ballCount;
        }
        ballCount = 0;
        for (int i = boxes.length() - 1; i > 0; i--)
        {
            if (boxes[i] == '1')
            {
                ballCount++;
            }
            right[i - 1] = right[i] + ballCount;
        }


        for (int i = 0; i < boxes.length(); i++)
        {
            left[i] += right[i];
        }
        return left;
    }
};