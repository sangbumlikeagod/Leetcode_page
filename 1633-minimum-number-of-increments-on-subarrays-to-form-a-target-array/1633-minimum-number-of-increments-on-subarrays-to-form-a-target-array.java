class Solution {
    public int minNumberOperations(int[] target) {
        ArrayList<Integer> monotonic = new ArrayList<>();
        int n = target.length;
        int answer = 0;
        for (int i = 0; i < n; i++)
        {
            if (!monotonic.isEmpty() && monotonic.get(monotonic.size() - 1) > target[i])
            {
                answer += monotonic.get(monotonic.size() - 1) - target[i];
                while(!monotonic.isEmpty() && monotonic.get(monotonic.size() - 1) >= target[i])
                {
                    monotonic.remove(monotonic.size() - 1);
                }
            }
            monotonic.add(target[i]);


        }
        return answer + monotonic.get(monotonic.size() - 1);
    }
}