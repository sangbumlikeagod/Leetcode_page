class Solution {
    public int maximumElementAfterDecrementingAndRearranging(int[] arr) {
        Arrays.sort(arr);
        arr[0] = 1;
        int tt = 1;
        for (int i = 1; i < arr.length; i++)
        {
            tt = Math.min(arr[i], tt + 1);
        }
        return tt;
    }
}