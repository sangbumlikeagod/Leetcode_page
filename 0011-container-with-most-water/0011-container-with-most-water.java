class Solution {

    private int binarySearch(ArrayList<ArrayList<Integer>> stacks, int value)
    {
        int l = 0, r = stacks.size() - 1;
        // value보다 같거나 큰놈 구하는거지 
        while (l < r)
        {
            int m = (l + r) / 2;
            if (stacks.get(m).get(1) < value)
            {
                l = m + 1;
            }        
            else
            {
                r = m;
            }
        }
           
        return stacks.get(l).get(1) >= value ? stacks.get(l).get(0) : -1;
        // return -1;
    }
    public int maxArea(int[] height) {
        ArrayList<ArrayList<Integer>> stacks = new ArrayList<>();
        ArrayList<ArrayList<Integer>> stacks2 = new ArrayList<>();
        int answer = 0;
        for (int i = 0; i < height.length; i++)
        {
            if (!stacks.isEmpty())
            {
                // 얘보다 작거나 같은놈이 없을 수도 있다
                int x = binarySearch(stacks, height[i]);
                // System.out.println(x + " " + i);
                
                // System.out.println(stacks);
                if (x != -1)
                {
                    answer = Math.max(answer, (i - x) * height[i]);
                }
            }
            if (stacks.isEmpty() || stacks.get(stacks.size() - 1).get(1) < height[i])
            {
                stacks.add(new ArrayList<>(Arrays.asList(i, height[i])));
            }
        }

        for (int i = height.length - 1; i >= 0; i--)
        {
            if (!stacks2.isEmpty())
            {
                // 얘보다 작거나 같은놈이 없을 수도 있다
                int x = binarySearch(stacks2, height[i]);
                // System.out.println(x + " " + i);
                if (x != -1)
                {
                    answer = Math.max(answer, (x - i) * height[i]);
                }
            }
            if (stacks2.isEmpty() || stacks2.get(stacks2.size() - 1).get(1) < height[i])
            {
                stacks2.add(new ArrayList<>(Arrays.asList(i, height[i])));
            }
        }
        return answer;
    }
}