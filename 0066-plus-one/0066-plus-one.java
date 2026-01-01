class Solution {

    // private boolean addDigit(int[] digits, int index)
    // {
    //     if (index == digits.length - 1)
    //     {

    //     }
    // }
    public int[] plusOne(int[] digits) {
        int n = digits.length;
        int i = n - 1;
        for (; i >= 0; i--)
        {
            if (digits[i] != 9)
            {
                break;
            }
        }
        List<Integer> answer = new ArrayList<>();
        if (i == -1)
        {
            answer.add(1);
        }
        
        for (int j = 0; j <= i; j++)
        {
            answer.add(digits[j]);
        }
        if (i != -1)
        {
            answer.set(i, (answer.get(i) + 1) % 10);
        }
        for (int j = i + 1; j < n; j++)
        {
            answer.add(0);
        }
        return answer.stream().mapToInt(Integer::intValue).toArray();
    }
}