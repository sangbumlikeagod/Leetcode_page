class Solution:
    def allPossibleFBT(self, n: int):
        
        def recur(num):
            ans = []
            if num == 0:
                return
            if num == 2:
                return [0,0]
            else:
                           
            
        ans = recur(n-1) + [0]
        return ans[::-1]
    
A = Solution()
print(A.allPossibleFBT(5))
                
            

    