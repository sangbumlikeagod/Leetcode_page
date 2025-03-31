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
            
        return sum_big - sum_small
    