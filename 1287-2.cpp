class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        // 
        int size = arr.size();
        // 벡터의 사이즈를 얻는다 
        int qtr = size / 4;
        // 4분할 됨 왜?
        int cnt = 1;
        // 
        int p = arr[0];
        // 시작점 설정 
        for (int i = 1 ; i < size ; i++) {
            // 1번부터 끝까지 적용
            if ( p == arr[i]) cnt++;
            else cnt = 1;
            // 개수를 센다
            if (cnt > qtr) return arr[i];
            // 더 커졌을 경우 리턴한다
            p = arr[i];
            // 해당하는 숫자로 시작점을 이동
        }

        return p;
    }
};