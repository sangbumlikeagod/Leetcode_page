class Solution {
    private static int MODULO = (int)1e9 + 7;
    public int[] productQueries(int n, int[][] queries) {
        int a = 1;
        int aIdx = 0;
        int m = queries.length;
        ArrayList<Integer> lis = new ArrayList<>();
        ArrayList<Integer> prefixLis = new ArrayList<>();
        // ArrayList<ArrayList<Integer>> adjLists = new ArrayList<>(31);
        // for (int i = 0; i < 31; i++)
        //     {
        //         adjLists.add(new ArrayList<>());
        //         for (int j = 0; j < 31; j++)
        //             {
        //                  adjLists[i].add(0);   
        //             }
        //     }
        int[][] adjLists = new int[31][31];
        
        int[] answer = new int[m];
        
        while (a <= n)
            {
                if ((n & a) != 0)
                {
                    lis.add(a);
                }
                a *= 2;
            }

        for (int i = 0; i < lis.size(); i++)
            {
                adjLists[i][i] = lis.get(i);
                long tmp = (long) lis.get(i);
                for (int j = i + 1; j < lis.size(); j++)
                    {
                        tmp *= lis.get(j);
                        tmp %= MODULO;
                        adjLists[i][j] = (int) tmp;
                    }
            }

        for (int i = 0; i < m; i++)
        {
            int[] query = queries[i];
            answer[i] = adjLists[query[0]][query[1]];
        }
        return answer;
        
    }
}