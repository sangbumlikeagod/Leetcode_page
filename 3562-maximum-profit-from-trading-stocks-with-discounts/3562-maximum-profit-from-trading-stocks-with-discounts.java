class DPResult {
    public int[] dpBossBuy;
    public int[] dpBossHold;

    DPResult(int budget) {
        dpBossBuy = new int[budget + 1];
        dpBossHold = new int[budget + 1];

    }
}

class Solution {
    List<Integer>[] adjLists;
    int[] present_glob;
    int[] future_glob;
    Integer bg;
    
    private DPResult DPDFS(int n) {
        // System.out.println("현재 "+ n + "노드");
        DPResult myResult = new DPResult(bg);

        // 내가 샀다고 약속한 값이지 전혀 
        int[] dpMeBuy = new int[bg + 1];


        int[] dpMeHold = new int[bg + 1];
        for (Integer next : adjLists[n])
        {
            DPResult childResult = DPDFS(next);

            // 난 이만큼 썼다라고 광고하는 자리임 
            for (int i = bg; i >= 0; i--)
            {
                // 내가 샀는데
                // 자식이 이만큼 썼다는데, 
                for (int j = bg - i; j >= 0; j--)
                {
                    dpMeBuy[i + j] = Math.max(childResult.dpBossBuy[j] + dpMeBuy[i], dpMeBuy[i + j]);
                    dpMeHold[i + j] = Math.max(childResult.dpBossHold[j] + dpMeHold[i], dpMeHold[i + j]);
                }
            }
        }

        int discounts = present_glob[n - 1] / 2;
        int whole = present_glob[n - 1];
        // 모든 budget에 대한 
        
        for (int i = bg; i >= 0; i--)
        {
            //내가 산건 나중에 여기서 계산할거니까
            myResult.dpBossBuy[i] = dpMeHold[i];
            myResult.dpBossHold[i] = dpMeHold[i];

            if (i + discounts <= bg)
            {
                myResult.dpBossBuy[i + discounts] = Math.max(dpMeHold[i + discounts], dpMeBuy[i] + future_glob[n - 1] - discounts);
            }
            if (i + whole <= bg)
            {
                myResult.dpBossHold[i + whole] = Math.max(dpMeHold[i + whole], dpMeBuy[i] + future_glob[n - 1] - whole);

            }
        }
        // System.out.println(n + " " + Arrays.toString(dpMeBuy));
        // System.out.println(n + " " + Arrays.toString(dpMeHold));
        return myResult;
    }
    public int maxProfit(int n, int[] present, int[] future, int[][] hierarchy, int budget) {
        // 모든 
        bg = budget;
        adjLists = new ArrayList[n + 1];
        present_glob = present;
        future_glob = future;
        for (int i = 0; i <= n; i ++)
        {
            adjLists[i] = new ArrayList<>();
        }
        for (int[] hierar : hierarchy)
        {
            adjLists[hierar[0]].add(hierar[1]);
        }

        DPResult answers = DPDFS(1);
        int answer = 0;
        for (int arg : answers.dpBossHold)
        {
            answer = Math.max(answer, arg);
        }
        return answer;
    }
}