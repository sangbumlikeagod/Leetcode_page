class Solution {
    int MODULO = (int) 1e9 + 7;
    HashSet<Long> hashSet = new HashSet<>();
    public int maximizeSquareArea(int m, int n, int[] hFences, int[] vFences) {
        int h = hFences.length;
        int v = vFences.length;
        long[] prefixSumX = new long[h + 2];
        long[] prefixSumY = new long[v + 2];
        prefixSumX[0] = 1;
        prefixSumX[h + 1] = m;
        prefixSumY[0] = 1;
        prefixSumY[v + 1] = n;

        Arrays.sort(hFences);
        Arrays.sort(vFences);

        
        for (int i = 0; i < h; i++)
        {
            prefixSumX[i + 1] = hFences[i];
        }
        for (int i = 0; i < v; i++)
        {
            prefixSumY[i + 1] = vFences[i];   
        }
        
        long answer = 0;
        for (int i = 1; i <= h + 1; i++)
            {
                for (int j = 0; j < i; j++)
                    {
                        hashSet.add(prefixSumX[i] - prefixSumX[j]);
                    }
            }

        for (int i = 1; i <= v + 1; i++)
            {
                for (int j = 0; j < i; j++)
                    {
                        if (hashSet.contains(prefixSumY[i] - prefixSumY[j]))
                        {
                            answer = Math.max(answer, prefixSumY[i] - prefixSumY[j]);
                        }
                    }
            }

        return answer == 0? -1 : (int) ((answer * answer) % MODULO);
        
    }
}