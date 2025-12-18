class Solution {
    public long maxProfit(int[] prices, int[] strategy, int k) {
        // 슬라이딩 윈도우라고 가정을하면 앞의 하나가 빠질때 원래 얻을 손해가 -price[i] 였으면
        // 
        // 원래 얻을 이익이 
        // 두개를 원래 팔려했는데[-1] 사는걸로 바꿈[1] 그러면 총이익은 2배가 되지 
        // 반대로 사게되어있는데 [1] 홀드로 바꿈[0] 
        // 맨왼쪽은 홀드였는데 [0]  -> 팔지 홀드일지 살지로 바뀜 

        // 전체값을 구한다

        int n = prices.length;
        long total = 0;
        for (int i = 0; i < n; i++)
        {
            total += prices[i] * strategy[i];
        }
        // 처음 k개만큼 덮어씌운다,

        long answer = total;
        for (int i = 0; i < k / 2; i++)
        {
            total += prices[i] * -strategy[i];
        }
        for (int i = k / 2; i < k; i++)
        {
            total += prices[i] * (1 - strategy[i]);
        }
        
        answer = Math.max(answer, total);

        for (int i = k; i < n; i++)
        {
            total += (1 - strategy[i]) * prices[i];
            total += (strategy[i - k]) * prices[i - k];
            total -= prices[i - k / 2];
            answer = Math.max(answer, total);
        }

        return answer;
    }
}