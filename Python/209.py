class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        i=j = 0
        local_sum = 0
        ans = float('inf')
        while j < len(nums):
            local_sum += nums[j]
            while local_sum > target:
                local_sum -= nums[i]
                ans = min(ans, local_sum)
                i+=1
            j+=1
        
        return 0 if ans == float('inf') else ans
            
        
            
        
        
        
        