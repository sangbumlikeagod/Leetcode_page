class Solution {
    int MODULO = 1000000007;
public:
    int numOfSubarrays(vector<int>& arr) {
        vector<pair<int, int>> preposition(arr.size() + 1, {0, 0});
        preposition[0] = {0, 0};
        int answer = 0;
        // 홀수면 홀수 substring개수만큼 짝수에 더해주고, 짝수 스트림개수만큼 홀수에 ㄷ더해줘야지 짝수면,, 짝수 스트림에 더하고 홀수 스트림에 호수만큼더하고


        for (int i = 0; i < arr.size(); i++)
        {
            int odd = preposition[i].first;
            int even = preposition[i].second;

            {
                if (arr[i] % 2)
                {
                    int tmp = odd;
                    odd = even + 1;
                    even = tmp;
                }
                else
                {
                    odd = odd;
                    even = even + 1;
                }
            }
            answer += odd;
            answer %= MODULO;
            preposition[i + 1] = {odd % MODULO, even % MODULO};
        }
        return answer;
    }
};