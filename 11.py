class Solution:
    def generateParenthesis(self, n: int):
        
        lst=[]
        table={}
        
        def recur(idx , paren=None):
            if idx==0:
                if paren in table:
                    return None
                else:
                    table[paren]=True
                    lst.append(paren)
                    return None

            
            if idx==n:
                return recur(idx-1,'()')
            for i in range(n-idx,2*(n-idx)+1):
                print(i)
                recur(idx-1,paren[:i]+'()'+paren[i:])
            
           
        recur(n)    
        
        return lst

a= Solution()
print(a.generateParenthesis(3))