class Solution {
    public int[] arrayRankTransform(int[] arr) {
        int n = arr.length;
        if (n == 0)
        {
            return new int[] {};
        }
        int[][] arrs = new int[n][2];
        for (int i = 0; i < n; i++)
        {
            arrs[i][0] = arr[i];
            arrs[i][1] = i;
        } 
        Arrays.sort(arrs, (a, b) -> a[0] - b[0]);
        int rank = 1;
        int[] answer = new int[n];
        answer[arrs[0][1]] = 1;
        for (int i = 1; i < n; i++)
        {
            if (arrs[i][0] > arrs[i - 1][0]) rank++;
            answer[arrs[i][1]] = rank; 
        }
        return answer;
    }
}