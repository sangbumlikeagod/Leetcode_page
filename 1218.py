class Solution:
    def longestSubsequence(self, arr, difference) -> int:
        # lst=[True]*size
        # for i in range(size-1):
        #     if lst[i] == True:
        #         lst[i] = False
        #     else:
        #         continue
            
        #     j = i + 1
        #     iter_r = 1 
        #     local_max= 0
        #     while j < size:
        #         if arr[j] - arr[i] == iter_r * difference:
        #             iter_r += 1 
        #             local_max += 1
        #         j += 1
        #     ans = max(ans, local_max)
        # return ans
        
        
        # def recur(index,prev):
            # if index == size:
            #     return 0
            # if prev == -float('inf'):
            #     notake = recur(index+1, prev)
            #     take = 1 + recur(index+1 , arr[index])
            # else:
            #     notake = recur(index+1, prev)
            #     take = 1 + recur(index+1 , arr[index]) if arr[index] - prev == difference else 0
            # return max(notake, take)
        
        # return recur(0,-float('inf'))
                    
        table = {}     
        size=len(arr)
        ans = 0
        for i in arr:
            table[i] = table.get(i - difference,0) + 1
        
        return max(table.values())       