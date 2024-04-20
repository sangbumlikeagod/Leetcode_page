# ## 핵심은 *의 특별 취급에 대한 것

# class Solution:
#     def isMatch(self, s: str, p: str):
#         if len(s)==0 or len(p)==0:
#             return True if len(s)==len(p) else False
#         #입력중 하나가 0일때를 생각해 처리
        
#         def pointer(i,j):
#             print(i,j)
#             care_dot = s[i]==p[j] or p[j]=='.' 
#             if i+1==len(s) and j+1==len(p):
#                 return care_dot 
            
#             if j < len(p)-1 and p[j+1]=='*':
#                 print('다음 값이 * 임')
#                 return  pointer(i,j+1) or (i<len(s)-1 and care_dot and pointer(i+1,j))  
            
#             if i<len(s)-1 and j<len(p)-1:
#                 return care_dot and pointer(i+1,j+1)
#             else:
#                 return care_dot
        
#         return pointer(0,0)
            

class Solution:
    def isMatch(self, s: str, p: str):
        if len(s)==0 or len(p)==0:
            return True if len(s)==len(p) else False
        #입력중 하나가 0일때를 생각해 처리
        
        def pointer(i,j):
            print(i,j)
            care_dot = s[i]==p[j] or p[j]=='.' 
            if i==len(s)-1 and j==len(p)-1:
                return care_dot
            
            if p[j]=='*':
                return (p[j-1]==s[i] and i< len(s)-1 and pointer(i+1,j)) or (pointer(i,j+1))
            
            if i<len(s)-1 and j<len(p)-1:
                pass
                
 
 
            
            
            
a = Solution()
s = "aa"
p="a*"

# s ="aa"
# p="a*"
print(a.isMatch(s,p))


# class Solution:
#     def isMatch(self, s: str, p: str):
#         if len(s)==0 or len(p)==0:
#             return True if len(s)==len(p) else False
#         #입력중 하나가 0일때를 생각해 처리
        
#         def pointer(i,j):
#             print(i,j)
#             care_dot = s[i]==p[j] or p[j]=='.' 
#             if i+1==len(s) and j+1==len(p):
#                 return care_dot or ( p[j]=='*' and s[i]==p[j-1] or p[j-1]=='.' )
            
#             if j < len(p)-1 and p[j+1]=='*':
#                 return (i<len(s)-1 and care_dot) and pointer(i+1,j) or  pointer(i,j+1)
#             else:
#                 return (care_dot and i<len(s)-1 and j<len(p)-1 and pointer(i+1,j+1)) or (j<len(p)-1 and pointer(i,j+1))
        
#         return pointer(0,0)
            
            
            