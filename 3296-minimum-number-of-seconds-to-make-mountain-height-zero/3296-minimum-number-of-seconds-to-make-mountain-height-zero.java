class Solution {
    public long minNumberOfSeconds(int mountainHeight, int[] workerTimes) {
        int w = workerTimes.length;
        
        long[] workers = new long[w];
        long[] workerCount = new long[w];
        PriorityQueue<long[]> pq= new PriorityQueue<>((x, y) -> (int) (x[0] - y[0]));
        for (int i = 0; i < w; i++)
        {
            pq.add(new long[] {(long) workerTimes[i], (long) i});
        }

        long answer = 0;
        while (mountainHeight > 0)
        {
            long[] next = pq.poll();
            // System.out.println(next[0] + " " + next[1]);
            // 지금까지의 값으로
            workerCount[(int) next[1]]++;
            workers[(int) next[1]] = next[0];
            pq.add(new long[] {
                workers[(int) next[1]] + workerTimes[(int) next[1]] * (workerCount[(int) next[1]] + 1)
                , next[1]
            });
            mountainHeight--;
        }

        for (int i = 0; i < w; i++)
        {
            answer = Math.max(answer, workers[i]);
        }
        return answer;

    }
}