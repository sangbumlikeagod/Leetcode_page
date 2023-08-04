class Solution:
    def searchInsert(self, nums, target: int) -> int:
        l = len(nums) - 1
        s = 0

        if target < nums[s]:
            return 0
        while s <= l:
            mid = (l + s) // 2
            if nums[mid] == target:
                return mid
            elif nums[mid] < target:
                s = mid + 1
                continue
            else:
                l = mid - 1
        return s 
    
a = Solution()
nums = [1,3,5,6]
target = 7
print(a.searchInsert(nums, target))