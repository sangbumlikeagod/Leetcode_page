class Solution {
    private int batch(StringBuffer corridor, int[] idx)
    {
        int[] batching = {-1, -1};
        int startIdx = idx[0];
        while (
            idx[0] < corridor.length() &&
            (batching[0] == -1 ||
            batching[1] == -1)
        )
        {
            if (corridor.charAt(idx[0]) == 'S')
            {
                if (batching[0] == -1)
                {
                    batching[0] = idx[0];
                }
                else
                {
                    batching[1] = idx[0];
                }
            }
            idx[0]++;
        }
        if (batching[0] == -1 && batching[1] == -1)return 0;
        return batching[1] == -1 ? -1 : batching[0] - startIdx + 1;
    }
    public int numberOfWays(String corridor) {
        ArrayList<Integer> counts = new ArrayList<>(); 
        int[] idx = {0};
        int MODULO = (int) 1e9 + 7;
        StringBuffer corridorMem = new StringBuffer(corridor);
        boolean firstBatch = true;
        boolean atLeastOne = false;
        while (idx[0] < corridor.length())
        {
            int next = batch(corridorMem, idx);
            if (next == -1) return 0;
            if (next == 0)
            {
                continue;
            }
            if (firstBatch)
            {
                atLeastOne = true;
                firstBatch = false;
                continue;
            }
            atLeastOne = true;
            counts.add(next);
        }
        long answer = 1;
        for (int i = 0; i < counts.size(); i++)
        {
            answer *= counts.get(i);
            answer %= MODULO;
        }
        if (!atLeastOne) return 0;
        return (int) answer; 
    }
}