class Solution:
    def wiggleMaxLength(self, nums: list[int]) -> int:
        result = 1

        size = len(nums)
        if size <= 2:
            if size == 2 and nums[0] == nums[1]:
                return 1
 
            return size

        wiggle = 0
        i, j = 0, 1
        while j < size:
            print(i, j)
            if not wiggle:
                if nums[j] - nums[i] != 0:
                    wiggle = nums[j] - nums[i]
                    i, j = j, j + 1
                    result += 1
                else:
                    j += 1

            else:
                if (nums[j] - nums[i]) * wiggle < 0:
                    i, j, wiggle = j, j + 1, nums[j] - nums[i]
                    result += 1
                else:
                    j += 1
        return result
        # 3이상의 애들에 대해서 조사 3개가 전부 같을 경우를 생각하지 않아서 이렇게됨


lst = [3,3,3,2,5]
# lst = [1,7,4,9,2,5]
a = Solution()
print(a.wiggleMaxLength(lst))