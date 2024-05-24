class Solution {
    int dp[21][22] = {0,};


    int binarySearch(int end, int val, vector<int>& nums)
    {
        int start = 0;
        while (start < end)
        {
            int mid = (start + end) / 2;
            if (nums[mid] < val)
            {
                start = mid + 1;
            }
            else if (nums[mid] > val)
            {
                end = mid;
            }
            else
            {
                return mid;
            }
        }
        return nums[start] == val? start : -1; 
    }
public: 
    int beautifulSubsets(vector<int>& nums, int k) {
        
        sort(nums.begin(), nums.end());
        for (int i = 0; i < 21; i++)
        {
            for (int j = 0; j <21; j++)
            {
                if (i == j)
                {
                    dp[i][j] = 1;
                }
                else
                {
                    dp[i][j] = 0;
                }
            }
        } 
        int size = nums.size();
        int ans = 0;
        for (int idx = 0; idx < size; idx++)
        {
            dp[idx][size] = 0;
            for (int dpIdx = 0; dpIdx < size; dpIdx++)
            {
                dp[idx][size] += dp[idx][dpIdx];
            }
            int test = binarySearch(idx, nums[idx] - k, nums);

            if (test != -1)
            {
                cout << test << '\n';
                int afterTest = test + 1;
                while (afterTest < idx)
                {
                    dp[idx][afterTest] -= dp[afterTest][test];
                    cout << afterTest << " 는 " << test << " 에게 " <<  dp[afterTest][test] << "만큼 영향을 받았었다" << '\n';
                    dp[idx][size] -= dp[afterTest][test];
                    afterTest++;
                }  
            }
            // cout << dp[idx][size] << '\t';
            ans += dp[idx][size];

            int idx2 = idx + 1;
            
            while (idx2 < size)
            {
                if (nums[idx2] - nums[idx] != k)
                {
                    dp[idx2][idx] += dp[idx][size];
                }
                idx2++;
            }
        }
        cout << '\n';
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j <= size; j++)
            {
                cout << dp[i][j] << '\t';
            }
            cout << '\n';
        } 
        return ans;
    }
};


// class Solution {
//     int dp[21][22] = {0,};


//     int binarySearch(int end, int val, vector<int>& nums)
//     {
//         int start = 0;
//         while (start < end)
//         {
//             int mid = (start + end) / 2;
//             if (nums[mid] < val)
//             {
//                 start = mid + 1;
//             }
//             else if (nums[mid] > val)
//             {
//                 end = mid;
//             }
//             else
//             {
//                 return mid;
//             }
//         }
//         return nums[start] == val? start : -1; 
//     }
// public: 
//     int beautifulSubsets(vector<int>& nums, int k) {
        
//         sort(nums.begin(), nums.end());
//         for (int i = 0; i < 21; i++)
//         {
//             for (int j = 0; j <21; j++)
//             {
//                 if (i == j)
//                 {
//                     dp[i][j] = 1;
//                 }
//                 else
//                 {
//                     dp[i][j] = 0;
//                 }
//             }
//         } 
//         int size = nums.size();
//         int ans = 0;
//         for (int idx = 0; idx < size; idx++)
//         {
//             cout << idx << "\n\n";
//             dp[idx][size] = 0;
//             for (int dpIdx = 0; dpIdx < size; dpIdx++)
//             {
//                 dp[idx][size] += dp[idx][dpIdx];
//             }
//             int test = binarySearch(idx, nums[idx] - k, nums);

//             if (test != -1)
//             {
//                 cout << test << '\n';
//                 int afterTest = test + 1;
//                 while (afterTest < idx)
//                 {
//                     int afterTestToIdx = afterTest + 1 ;
//                     dp[idx][afterTest] -= dp[afterTest][test];
//                     dp[idx][size] -= dp[afterTest][test];
//                     while (afterTestToIdx < idx)
//                     {
//                         cout << "원래 " << idx << "는 " << afterTestToIdx << "에게 " <<  dp[idx][afterTestToIdx] << "이만큼 값을 받았다 그런데 " <<  afterTestToIdx << " 가 " << afterTest << "의 안에있는 " << test << "에게 " << dp[afterTest][test] << "만큼을 영향이 받았기 때문에 뺐다" << '\n'; 
//                         dp[idx][afterTestToIdx] -= dp[afterTest][test];
//                         dp[idx][size] -= dp[afterTest][test];
//                         // cout << afterTestToIdx << " 는 " << test << " 에게 " <<  dp[afterTestToIdx][test] << "만큼 영향을 받았었다" << '\n';
//                         afterTestToIdx++;
//                     }
//                     // dp[idx][afterTest] -= dp[afterTest][test];
//                     cout << afterTest << " 는 " << test << " 에게 " <<  dp[afterTest][test] << "만큼 영향을 받았었다" << '\n';

//                     // dp[idx][size] -= dp[afterTest][test];
                    
//                     afterTest++;
//                 }  
//             }
//             // cout << dp[idx][size] << '\t';
//             ans += dp[idx][size];

//             int idx2 = idx + 1;
            
//             while (idx2 < size)
//             {
//                 if (nums[idx2] - nums[idx] != k)
//                 {
//                     dp[idx2][idx] += dp[idx][size];
//                 }
//                 idx2++;
//             }
//         }
//         cout << '\n';
//         for (int i = 0; i < size; i++)
//         {
//             for (int j = 0; j <= size; j++)
//             {
//                 cout << dp[i][j] << '\t';
//             }
//             cout << '\n';
//         } 
//         return ans;
//     }
// };