class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        total = 1
        memorization = [0] * (m + n + 1)
        for i in range(1, (m + n + 1)):
            total *= i
            memorization[i] = total
        return total // (memorization[m] * memorization[n])