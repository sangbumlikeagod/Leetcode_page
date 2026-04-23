class Solution:
    def distance(self, nums: List[int]) -> List[int]:
        dics = {}
        n = len(nums)
        answer = [0] * n
        for idx, num in enumerate(nums):
            lst = dics.get(num, [])

            if len(lst) == 0:
                lst.append([idx, 0]) 
            else:
                lastS = lst[-1]
                answer[idx] += (idx - lastS[0]) * len(lst) + lastS[1]
                newS = [idx, (idx - lastS[0]) * len(lst) + lastS[1]]
                lst.append(newS)
            dics[num] = lst

        rev_dics = {}
        for idx in range(n - 1, -1, -1):
            num =  nums[idx]
            lst = rev_dics.get(num, [])

            if len(lst) == 0:
                lst.append([idx, 0]) 
            else:
                lastS = lst[-1]
                answer[idx] +=  (lastS[0] - idx) * len(lst) + lastS[1]
                newS = [idx, (lastS[0] - idx) * len(lst) + lastS[1]]
                lst.append(newS)
                
            rev_dics[num] = lst

            
        return answer
        
    