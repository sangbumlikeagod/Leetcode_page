class Solution:
    def search(self, nums: List[int], target: int) -> int:
        left = 0
        right = len(nums) - 1

        def recur(left, right):
            if right - left <= 0:
                return left if nums[left] == target else -1
            mid = (left + right) // 2 
            if nums[mid] == target:
                return mid
            elif nums[mid] < target:
                return recur(mid+1, right)
            else:
                return recur(left, mid-1)

            

        return recur(left, right)