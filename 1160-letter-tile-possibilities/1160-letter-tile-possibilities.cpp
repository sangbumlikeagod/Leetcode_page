class Solution {
    unordered_map<int, int> mapps[8];
    void backTracking(vector<int>& freq, int index, int limit, int now, int& answer){
        if (index == limit)
        {
            if (mapps[index].find(now) == mapps[index].end())
            {
                mapps[index][now]++;
                answer++; 
                return;
            }
            return;
        }

        for (int i = 0; i < 26; i++)
        {
            if (freq[i] == 0) continue;
            long long cc = (long long) now * 27 + (i + 1);
            if (mapps[index].find(cc) == mapps[index].end())
            {
                mapps[index][cc]++;
                freq[i]--;
                backTracking(freq, index + 1, limit, cc, answer);
                freq[i]++;
            }
        }
        backTracking(freq, index + 1, limit, now, answer);
    }
public:
    int numTilePossibilities(string tiles) {
        // 중복순열 생각이나 근데 정확히 중복순열은 아님
        vector<int> freq(26, 0);
        for (char c : tiles)
        {
            freq[c - 'A']++;
        }
        int answer = 0;
        mapps[tiles.length()][0] = 1;
        backTracking(freq, 0, tiles.length(), 0, answer);
        return answer;
    }
};