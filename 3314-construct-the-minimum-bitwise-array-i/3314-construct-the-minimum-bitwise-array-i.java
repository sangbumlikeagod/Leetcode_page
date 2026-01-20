class Solution {
    public int[] minBitwiseArray(List<Integer> nums) {
        int n = nums.size();

        int[] answer = new int[n];

        for (int i = 0; i < n; i++)
        {
            answer[i] = -1;
            int next = nums.get(i);
                
            int x = (next >> 1);
            boolean found = false;
            for (int s = x; s <= next; s++)
            {
                if ((s | s + 1) == next)
                {
                    answer[i] = s;
                    break;
                }
            }
        }
        return answer;

    }
}