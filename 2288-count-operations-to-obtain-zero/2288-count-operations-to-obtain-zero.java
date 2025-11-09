class Solution {
    public int countOperations(int num1, int num2) {
        int[] numArr = new int[2];
        numArr[0] = num1;
        numArr[1] = num2;
        int answer = 0;
        while (numArr[0] != 0 && numArr[1] != 0)
        {
            if (numArr[0] < numArr[1])
            {
                int tmp = numArr[1];
                numArr[1] = numArr[0];
                numArr[0] = tmp;
            }
            numArr[0] -= numArr[1];
            answer++;
        }
        return answer;
    }
}