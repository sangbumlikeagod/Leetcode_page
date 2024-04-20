# class Solution:
#     def isMatch(self, s: str, p: str):
#         if len(s)==0 or len(p)==0:
#             return True if len(s)==len(p) else False
#         i,j=0,0
#         while True:
#             a,b=0,0
#             if i>=len(s) and j>=len(p):
#                 break
        
#             if i==len(s):
#                 a=0
#                 b=p[j]
#             if j==len(s):
#                 a=s[i]
#                 b=0
                
#             if b=='.' and a != 0:
#                 i+=1
#                 j+=1
#                 continue
            
#             if b=='*':
#                 k=0
#                 if p[j-1]=='.':
#                     while i<len(s):
                        
#                         if s[i+1]==s[i]:
#                             i+=1
#                             k+=1
#                         else:
#                             break
#                     while k>0 and j<len(s):
#                         if p[j+1]==s[i]:
#                             i+=1
#                             k-=1
#                         else:
#                             break
#                 else:
#                     if s[i] == s[i-1]:
#                         while i<len(s):
#                             if s[i+1]==s[i]:
#                                 k+=1
#                                 i+=1
#                             else:
#                                 break
#                         while k>0 and j<len(s):
#                             if p[j+1]==s[i]:
#                                 i+=1
#                                 k-=1
#                             else:
#                                 break
#                     else:
#                         j+=1
#                         continue
#             if s[i]==p[j]:
#                 i+=1
#                 j+=1
#             else:
#                 if j<len(s) and p[j+1]=='*':
#                     j+=2
#                     continue
#                 else:
#                     return False
#         return True



class Solution:
    def isMatch(self, s: str, p: str):
        if len(s)==0 or len(p)==0:
            return True if len(s)==len(p) else False
        i,j=0,0
        while True:
            
            a,b=0,0
            
            if i>=len(s) and j>=len(p):
                break
            
            if i>=len(s):
                a=0
                b=p[j]
            elif j>=len(p):
                a=s[i]
                b=0
            else:
                a,b=s[i],p[j]
                
            print(a,b)

            if b=='.' and a != 0:
                i+=1
                j+=1
                continue
            
            if b=='*':
                k=0
                if p[j-1]=='.':
                    print('분기점1')
                    while True: #마지막 요소까지 허용함 그럼 i가 
                        if not i < len(s)-1:

                            break
                        if s[i+1]==s[i]:
                            i+=1
                            k+=1
                        else:
                            break
                    while k>=0 and j<len(p)-1: #딱 그 자리까지만 가는거였지 얘네는
                        if p[j+1]==a:
                            i+=1
                            k-=1
                        else:
                            break
                        
                    i+=1
                    j+=1
                    continue
                else:
                    print('분기점2')
                    if a == s[i-1]:
                        while True:
                            if i>=len(s)-1:
                                break
                            if s[i+1]==s[i]:
                                
                                k+=1
                                i+=1

                            else:
                                break
                        while k>=0 and j<len(p)-1:
                            if p[j+1]==a:
                                j+=1
                                k-=1
                            else:
                                break
                        i+=1
                        j+=1
                        print(i,j)
                        continue
                    else:
                        print('분기점3')
                        j+=1  #1개라는 뜻
                        print('적용됨')
                        continue
            
                
            if a==b:
                print('s4')
                i+=1
                j+=1
                continue
            else:
                print('s5')
                if j<len(p)-1 and p[j+1]=='*':
                    j+=2
                    continue
                else:
                    return False
        return True
s='aaa'
p='a*a'

a=Solution()
print(a.isMatch(s,p))