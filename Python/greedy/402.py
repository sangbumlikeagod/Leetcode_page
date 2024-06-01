class Solution:
    def removeKdigits(self, num: str, k: int) -> str:
        pointer = 0
        size = len(num)
        new_lst = []
        new_llst = []
        while pointer < size:
            count = 1
            while pointer < size - 1 and num[pointer] == num[pointer + 1]:
                count += 1
                pointer += 1
            new_lst += [num[pointer]]
            new_llst += [count]
            pointer += 1
        
        while new_lst and k > 0:
            size2 = len(new_lst)
            pointer = 0
            if new_lst[pointer] == '0':
                new_lst.pop(pointer)
                new_llst.pop(pointer)
                continue
            while pointer < size2:
                if pointer == size2 - 1:
                    new_llst[pointer] -= 1
                    if new_llst[pointer] == 0:
                        new_lst.pop(pointer)
                        new_llst.pop(pointer)
                    break
                elif new_lst[pointer] > new_lst[pointer + 1]:
                    new_llst[pointer] -= 1

                    if new_llst[pointer] == 0:
                        new_lst.pop(pointer)
                        new_llst.pop(pointer)                    
                    break
                else: pointer += 1

            k -= 1

        if new_lst and new_lst[0] == '0':

            new_lst.pop(0)
            new_llst.pop(0)
            
        ret_string = ''.join([new_lst[i] * new_llst[i] for i in range(len(new_lst))])
        return ret_string if ret_string else '0'



a = Solution()
print(a.removeKdigits("10033359", 5))
print(a.removeKdigits("133359", 9))
print(a.removeKdigits("1432219", 3))