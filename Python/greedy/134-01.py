class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        max_cost_idx = 0
        for i in range(len(cost)):
            if cost[i] - gas[i] > cost[max_cost_idx] - gas[max_cost_idx]:
                max_cost_idx = i
        
        size = len(gas)
        idx = i + 1
        sum_total = 0
        while True:

            if idx == i:
                return idx + 1 if sum_total + gas[idx] >= cost[idx] else -1
            
            sum_total += gas[idx]
            sum_total -= cost[idx]
            idx += 1
            if idx == size - 1:
                idx = 0