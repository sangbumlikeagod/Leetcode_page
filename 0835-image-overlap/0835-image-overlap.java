class Solution {

    private int moveOneShot(
        int dx, 
        int dy,
        int[][] img1,
        int[][] img2  
    ) {
        int n = img1.length;
        int answer = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (
                    0 <= i + dx &&
                    i + dx < n &&
                    0 <= j + dy &&
                    j + dy < n
                )
                {
                    answer += (
                        img2[i + dx][j + dy] & 
                        img1[i][j]
                    );
                }
            }
        }
        return answer;
    }
    public int largestOverlap(int[][] img1, int[][] img2) {
        int answer = 0;
        int n = img1.length;
        for (int i = -n + 1; i < n; i++)
        {
            for (int j = -n + 1; j < n; j++)
            {
                answer = Math.max(
                    answer, 
                    moveOneShot(
                        i, 
                        j, 
                        img1,
                        img2
                    )
                );
            }
        }
        return answer;
    }
}