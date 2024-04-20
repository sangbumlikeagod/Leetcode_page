class Solution:
    def myPow(self, x: float, n: int) -> float:

        i = 1 
        if n % 2 == 1:
            i = x
        # print(n, x)
        if abs(n) <= 1:
            return x ** n
        else:
            return self.myPow( x, n // 2 ) ** 2 * i