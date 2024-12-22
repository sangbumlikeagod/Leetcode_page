class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights,
                                        vector<vector<int>>& queries) {
        // 모노토닉 스택
        vector<pair<int, int>> monoStack;
        
        // 결과에 대한 코드
        vector<int> result(queries.size(), -1);
        
        // 쿼리를 새로 만들었다 
        vector<vector<pair<int, int>>> newQueries(heights.size());
        for (int i = 0; i < queries.size(); i++) {
            int a = queries[i][0];
            int b = queries[i][1];
            // 나처럼 스왑해서 a가 b보다 무조건 작게 만들고
            if (a > b) swap(a, b);
            // 둘이 높이차가 일정하면 나처럼 결과를 같게 만들었다 
            if (heights[b] > heights[a] || a == b)
                result[i] = b;
            else
		            // 새로운 쿼리는 그냥 높이 높이별로, 더 커야하는 값, 인덱스를 정보로  
                newQueries[b].push_back({heights[a], i});
        }

				// heights - 1 부터 0까지 반복하는데 모든 heights별로 쿼리를 다시 때린다고? 
        for (int i = heights.size() - 1; i >= 0; i--) {
            int monoStackSize = monoStack.size();
            for (auto& [a, b] : newQueries[i]) {
			          // 이진탐색을 하는 포지션, 그 값에서 서치가 제대로 됐을 경우 그 스택의 포지션의 2번째 값을 답으로 
                int position = search(a, monoStack);
                if (position < monoStackSize && position >= 0)
                    result[b] = monoStack[position].second;
            }
            while (!monoStack.empty() && monoStack.back().first <= heights[i])
		            // 높이가 heights[i]보다 작거나 같은애들은 전부 빼버리는 방식
                monoStack.pop_back();
            // 현재 내 높이와 순서를 넣는다., 
            monoStack.push_back({heights[i], i});
        }
        return result;
    }

private:
    int search(int height, vector<pair<int, int>>& monoStack) {
        int left = 0;
        int right = monoStack.size() - 1;
        int ans = -1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (monoStack[mid].first > height) {
                ans = max(ans, mid);
                left = mid + 1;
            } else
                right = mid - 1;
        }
        return ans;
    }
};