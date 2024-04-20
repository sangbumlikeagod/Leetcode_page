class Solution:
    def maxProfit(self, prices):
        ans=0
        for num in range(len(prices)-1):
            if prices[num]>prices[num+1]:
                ans+=prices[num+1]-prices[num]
            else:
                pass
        return ans