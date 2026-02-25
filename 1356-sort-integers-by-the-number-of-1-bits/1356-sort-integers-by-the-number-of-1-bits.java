class Solution {
    private int getBits(int n)
    {
        int ret = 0;
        while (n > 0)
        {
            ret += (n & 1);
            n >>= 1;
        }
        return ret;
    }
    public int[] sortByBits(int[] arr) {
        int n = arr.length;


        int[][] sortedArray = new int[n][2];
        for (int i = 0; i < n; i++)
        {
            sortedArray[i][0] = arr[i];
            sortedArray[i][1] = getBits(arr[i]);
        }
        Arrays.sort(sortedArray, (a, b) -> {
            if (a[1] != b[1])
            {
                return a[1] - b[1];
            }
            return a[0] - b[0];
        });
        int[] answer = new int[n];
        for (int i =0 ;i < n;i ++)
        {
            answer[i] = sortedArray[i][0];
        }
        
        return answer;
    }
}