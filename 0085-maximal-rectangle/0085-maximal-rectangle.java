class Solution {
    public int maximalRectangle(char[][] matrix) {
        int m = matrix.length, n = matrix[0].length;  

        int[][] prefixHeights = new int[m + 1][n];

        for (int i = 1; i <= m; i++)
         {
            for (int j = 0; j < n; j++)
                {
                    prefixHeights[i][j] = matrix[i - 1][j] == '0' ? 0 : 1 + prefixHeights[i - 1][j];
                }
         }

        int answer = 0;


        for (int i = 1; i <= m; i++)
            {
                Stack<int[]> monoStack = new Stack<>();
                int maxValue = 0;
                for (int j = 0; j < n; j++)
                {
                    int myIndex = j;
                    while (monoStack.isEmpty() == false && monoStack.peek()[1] >= prefixHeights[i][j])
                        {
                            maxValue = Math.max(maxValue, monoStack.peek()[1] * (j - monoStack.peek()[0])); 
                            myIndex = monoStack.peek()[0];
                            monoStack.pop();


                        }
                    if (monoStack.isEmpty() || (prefixHeights[i][j] != 0))
                    {
                        monoStack.push(new int[] {myIndex, prefixHeights[i][j]});
                    }  
                }
                // 다 돌았을떄 소모시켜줘야함
                while (monoStack.isEmpty() == false)
                {
                    maxValue = Math.max(maxValue, monoStack.peek()[1] * (n - monoStack.peek()[0]));
                    monoStack.pop();
                }

                monoStack = new Stack<>();
                for (int j = n - 1; j >= 0; j--)
                {
                    int myIndex = j;
                    while (monoStack.isEmpty() == false && monoStack.peek()[1] > prefixHeights[i][j])
                    {
                        maxValue = Math.max(maxValue, monoStack.peek()[1] * (monoStack.peek()[0] - j));
                        myIndex = monoStack.peek()[0];
                        monoStack.pop();
                    }
                    if (monoStack.isEmpty() || (monoStack.peek()[1] != prefixHeights[i][j] && prefixHeights[i][j] != 0))
                    {
                        monoStack.push(new int[] {myIndex, prefixHeights[i][j]});
                    }  
                }
                while (monoStack.isEmpty() == false)
                {
                    maxValue = Math.max(maxValue, monoStack.peek()[1] * (monoStack.peek()[0]));
                    monoStack.pop();

                }
                
                answer = Math.max(answer, maxValue);
            }
        return answer;
        
        
    }
}