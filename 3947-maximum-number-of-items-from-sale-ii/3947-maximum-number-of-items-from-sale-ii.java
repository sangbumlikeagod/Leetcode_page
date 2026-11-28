class Solution {

    private void findNums(int[] divides, int num)
    {
        for (int i = 1; (long) i * i <= (long) num; i++)
        {   
            if (num % i == 0)
            {
                divides[i]++;
                if (num / i != i)
                {
                    divides[num / i]++;
                }
            }
        }
    }

    public int maximumSaleItems(
        int[][] items, 
        int budget
    ) 
    {
        int n = items.length;
        int[] divides = new int[n + 1];

        
        int minV = Integer.MAX_VALUE;
        for (int i = 0; i < n; i++)
        {   
            findNums(divides, items[i][0]);
            minV = Math.min(items[i][1], minV);
        }
        
        List<int[]> sortedLst = new ArrayList<>();

        
        for (int i = 0; i < n; i++)
        {
            if (
                divides[items[i][0]] > 1 &&
                items[i][1] < minV * 2
            )
            {
                sortedLst.add(new int[] {
                    items[i][1], divides[items[i][0]] - 1}
                );
            }
        }
        
        Collections.sort(sortedLst, (a, b) -> Integer.compare(a[0], b[0]));
        int answer = 0;
        
        for (int i = 0; i < sortedLst.size(); i++)
        {
            if (sortedLst.get(i)[0] <= budget)
            {
                // System.out.println(sortedLst.get(i));
                int count = Math.min(budget / sortedLst.get(i)[0], sortedLst.get(i)[1]);
                answer += 2 * count;
                budget -= sortedLst.get(i)[0] * count;
            }
            else
            {
                break;
            }
            // System.out.println(budget);
        }
        if (budget >= minV) 
        {
            answer += (budget / minV);
        }
        
        return answer;
    }
}