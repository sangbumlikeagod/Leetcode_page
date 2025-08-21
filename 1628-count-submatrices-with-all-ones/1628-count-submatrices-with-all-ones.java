class Solution {
    private int sums(int n)
    {
        int ret = 0;
        while (n > 0)
        {
            ret += n;
            n--;
        }
        return ret;
    }
    public int numSubmat(int[][] mat) {
        int m = mat.length, n = mat[0].length;
        
        int[][] arg_y = new int[m + 2][n + 2];
        int[][] arg_x = new int[m + 2][n + 2];
        int[][] arg_square = new int[m + 1][n + 1];
        for (int j = 1; j <= n; j++)
        {
            for (int i = 1; i <= m; i++)
            {
                if (mat[i - 1][j - 1] == 1)
                {
                    arg_y[i][j] = arg_y[i - 1][j] + 1;
                }
            }
        }

        int answer = 0;
        
        for (int i = 1; i <= m; i++)
        {
            ArrayList<ArrayList<Integer>> vector = new ArrayList<>();
            ArrayList<Integer> tmp = new ArrayList<>();
            tmp.add(0);
            tmp.add(0);
            vector.add(tmp);
            for (int j = 1; j <= n + 1; j++)
            {
                if (vector.get(vector.size() - 1).get(1) == arg_y[i][j])
                {
                }
                else if (vector.get(vector.size() - 1).get(1) < arg_y[i][j])
                {
                    vector.add(new ArrayList(List.of(j, arg_y[i][j])));
                }
                else
                {
                    int lastIndex = j;
                    while(vector.size() > 0 && vector.get(vector.size() - 1).get(1) >= arg_y[i][j])
                    {
                        int width =  j - vector.get(vector.size() - 1).get(0);
                        // 높이를 다 처리할수있도록 반영하고싶은데 그러면 가로로가 문제임
                        int min_border =vector.size() > 1 ? Math.max(vector.get(vector.size() - 2).get(1), arg_y[i][j]) : arg_y[i][j];
                        int height = vector.get(vector.size() - 1).get(1) - min_border;
                        if (vector.get(vector.size() - 1).get(1) > arg_y[i][j])
                        {
                            answer += sums(width) * height;
                        }
                        lastIndex = vector.get(vector.size() - 1).get(0);
                        vector.remove(vector.size() - 1);
                    }
                    vector.add(new ArrayList(List.of(lastIndex, arg_y[i][j])));
                }
            }
        }
        return answer;
    }
}