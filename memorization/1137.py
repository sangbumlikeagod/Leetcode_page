class Solution:
    def __init__(self) -> None:
        self.dic = {0 : 0,
               1 : 1,
               2 : 1}
    def tribonacci(self, n: int) -> int:
        if n in self.dic:
            pass
        else:
            self.dic[n] = self.tribonacci(n - 1) + self.tribonacci(n - 2) + self.tribonacci(n - 3)
        return self.dic[n]  

        
a = Solution()
print(a.tribonacci(25))