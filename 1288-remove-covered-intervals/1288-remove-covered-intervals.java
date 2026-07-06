class Solution {
    public int removeCoveredIntervals(int[][] intervals) {
        Arrays.sort(intervals, (a, b) -> {
            if (a[0] != b[0])
            {
                return a[0] - b[0];
            }
            else
            {
                return b[1] - a[1];
            }
    });

        int answer = intervals.length;
        List<Integer> monoStack = new ArrayList<>();
        for (int i = 0; i < intervals.length; i++)
        {
            if (
                !monoStack.isEmpty() && 
                monoStack.getLast() >= intervals[i][1])
            {
                answer--;
                continue;
            }
            monoStack.add(intervals[i][1]);
        }
        return answer;
    }
}