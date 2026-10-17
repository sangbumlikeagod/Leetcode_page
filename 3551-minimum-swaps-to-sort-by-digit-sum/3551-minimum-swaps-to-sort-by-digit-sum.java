class Solution {
    private static Integer idx = 0;
    private static int[] digitSum = new int[1];
    private static HashMap<Integer, Integer> hashMap = new HashMap<>();

    private void getDigitSum(Integer arg) {
        Integer ret = 0;
        int idx = hashMap.get(arg);
        while (arg > 0)
        {   
            ret += arg % 10;
            arg /= 10;
        }
        digitSum[idx] = ret;  
    }
    private int findCirculation(List<Integer> arr) {
        int n = arr.size();
        int[] visited = new int[n];
        int answer = 0;
        for (int i = 0; i < n; i++)
        {
            if (visited[i] != 0) continue;
            visited[i] = 1;
            int start = arr.get(i);
            int chain = 0;
            int originalPosition = hashMap.get(start);
            while (i != originalPosition)
            {
                // 정렬된 현재에 누가 있냐
                visited[originalPosition] = 1;
                int next = arr.get(originalPosition);
                originalPosition = hashMap.get(next);
                chain++;
            }
            answer += chain;
        }
        return answer;
    }
    public int minSwaps(int[] nums) {
        hashMap.clear();
        idx = 0;
        digitSum = new int[nums.length];

        List<Integer> numsList = Arrays.stream(nums)
            .boxed()
            .map((Integer a) -> {
                hashMap.put(a, idx++);
                getDigitSum(a);
                return a;
            })
            .sorted((a, b) -> {
                if (digitSum[hashMap.get(a)] == digitSum[hashMap.get(b)])
                {
                    return a - b;
                }
                else
                {
                    return digitSum[hashMap.get(a)] - digitSum[hashMap.get(b)];
                }
            }).toList();
        return findCirculation(numsList);

    }
}