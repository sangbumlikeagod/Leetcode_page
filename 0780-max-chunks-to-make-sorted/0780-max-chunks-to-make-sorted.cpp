class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        
        vector<int> arr_s;

        int answer = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] > i)
            {
                arr_s.push_back(arr[i]);
            }
            while(!arr_s.empty() && arr_s.back() <= i)
            {
                arr_s.pop_back();
            }
            if (arr_s.empty())
            {
                answer++;
            }
        }
        return answer;
    }
};