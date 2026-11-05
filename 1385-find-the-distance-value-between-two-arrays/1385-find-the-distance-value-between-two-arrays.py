class Solution:
    def findTheDistanceValue(self, arr1: list[int], arr2: list[int], d: int) -> int:
        answer = len(arr1)
        for arg1 in arr1:
            for arg2 in arr2:
                if abs(arg1 - arg2) <= d:
                    answer -= 1
                    break
        return answer