class Solution {
    public int totalMoney(int n) {
        int a = n / 7, remainder = n % 7;
        return a * remainder + ((remainder) * (remainder + 1) / 2) + 28 * a + 7 * (a * (a - 1) / 2); 
    }
}