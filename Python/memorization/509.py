class Solution:
    def __init__(self):
        self.dic = {1 : 1,
                0 : 0}

    def fib(self, n: int) -> int:
        if n <= 0:
            return 0
        if self.dic.get(n, 0):
            return self.dic[n]
        else:
            self.dic[n] = self.fib(n - 1) + self.fib(n - 2)
            return self.dic[n]

        