class Solution {
    int binarySearch(int[] arr)
    {
        int l = 0, r = arr.length - 1;
        while (l != r)
        {
            int m = (l + r) / 2;
            if (arr[m] < 0)
            {
                r = m;
            }
            else
            {
                l = m + 1;
            }
        }
        return l;
    }


    public int countNegatives(int[][] grid) {
        int answer = 0;
        for (int[] gr : grid)
        {
            if (gr[gr.length - 1] >= 0) continue;
            int idx = binarySearch(gr);
            System.out.println(idx);
            answer += gr.length - idx;
        }

        return answer;    
    }
}