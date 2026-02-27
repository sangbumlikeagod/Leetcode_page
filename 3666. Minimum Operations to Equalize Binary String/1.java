class Solution {
    
    public int minOperations(String s, int k) {
        int n = s.length();


        int countOne = 0;
        int countZero = 0;
        for (char c : s.toCharArray())
        {
            if (c == '1')
            {
                countOne++;
            }
            else
            {
                countZero++;
            }
        }


        if (k == n)
        {
            if (countZero == n)
            {
                return 1;
            }
            else if (countOne == n)
            {
                return 0;
            }
            return -1; 
        }
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[0] - b[0]);
        pq.add(new int[] {0, countZero});


        int visited[] = new int[n + 1];
        visited[countZero] = 1;
        TreeSet<Integer> evenTS = new TreeSet<>();
        TreeSet<Integer> oddTS = new TreeSet<>();

        for (int i = 0; i <= n ; i++)
        {
            if (i != countZero)
            {
                if (i % 2 != 0)
                {
                    oddTS.add(i);
                }
                else
                {
                    evenTS.add(i);

                }
            }
        }

        while (!pq.isEmpty())
        {
            int[] next = pq.poll();
            // 0의 개수
            if (next[1] == 0)
            {
                return next[0];
            }

            int minPickZero =  k - Math.min(n - next[1], k);
            int maxPickZero = Math.min(
                next[1], k
            );

            int nextValue = next[1] + k - 2 * maxPickZero;
            TreeSet<Integer> myNextTreeSet = nextValue % 2 == 1 ? oddTS: evenTS; 
            nextValue--;
            while (nextValue <= next[1] + k - 2 * minPickZero)
            {
                Integer nnext = myNextTreeSet.higher(nextValue);
                if (nnext == null || nnext > next[1] + k - 2 * minPickZero) break;
                myNextTreeSet.remove(nnext);
                pq.add(new int[] {next[0] + 1, nnext});
                nextValue = nnext;
            }

        }
        return -1;
    }
}
