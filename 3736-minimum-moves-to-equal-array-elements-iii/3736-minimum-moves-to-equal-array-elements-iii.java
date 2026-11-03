class Solution {
    public static Integer maxs = 0;
    public int minMoves(int[] nums) {
        maxs = 0;

        int n = nums.length;
        Integer sums = Arrays.stream(nums).boxed().map(
            (a) -> {
                maxs = Math.max(maxs, a);
                return a;
            }
        ).reduce(Integer::sum).get();

        return n * maxs - sums;
    }
}