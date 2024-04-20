class Solution:
    def __init__(self) -> None:
        self.lst = [1] * 20

    def canIWin(self, maxChoosableInteger: int, desiredTotal: int) -> bool:
        # if maxChoosableInteger == 10 and desiredTotal == 40:
        #     return False

        def recur(desiredTotal):
            print(desiredTotal, self.lst)
            for num in range(maxChoosableInteger - 1 , -1, -1):
                if  self.lst[num] > desiredTotal:
                    return True
                else:
                    break
            for i in range(maxChoosableInteger - 1 , -1 , -1):
                if self.lst[i]:
                    self.lst[i] = 0
                for oppo in range(maxChoosableInteger - 1 , -1, -1):
                    if  self.lst[oppo]:
                        self.lst[oppo] = 0
                        if recur(desiredTotal - i - 2 - oppo) == False:
                            return False
                        
            else:
                return True
        return recur(desiredTotal)

a = Solution()
print(a.canIWin(10, 40))
        
