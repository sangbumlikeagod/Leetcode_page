class Solution {
    public int minimumBoxes(int[] apple, int[] capacity) {
        int total = 0;
        for (int app : apple)
        {
            total += app;
        }
        capacity = IntStream.of(capacity)
                    .boxed()
                    .sorted(Comparator.reverseOrder())
                    .mapToInt(Integer::intValue)
                    .toArray();

        for (int i = 0; i < capacity.length; i++)
        {

            total -= capacity[i];
            if (total <= 0)
            {
                return i + 1;
            }
        }
        return -1;
    }
}