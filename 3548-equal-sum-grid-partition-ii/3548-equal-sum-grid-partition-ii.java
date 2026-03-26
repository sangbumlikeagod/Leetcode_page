class Solution {
    private int binarySearch(long[] sortedArray, long match)
    {
        int l = 0;
        int r = sortedArray.length;
        while (l < r)
        {
            int m = (l + r) / 2;
            if (sortedArray[m] < match)
            {
                l = m + 1;
            }
            else if (sortedArray[m] >= match)
            {
                r = m;
            }
        }
        return l;
    }
    public boolean canPartitionGrid(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;


        long[] prefixRows = new long[m + 1];
        long[] prefixCols = new long[n + 1];




        for (int i = 0; i < m; i++)
        {
            prefixRows[i + 1] = prefixRows[i];
            for (int j = 0; j < n; j++)
            {
                prefixRows[i + 1] += grid[i][j];
            }
        }

        for (int j = 0; j < n; j++)
        {
            prefixCols[j + 1] = prefixCols[j];
            for (int i = 0; i < m; i++)
            {
                prefixCols[j + 1] += grid[i][j];
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (prefixCols[i] * 2 == prefixCols[n])
            {
                return true;
            }
        }

        for (int i = 0; i < m; i++)
        {
            if (prefixRows[i] * 2 == prefixRows[m])
            {
                return true;
            } 
        }
        // 안지우는건 여기서 다 해결했는데 

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                // 쿼리는 두번 한다, 행과 열, 거기서 나오는 값이 내 왼쪽에 있다면 합격이다.
                // 그리고 기본적으로 0과 맨끝 (m, n)에서는 1차이 나는 것도 막아야한다

                long rowMax = prefixRows[m];
                long colMax = prefixCols[n];                

                // System.out.println("# " + i + " " + j);
                if ((rowMax - grid[i][j]) % 2 == 0)
                {

                    // 자르는 칸 왼쪽에 값이 있을떄
                    int matchLeftRow = binarySearch(prefixRows, (rowMax - grid[i][j]) / 2);
                    // 자르는 칸 오른쪽에 값이 있을때
                    int matchRightRow = binarySearch(prefixRows, (rowMax - grid[i][j]) / 2 + grid[i][j]);
                    // System.out.println(matchLeftRow + " " + i + "  " + matchRightRow);
                    if (matchLeftRow <= i &&  prefixRows[matchLeftRow] == (rowMax - grid[i][j]) / 2)
                    {
                        // System.out.println(1 + " matchLeftRow" + matchLeftRow);
                        if (m - matchLeftRow == 1)
                        {
                            if (j == 0 || j == n - 1)
                            {
                                return true;
                            }
                        }
                        else
                        {
                            if (n != 1 || matchLeftRow == i || i == m - 1)
                            {
                                return true;
                            }
                        }
                    }
                    if (i < matchRightRow && prefixRows[matchRightRow] == (rowMax - grid[i][j]) / 2 + grid[i][j])
                    {
                        // System.out.println(2 + " matchRightRow" + matchRightRow);

                        if (matchRightRow == 1)
                        {
                            if (j == 0 || j == n - 1)
                            {
                                return true;
                            }
                        }
                        else
                        {
                            if (n != 1 || matchRightRow == i + 1 || i == 0)
                            {
                                return true;
                            }
                        }
                    }

                }
                if ((colMax - grid[i][j]) % 2 == 0)
                {
                    // 이거부터가 지웠을떄를 기준으로 찾는거라 말이안됨 
                    // int matchCol = binarySearch(prefixCols, (colMax - grid[i][j]) / 2);
                    // System.out.println(" val: " + (colMax - grid[i][j]));

                    int matchLeftCol = binarySearch(prefixCols, (colMax - grid[i][j]) / 2);
                    // 자르는 칸 오른쪽에 값이 있을때
                    int matchRightCol = binarySearch(prefixCols, (colMax - grid[i][j]) / 2 + grid[i][j]);

                    // System.out.println(matchLeftCol + " " + j + "  " + matchRightCol);
                    if (matchLeftCol <= j && prefixCols[matchLeftCol] == (colMax - grid[i][j]) / 2)
                    {
                        // System.out.println(3);
                        
                        // System.out.println(3 + " matchLeftCol" + matchLeftCol);

                        if (n - matchLeftCol == 1)
                        {
                            if (i == 0 || i == m -1)
                            {
                                return true;
                            }
                        }
                        else
                        {
                            if (m != 1 || matchLeftCol == j || j == n - 1)
                            {
                                return true;
                            }
                        }
                    }
                    if (j < matchRightCol && prefixCols[matchRightCol] == (colMax - grid[i][j]) / 2 + grid[i][j])
                    {
                        // System.out.println(4);
                        // System.out.println(4 + " matchRightCol" + matchRightCol);

                        if (matchRightCol == 1)
                        {
                            if (i == 0 || i == m -1)
                            {
                                return true;
                            }
                        }
                        else
                        {
                            if (m != 1 || matchRightCol == j + 1 || j == 0)
                            {
                                return true;
                            }
                            // return true;
                        }
                    }

                }
                

            }
        }


        return false;


    }
}