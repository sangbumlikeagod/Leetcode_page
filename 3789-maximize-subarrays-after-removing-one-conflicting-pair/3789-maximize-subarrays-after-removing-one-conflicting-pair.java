class Solution {
    public long maxSubarrays(int n, int[][] conflictingPairs) {
        long answer = 0;
        // 모든 쌍을 좌표로 바꾸되, 
        // int l = conflictingPairs.length;

        int[] mostFarAway= new int[n + 1];
        int[] secondFarAway= new int[n + 1];
        Arrays.fill(mostFarAway, Integer.MAX_VALUE);
        Arrays.fill(secondFarAway, Integer.MAX_VALUE);

        // pair에 묶여있는 정보를 좌표로 변경한다
        for (int[] pair : conflictingPairs)
        {
            // int[] pair = conflictingPairs[i]
            int a = pair[0], b = pair[1];
            if (b < a)
            {
                int tmp = b;
                b = a;
                a = tmp;
            }
            if (b < mostFarAway[a])
            {
                secondFarAway[a] = mostFarAway[a];
                mostFarAway[a] = b;
            }
            else if (b < secondFarAway[a])
            {
                secondFarAway[a] = b;
            }
        }
        // System.out.println(Arrays.toString(mostFarAway));
        // System.out.println(Arrays.toString(secondFarAway));
        // 모든 좌표가 가장 가까운점, 두번째로 가까운 점을 구할 수 있다
        // 모든 점은 제한이 그대로니 가장 가까운점 
        
        int minimumIndex = n;
        int secondMinimumValue = n + 1;
        long secondMax = 0;
        long [] SecondMinimumIdx = new long [n + 1];
        for (int i = n; i > 0; i--)
        { 
            
            // 모던 지점이 이점에서 시작하는 subarray의 개수를 더한다.

            if (mostFarAway[i] < mostFarAway[minimumIndex])
            {
                secondMinimumValue = Math.min(secondMinimumValue, mostFarAway[minimumIndex]);
                minimumIndex = i;
            }
            else if (mostFarAway[i] < secondMinimumValue)
            {
                secondMinimumValue = mostFarAway[i];
            }
            if (secondFarAway[i] < secondMinimumValue)
            {
                secondMinimumValue = secondFarAway[i];
            }
            answer += Math.min(mostFarAway[minimumIndex], n + 1) - i;
            // System.out.println(Math.min(mostFarAway[minimumIndex], n + 1) - i);
            // 두번째로 가까운 점과 첫번째 점을 알고있음

            // 뭐 하나를 지웠다고 가정하고 있음 -> minimumIndex을 했을때 마주하게되는건 secondMinimumValue 혹은 secondFarAway다

            SecondMinimumIdx[minimumIndex] += (
                Math.min(secondMinimumValue, secondFarAway[i]) - Math.min(mostFarAway[minimumIndex], n + 1)
            );
        }

        for (int i = 1; i <= n; i++)
        {
            secondMax = Math.max(secondMax, SecondMinimumIdx[i]);
        }
        // System.out.println(Arrays.toString(SecondMinimumIdx));
        return answer + secondMax;
    }
}