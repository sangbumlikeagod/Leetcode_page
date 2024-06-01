class Solution:
    def canCompleteCircuit(self, gas: list[int], cost: list[int]) -> int:
        left_sum = 0
        right_sum = 0
        idx = 0 
        size = len(gas)
        for i in range(size):
            right_sum += gas[i] - cost[i]
            if right_sum < 0:
                idx = i + 1
                left_sum += right_sum
                right_sum = 0
        return idx if right_sum + left_sum >= 0 else -1