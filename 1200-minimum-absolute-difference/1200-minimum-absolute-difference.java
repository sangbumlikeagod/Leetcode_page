class Solution {
    public List<List<Integer>> minimumAbsDifference(int[] arr) {
        int n = arr.length;
        Arrays.sort(arr);
        List<List<Integer>> answer = new ArrayList<>();
        int x = Integer.MAX_VALUE;

        for (int i = 0; i < n - 1; i++)
        {
            x = Math.min(x, arr[i + 1] - arr[i]);   
        }

        for (int i = 0; i < n - 1; i ++)
        {
            if (arr[i + 1] - arr[i] == x)
            {
                answer.add(List.of(arr[i], arr[i + 1]));
            }    
        }
        return answer;
    }
}