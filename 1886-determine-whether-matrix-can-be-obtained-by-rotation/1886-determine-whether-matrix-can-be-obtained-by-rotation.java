class Solution {
    public boolean findRotation(int[][] mat, int[][] target) {
        int n = mat.length;
        boolean r_get = true;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (mat[i][j] != target[i][j])
                {
                    r_get = false;
                    break;
                }
                if (!r_get) break;
            }
        }
        if (r_get) return true;

        r_get = true;
        for (int i = 0, i2 = n - 1; i < n; i++, i2--)
        {
            for (int j = 0, j2 = 0; j < n; j++, j2++)
            {
                if (mat[i][j] != target[j2][i2])
                {
                    r_get = false;
                    break;
                }
                if (!r_get) break;
            }
        }
        if (r_get) return true;

        r_get = true;

        for (int i = 0, i2 = n - 1; i < n; i++, i2--)
        {
            for (int j = 0, j2 = n - 1; j < n; j++, j2--)
            {
                if (mat[i][j] != target[i2][j2])
                {
                    r_get = false;
                    break;
                }
                if (!r_get) break;
            }
        }
        if (r_get) return true;


        r_get = true;
         for (int i = 0, i2 = 0; i < n; i++, i2++)
        {
            for (int j = 0, j2 = n - 1; j < n; j++, j2--)
            {
                if (mat[i][j] != target[j2][i2])
                {
                    r_get = false;
                    break;
                }
                if (!r_get) break;
            }
        }
        if (r_get) return true;
        return false;
    }
}