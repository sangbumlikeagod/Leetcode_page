class Solution:
    def climbStairs(self, n: int):

        
        def recur(n,k=0):
            
            if n==2:
                return 2
            if n<2:
                return 1
            



        return recur(n)
    
    # def climbStairs2(self, n: int):
    #     target=n
    #     table={}
    #     def recur(n,n1,n2):
    #         if n==0:
    #             return n2+n1
    #         return recur(n-1,n2,n2+n1)

    #     return recur(n-3,1,2)
    
a=Solution()
print(a.climbStairs(40))
