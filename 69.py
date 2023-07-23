class Solution:
    def mySqrt(self, x: int) -> int:
        if x == 0 or x == 1:
            return x
        i = 1
        j = x
        while j > i and j - i >1:
            tmp = (i + j)//2
            tmp_2 = tmp ** 2
            if tmp_2 == x:
                return tmp
            elif tmp_2 < x:
                i = tmp
            else:
                j = tmp
        return i