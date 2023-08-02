class Solution:
    def removeKdigits(self, num: str, k: int) -> str:
        pointer = 0
        size = len(num)
        new_lst = []
        while pointer < size:
            count = 1
            
            while pointer < size - 1 and num[pointer] == num[pointer + 1]:
                count += 1
                pointer += 1
            new_lst += [num[pointer], count]
            pointer += 1
        return new_lst


        
        while k > 0:
            
            size2 = sum([i for i in range(len(new_lst)) if i % 2 == 1])
            pointer = 0
            while True:
                if num[pointer + 1] == 0:
                    pointer += 2 
                if num[pointer + 2 + 1] != 0 and num[pointer] > num[pointer + 2]:
                    num[pointer + 1] -= 1
                else:
                    pointer += 2 
                
            k -= 1
        return [ num[i] * num[i + 1] for i in range(0, len(new_lst) // 2, 2)]    
    
a = Solution()
print(a.removeKdigits("94321", 5))