class Solution {
    public long flowerGame(int n, int m) {
        long ne = n / 2, no = n % 2 + n / 2,  mo = m / 2 + m %2, me = m /2;
        return ne * mo + me * no;
    }
}