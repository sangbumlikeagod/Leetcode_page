class Solution {
    public long maxRunTime(int n, int[] batteries) {
        List<Integer> lsts = Arrays.stream(batteries).boxed()
            .sorted(Comparator.reverseOrder())
            .toList();
        int bl = batteries.length;
        long remains = 0;
        for (int i = n; i < bl; i++)
        {
            remains += lsts.get(i);
        }
        // System.out.println(remains + " " + lsts.get(0)  + " " );
        for (int i = n - 1; i > 0; i--)
        {
            long weNeed = (lsts.get(i - 1) - lsts.get(i)) * (n - i);
            if (weNeed <= remains)
            {
                remains -= weNeed;
            }
            else
            {
                return lsts.get(i) + (remains / (n - i));
            }
        }
        // System.out.println(remains + " " + batteries[0]  + "" );
        return lsts.get(0) + (remains / n);
    }
}