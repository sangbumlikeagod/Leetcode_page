class Solution:
    def mirrorDistance(self, n: int) -> int:
        n2 = n
        nr = 0
        while n2:
            nr *= 10
            nr += n2 % 10
            n2 //= 10
        return abs(n - nr)
