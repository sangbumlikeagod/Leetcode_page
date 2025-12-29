class Solution {
    private TreeMap<Integer, List<Integer>> maps = new TreeMap<>();
    private int[][][] heightWidthAlpha = new int[6][6][6];
    private int n;
    private List<Integer> getCombination(int A, int B)
    {
        int x = (A ) * 6 + (B);
        return maps.getOrDefault(x, new ArrayList<>());
    }

    private void setCombination(int A, int B, int C)
    {
        int x = (A) * 6 + (B);
        List<Integer> lst = maps.getOrDefault(x, new ArrayList<>());
        lst.add(C);
        maps.put(x, lst);
    }

    private void initialize(List<String> allowed, String bottom)
    {
        for (String str : allowed)
        {
            setCombination(str.charAt(0) - 'A', str.charAt(1) - 'A', str.charAt(2) - 'A');
        }
        for (int i = 0; i < bottom.length(); i++)
        {
            heightWidthAlpha[0][i][bottom.charAt(i) - 'A'] = 1;
        }
    }

    private boolean backTracking(int layer, int slot, int[][] widthAlpha)
    {
        // slot은 n - layer 이면 다음층으로 넘어간다

        if (layer == n - 1) return true;
        if (slot == n - layer - 1) 
        {
            return backTracking(layer + 1, 0, heightWidthAlpha[layer + 1]);
        }
        // System.out.println(layer + " " + slot);
        for (int k = 0; k < 6; k++)
        {
            if (widthAlpha[slot][k] == 0) continue;
            for (int p = 0; p < 6; p++)
            {
                if (widthAlpha[slot + 1][p] == 0) continue;
                List<Integer> lst = getCombination(k, p);
                if (lst.isEmpty()) continue;

                // System.out.println(layer + " " + slot + " " + k + "     " + p + " " + lst);

                for (Integer arg : lst)
                {
                    heightWidthAlpha[layer + 1][slot][arg] = 1;
                    if (backTracking(layer, slot + 1, widthAlpha))
                    {
                        return true;
                    }
                    heightWidthAlpha[layer + 1][slot][arg] = 0;
                }
            }
            return false;
        }

        return false;
    }

    public boolean pyramidTransition(String bottom, List<String> allowed) {
        initialize(allowed, bottom);
        n = bottom.length();
        return backTracking(0, 0, heightWidthAlpha[0]);
        // for (int i = 0; i < bottom.length(); i++)
        // {
        //     for (int j = 0; j < bottom.length() - i - 1; j ++)
        //     {
        //         boolean possibleOnce = false;
        //         System.out.println(i + " " + j + " " + Arrays.toString(heightWidthAlpha[i][j]));
        //         for (int k = 0; k < 6; k++)
        //         {
        //             if (heightWidthAlpha[i][j][k] == 0) continue;
        //             for (int p = 0; p < 6; p++)
        //             {
        //                 if (heightWidthAlpha[i][j + 1][p] == 0) continue;
        //                 List<Integer> lst = getCombination(k, p);
        //                 // System.out.println(k + " " + p + " " + lst);
        //                 if (lst.isEmpty()) continue;

        //                 for (Integer arg : lst)
        //                 {
        //                     heightWidthAlpha[i + 1][j][arg] = 1;
        //                     possibleOnce = true;
        //                 }
        //             }
        //         }
        //         if (possibleOnce == false) return false;
        //     }
        // }
        // return true;

    }
}