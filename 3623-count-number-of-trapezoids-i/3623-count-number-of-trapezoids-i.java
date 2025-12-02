class Solution {
    private Integer MODULO = (int) 1e9 + 7;
    public int countTrapezoids(int[][] points) {
        HashMap<Integer, Integer> maps = new HashMap<>(); 

        for (int[] point : points)
        {
            Integer cnt = maps.get(point[1]);
            if (cnt == null) cnt = 0;
            maps.put(point[1], cnt + 1);
        }
        long sums = 0;
        for (Integer key : maps.keySet())
        {
            if (maps.get(key) > 1)
            {
                sums += (
                    ((long) maps.get(key) * (maps.get(key) - 1)) / 2
                ) % MODULO;
                sums %= MODULO;
            }
        }

        long answer = 0;
        for (Integer key : maps.keySet())
        {
            if (maps.get(key) > 1)
            {
                long mine = (((long) maps.get(key) * (maps.get(key) - 1)) / 2) % MODULO;
                answer += (mine * ((sums - mine) % MODULO));
                answer %= MODULO;
                sums -= mine;
            }
        }
        return (int) answer;


    }
}