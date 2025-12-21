class Solution {
    public int minDeletionSize(String[] strs) {
        HashSet<Integer> answer = new HashSet<>();
        int n = strs.length;
        int sL = strs[0].length();

        int[][] runNexts = new int[sL + 1][n];
        // 처음이니 전부 돌아야 한다고 쓰고 
        for (int i = 1; i < n; i++) {
            runNexts[0][i] = 1;
        }
        // System.out.println(Arrays.toString(runNexts[0]));

        int[] runNext = runNexts[0];

        for (int i = 0; i < sL; i++)
        {
            char last = strs[0].charAt(i);
            boolean deleted = false;
            boolean needCheck = false;
            // 0번은 안세도 되니까 뺴고 
            // runNext[j - 1]이 직렬화 되도록 설정하는것
            for (int j = 1; j < n; j++)
            {
                // 나와 이전놈의 관계라 이미 정리됐다면 할필요 없다 
                if (runNext[j] == 0) 
                {
                    last = strs[j].charAt(i);
                    continue;
                }

                if (last > strs[j].charAt(i))
                {
                    // System.out.println(i + "  " +j);
                    answer.add(i);
                    deleted = true;
                    // 만약 지울 경우가 생기면 이전값으로 해줘야한다

                    break;
                }
                else if (last == strs[j].charAt(i))
                {
                    runNexts[i + 1][j] = 1;
                    needCheck = true;
                }
                else if (last < strs[j].charAt(i))
                {
                    runNexts[i + 1][j] = 0;
                }

                last = strs[j].charAt(i);
            }

            // 예상 값은 처음에서 전부다 0
            runNext = deleted ? runNext : runNexts[i + 1];
            // System.out.println(i + " " + deleted + " " + needCheck + " " + Arrays.toString(runNext));


            if (!deleted && !needCheck)
            {
                break;
            }

        }

        return answer.size();
    }
}