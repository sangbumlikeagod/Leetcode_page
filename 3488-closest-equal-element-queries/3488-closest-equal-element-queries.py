class Solution:
    def solveQueries(self, nums: List[int], queries: List[int]) -> List[int]:
        n = len(nums)
        maxVal = max(nums)
        arr = [
            [] for i in range(maxVal + 1)
        ]
        answer_before = [1000001] * len(nums)
        answer = [1000001] * len(queries)
        first = [-1] * (maxVal + 1)
        
        for i in range(n):
            arr[nums[i]].append(i)
            if first[nums[i]] == -1:
                first[nums[i]] = i

        for i in range(maxVal + 1):
            arr[i].append(first[i] + n)
            arrLen = len(arr[i]) - 1
            for j in range(1, arrLen + 1):
                answer_before[arr[i][j] % n] = min(answer_before[arr[i][j] % n], arr[i][j] - arr[i][j - 1])
                if j != arrLen:
                    answer_before[arr[i][j] % n] = min(answer_before[arr[i][j] % n], arr[i][j + 1] - arr[i][j])
                else:
                    answer_before[arr[i][0] % n] = min(answer_before[arr[i][0] % n], arr[i][1] -  arr[i][0])
        print(answer_before)
        answer = [
            answer_before[queries[i]] if answer_before[queries[i]] != n else -1
            for i in range(len(queries))
        ]

        return answer