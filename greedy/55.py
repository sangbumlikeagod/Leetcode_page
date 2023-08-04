class Solution:
    def canJump(self, nums) -> bool:

        size = len(nums)
        def recur(idx, jump):
            print(jump, idx)
            if idx + jump >= size:
                return True
            
            if nums[idx] > jump:
                return recur(idx + 1, nums[idx] - 1)
            elif nums[idx] == jump == 0:
                return False
            else:
                return recur(idx + 1, jump - 1)
        return recur(0,0)
    
a = Solution()
print(a.canJump([3,2,1,0,4]))