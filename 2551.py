class Solution:
    def putMarbles(self, weights, k) -> int:
        size = len(weights)
        if size == k:
            return 0
        import heapq as hq
        big = []
        small = []
        
        for i in range(size-1):
            tmp = weights[i] + weights[i+1]
            hq.heappush(small, tmp)
            hq.heappush(big, -tmp)
        
        sum_big = 0
        sum_small = 0
        
        for _ in range(k-1):
            
            sum_big += -hq.heappop(big)
            sum_small += hq.heappop(small)
            print(sum_big, sum_small)
            
        return sum_big - sum_small
    
weights = [1,3,5,1]
k = 2
# weights = [1,4,2,5,2]
# k = 3
ans = Solution()
print(ans.putMarbles(weights=weights,k=k))