class Solution {
public:
    long long coloredCells(int n) {
        // 한변은 n크기
        // 두 변은 n - 1 크기
        // 나머지 한 번은 n - 2 크기
        if (n == 1) return 1;

        // 2부터 그 뒤까지 4n - 4가 되는거지 
        // 이거 다더하면 
        return 2 *  (long long) (n - 1) * (long long) (n) + 1; 
    }
};