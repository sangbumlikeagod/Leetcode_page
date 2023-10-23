class Solution:
    def generateParenthesis(self, n: int):
        lst=[]
        def recur(l,r,s=''):
            if l==r==0:
                lst.append(s)
                return None
            
            if 0<=l<r:
                print(l,r)
                return recur(l-1,r,s+'(') or recur(l,r-1,s+')')
            elif l==r:
                print(l,r)
                return recur(l-1,r,s+'(')
            
            return None
    
        recur(n,n)
        return lst
    
a=Solution()
print(a.generateParenthesis(3))