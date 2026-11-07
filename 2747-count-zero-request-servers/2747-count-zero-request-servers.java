class Solution {
    public int[] countServers(int n, int[][] logs, int x, int[] queries) {

        HashMap<Integer, Integer> hmap = new HashMap<>();

        int[] answer = new int[queries.length];
        Arrays.sort(logs, (a, b) -> a[1] - b[1]);

        int maxLoggedLength = logs[logs.length - 1][1] + x + 1;
        int[] logClusters = new int[maxLoggedLength]; 
        int l = -1, r = 0;
        

        for (int rtime = 0; rtime < maxLoggedLength; rtime++)
        {
            // r시간보다 작아 
            while (r < logs.length && logs[r][1] <= rtime)
            {
                hmap.put(
                    logs[r][0], 
                    hmap.getOrDefault(logs[r][0], 0) + 1
                );
                r++;
            }
            // 반대로 반드시 포함 될 때까지 
            while (
                l < logs.length &&
                logs[l + 1][1] < rtime - x
            )
            {
                if (logs[l + 1][1] > rtime)
                {
                    break;
                }
                hmap.put(
                    logs[l + 1][0], 
                    hmap.get(logs[l + 1][0]) - 1
                );
                if (hmap.get(logs[l + 1][0]) == 0)
                {
                    hmap.remove(logs[l + 1][0]);
                }
                l++;
            }
            logClusters[rtime] = hmap.size();
            // System.out.println(l + " "+ r);
        }


        // System.out.println(
        //     Arrays.toString(logClusters)
        // );
        for (int i = 0; i < queries.length; i++)
        {
            if (queries[i] >= maxLoggedLength)
            {
                answer[i] = n;
            }
            else
            {
                answer[i] = n - logClusters[queries[i]];
            }
        }
        return answer;
    }
}