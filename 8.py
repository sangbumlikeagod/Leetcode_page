# class Solution:
#     def myAtoi(self, s: str):
#         switch=False
#         comlist=['0','1','2','3','4','5','6','7','8','9']
        
#         for i in range(len(s)):
#             if s[i]==' ':
#                 continue
#             if s[i]=='-' and switch==False:
#                 switch=True
#             if s[i] in comlist:
#                 j=i
#                 while j<=len(s)-1 and s[j+1] in comlist:
#                     j+=1
#                 result=int(s[i:j]) 
#                 if result<2**31 or result>2**31-1:
#                     return 0
#                 return result if switch is False else -result
                
            
class Solution:
    def myAtoi(self, s: str):
        result = 0
        switch=1
        s=s.lstrip()
        if s[0] == '+' or s[0] == '-':
            switch = -1 if s[0] == '-' else 1
            s=s[1:]
        for i in range(len(s)):    
            if s[i].isdigit():
                j=i
                while j<=len(s)-1 and s[j].isdigit():
                    j+=1

                result=int(s[i:j]) 
                
                
                if result<-2**31:
                    return -2**31
                elif result>2**31-1:
                    return 2**31

                return result if switch is 1 else -result
            else:
                return result
    
a=Solution()
print(a.myAtoi("words and 987"))
print(a.myAtoi('     -42'))