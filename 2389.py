class Solution:
    def answerQueries(self, nums: List[int], queries: List[int]) -> List[int]:
        nums.sort()
        size = len(nums)
        
        ans = []
        for i in queries:
            last = 0
            prev = 0
            while True:
                local_sum = sum(nums[: last + 1])
                if local_sum == i:
                    ans.append(last)
                    break
                elif local_sum < i:
                    prev, last =last, last + abs(prev - last)//2
                else:
                    prev, last = last, last - abs(prev - last)//2
                if abs(last - prev) == 1:
                    ans.append(last)
                    break
        return ans
