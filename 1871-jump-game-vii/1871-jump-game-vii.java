class Solution {
    public boolean canReach(String s, int minJump, int maxJump) {
        int n = s.length();
        if (s.charAt(n - 1) != '0') return false;
        // int l = 0, r = 0, rm = 0;
        Queue<Integer> q1 = new LinkedList<>();
        Queue<Integer> q2 = new LinkedList<>();
        for (int i = 1; i < n; i++)
        {
            if (s.charAt(i) == '0')
            {
                q2.add(i);
            }
        }
        q1.add(0);
        while (!q1.isEmpty())
        {
            // 제일 작은값인것을 보장
            // System.out.println(next);
            int next = q1.poll();
            if (next == n - 1) return true;
            while (!q2.isEmpty() && q2.peek() < next + minJump)
            {
                q2.poll();
            }
            while (!q2.isEmpty() && q2.peek() <= next + maxJump)
            {
                q1.add(q2.poll());
            }
        }
        return false;
    }
}