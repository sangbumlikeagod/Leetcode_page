class Solution:
    def missingNumber(self, nums: List[int]) -> int:
    
        nums.sort()
        i = 0
        j = len(nums)

        while j > i + 1:
            tmp = (i + j)//2
            if tmp == nums[tmp]:
                i = tmp
            else:
                j = tmp






        return j if i in nums[i:j+1] else i
