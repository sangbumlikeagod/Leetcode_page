class Solution {
public:
    vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
        int p1 = 0, p2 = 0, p3 = 0;
        vector<int> answer {};
        while(p1 < arr1.size() && p2 < arr2.size() && p3 < arr3.size())
        {
            if (arr1[p1] == arr2[p2] && arr2[p2] == arr3[p3])
            {
                answer.push_back(arr1[p1]);
                p1++; p2++; p3++;
            }
            else
            {
                int tmp = arr1[p1];
                if (arr2[p2] < tmp)
                {
                    tmp = arr2[p2];
                }
                if (arr3[p3] < tmp)
                {
                    tmp = arr3[p3];
                }

                if (tmp == arr1[p1])
                {
                    p1++;
                    continue;
                }
                if (tmp == arr2[p2])
                {
                    p2++;
                    continue;
                }
                if (tmp == arr3[p3])
                {
                    p3++;
                    continue;
                }
            }
        }
        return answer;
    }
};