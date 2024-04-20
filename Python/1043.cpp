// 잘못된 풀이

class Solution
{
    map<int, short> palette;

public:
    int maxSumAfterPartitioning(vector<int> &arr, int k)
    {
        int ans = 0;
        for (int i = 0; i < k - 1; i++)
        {
            palette[arr[i]] = 1;
        }

        for (int i = 0; i < arr.size(); i++)
        {
            // 더하고 언제부터 더하지 않냐면 이미 모두 더해졌을 때 k가 3일때 0에선 2번째 애를 더해야함 그렇다면 i - 1 번째에선 i - 3번째 부터 빼지지 않아야함
            if (i < arr.size() - k - 1)
            {
                palette[arr[i + k - 1]] += 1;
            }

            cout << (--palette.end())->first << endl;
            ans += (--palette.end())->first;

            // 빼고
            if (k - 1 < i)
            {
                palette[arr[i - (k - 1)]] -= 1;
                if (!palette[arr[i - (k - 1)]])
                {
                    palette.erase(arr[i - (k - 1)]);
                }
            }
        }
        return ans;
    }
};