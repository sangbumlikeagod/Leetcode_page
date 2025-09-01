class Solution {
    private double err = 1e-5;
    public double maxAverageRatio(int[][] classes, int extraStudents) {
        PriorityQueue<ArrayList<Integer>> q = new PriorityQueue<>((a, b) -> {
            Long as = (long) (a.get(1) - a.get(0)) * b.get(1) * (b.get(1) + 1);
            Long bs = (long) (b.get(1) - b.get(0)) * a.get(1) * (a.get(1) + 1);
            if (as > bs)
            {
                return -1;
            }
            else 
            {
                return 1;
            }
            // return (a.get(1) - a.get(0))  + (b.get(1) - b.get(0));

        });
        int m = classes.length;
        double answer = 0;
        for (int i = 0; i < m; i++)
        {
            q.add(new ArrayList<>(Arrays.asList(classes[i][0], classes[i][1])));
        }

        while(extraStudents > 0)
        {
            // System.out.println(q.peek());
            ArrayList<Integer> next = q.poll();
            next.set(0, next.get(0) + 1);
            next.set(1, next.get(1) + 1);
            // System.out.println("after "+ next);
            q.add(next);
            extraStudents--;
        }

        while(q.isEmpty() == false)
        {
            ArrayList<Integer> next = q.poll();
            // System.out.println(next);
            answer += (double) next.get(0) / next.get(1);
        }
        return answer / m;
    }
}