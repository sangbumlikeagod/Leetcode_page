class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        // 
        int kC = k;
        
        int n = fruits.size();
        // 여기부터는 맞다 
        int left = (upper_bound(fruits.begin(), fruits.end(), vector<int> {startPos - k, 0}) - fruits.begin());
        // 여기까지가 한계다
        int leftLimit = (upper_bound(fruits.begin(), fruits.end(), vector<int> {startPos - 1, 200000}) - fruits.begin()) - 1;
        // 본인을 포함하지 않는 가장 큰 왼쪽인덱스 에대해서 계산한다 
        int right =(upper_bound(fruits.begin(), fruits.end(), vector<int> {startPos + k, 200000}) - fruits.begin()) - 1;
        // 이렇게 하면 갈수있는 가장오른쪽의 값을 구하게 되는것  
        int rightLimit = (upper_bound(fruits.begin(), fruits.end(), vector<int> {startPos, 200000}) - fruits.begin());

        
        // 반드시 먹을 수 있는 값을 계산한다 미리
        int basic = rightLimit - leftLimit > 1 ? fruits[rightLimit - 1][1] : 0;
        int answer = 0;
        int value = 0;
        int leftC = left;

        
        // 왼쪽부터 진행한다
        while (leftC >= 0 && leftC < n && fruits[leftC][0] < startPos)
        {
            value += fruits[leftC][1];
            leftC++;
        }
        
        leftC = left;
        int rightC = rightLimit;
        answer = max(answer, value);
    
        if (rightC != n)
        {
            while (rightC < n && leftC >= 0 && leftC < n && fruits[leftC][0] < startPos)
            {
                while (rightC < n && k < (fruits[rightC][0] - startPos) + 2 * (startPos - fruits[leftC][0]))
                {
                    value -= fruits[leftC++][1];
                }
                if (leftC <= leftLimit && rightC < n)
                {
                    value += fruits[rightC++][1];
                }   
                // cout << leftC << ' ' << value << ' ' << rightC << '\n';
                answer = max(answer, value);
            }
        }

        rightC = right;
        value = 0;

        while (0 <= rightC && rightC < n && fruits[rightC][0] > startPos)
            {
                value += fruits[rightC--][1];
            }
        
        rightC = right;
        leftC = leftLimit;
        answer = max(answer, value);

        if (leftC != -1)
        {
            while (leftC >= 0 && 0 <= rightC && rightC < n && fruits[rightC][0] > startPos)
            {
                while (leftC >= 0 && k < (startPos - fruits[leftC][0]) + 2 * (fruits[rightC][0] -  startPos))
                {
                    value -= fruits[rightC--][1];
                }

                if (rightC >= rightLimit && leftC >= 0)
                {
                    value += fruits[leftC--][1];
                }
                answer = max(answer, value);
            }
        }

        
        return answer + basic;
    }
};