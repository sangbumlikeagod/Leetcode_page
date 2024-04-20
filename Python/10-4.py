
class Solution:
    def isMatch(self, s: str, p: str):
        if len(s)==0 or len(p)==0:
            return True if len(s)==len(p) else False
        
        branch={}
        
        def recur(i,j):
            
            if branch[(i,j)]:
                return branch[(i,j)]
            
            if i==len(s)-1:
                return j==len(p)-1
            
            dot_care = i<len(s) and  (s[i]==p[j] or p[j]=='.')
            
            if j+1<len(s) and p[j+1]=='*':
                ans=recur(i,j+2) or (dot_care and recur(i+1,j))
            else:
                ans=(dot_care and recur(i+1,j+1)) or (dot_care and recur(i+1,j))
                
            branch[(i,j)]=ans
            
            return ans
            
        return recur(0,0)
