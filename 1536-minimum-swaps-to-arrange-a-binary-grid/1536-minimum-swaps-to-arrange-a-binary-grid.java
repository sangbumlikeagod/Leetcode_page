class Solution {
    public int minSwaps(int[][] grid) {
        int n = grid[0].length;
        int[] cnts= new int[n];
        int[] visited = new int[n];
        int answer = 0;
        
        for (int j = 0; j < n ; j++)
        {
            int[] gridRow = grid[j];
            int cnt = 0;
            for (int i = n - 1; i >= 0; i--)
                {
                    if (gridRow[i] == 1)
                    {
                        break;
                    }
                    else
                    {
                        cnt++;
                    }
                }
            cnts[j] = cnt;
        }

        
        for (int i = 0, cnt = n - 1; i < n; i++, cnt--)
        {
            boolean getValue = false;
            for (int j = 0, ccnt = 0; j < n; j++)
            {
                if (visited[j] == 0 && cnts[j] >= cnt)
                {
                    answer += ccnt;
                    visited[j] = 1;
                    getValue = true;
                    break;
                }
                else if (visited[j] == 0)
                    {
                    ccnt++;
                    }
            }
            
            if (!getValue) return -1;
        }

        return answer;
    }
}