class Solution:
    def __init__(self):
        pass
    
    def integerReplacement(self, n: int) -> int:
        if n == 3:
            return 2
        if n == 1:
            return 0
        if n % 2:
            if n % 4 == 3:
                return 1 + self.integerReplacement(n + 1)
            else:
                return 1 + self.integerReplacement(n - 1)
                
        else:
            return 1 + self.integerReplacement(n // 2)