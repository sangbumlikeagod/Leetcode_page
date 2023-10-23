class Solution:
    def reverse(self, x: int):
        if x not in range(-2**31,2**31):
            return 0
        result=0
        switch=False
        if x<0:
            switch=True
            x=-x
        while x>10:
            i=x%10
            result=result*10+i
            x=x//10
            print(result)
        if x != 0:
            result=result*10+x
            print(result)
        return -result if switch is True else result

a=Solution()
a.reverse(10)
