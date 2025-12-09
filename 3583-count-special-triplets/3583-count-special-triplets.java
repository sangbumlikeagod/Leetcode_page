class Solution {
    int MODULO = (int) 1e9 + 7;
    public int specialTriplets(int[] nums) {
        HashMap<Integer, Integer> maps = new HashMap<>();

        for (int num : nums)
        {
            maps.put(num, maps.getOrDefault(num, 0) + 1);
        }
        
        int answer = 0;
        HashMap<Integer, Integer> ansMaps = new HashMap<>();
        for (int num : nums)
        {
            long left = ansMaps.getOrDefault(num * 2, 0);
            long right = maps.getOrDefault(num * 2, 0);
            right -= num == 0 ? left + 1 : left;
            answer += (int) ((right * left) % MODULO);
            answer %= MODULO;
            ansMaps.put(num, ansMaps.getOrDefault(num, 0) + 1);
        }
        return answer;
    }
}