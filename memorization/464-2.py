class Solution:
    def canIWin(self, maxChoosableInteger: int, desiredTotal: int) -> bool:
        lst = (1 << maxChoosableInteger) - 1
        dic = {}
        def winnable(integer, desireTotal):
            # print(bin(integer))
            if len(bin(integer)) - 3 >= desireTotal:
                return True

            # for i in range(maxChoosableInteger, -1, -1):
            #     if integer & 1 << i :
            #         if i + 1 >= desireTotal:
            #             return True
            #         break
            if integer in dic:
                return dic[integer]

            for j in range(len(bin(integer)) - 3, -1, -1):
                if integer & 1 << j:
                    if not winnable(integer - (1 << j), desireTotal - j - 1):
                        dic[integer] = True
                        return True
            
            dic[integer] = False
            # print(dic)
            return False
        if sum(range(maxChoosableInteger + 1)) < desiredTotal:
            return False
       
        return winnable(lst, desiredTotal)


print(len(bin(7)) - 2)

for i in range(len(bin(7)) - 2):
    print(1 << i)