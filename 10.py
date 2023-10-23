class Solution:
    def isMatch(self, s: str, p: str):
        if len(s)==0 or len(p)==0:
            return True if len(s)==len(p) else False


        i,j=0,0
        while i<len(s) or j<len(p):
            
            if i==len(s):# 마지막칸 바깥에 갔을때 
                a,b=0,p[i]
            elif j==len(p):
                a,b=s[i],0
            else:
                a,b=s[i],p[j]
            
            
            if b=='.':
                if a==0:
                    if j<len(s)-1 and p[j+1]=='*':
                        return True
                    return False
                if a!=0:         
                    i+=1
                if b!=0:
                    j+=1
                continue
            
            if b=='*':
                if p[j-1]=='.':
                    while i<len(s)-1:
                        if s[i]==s[i+1]: #맞을때만 넘어가니 괜찮
                            i+=1
                        else:break
                    while j<len(p)-1:
                        if p[j+1]==s[i]:
                            j+=1
                        else:break
                else:
                    while i<len(s):
                        if s[i-1]==s[i]:
                            i+=1
                        else:
                            break
                        i-=1
                    while j<len(p)-1:
                        if p[j+1]==s[i-1]:
                            j+=1
                        else:break
                if a!=0:         
                    i+=1
                if b!=0:
                    j+=1
                continue
            
            
            if a==b:
                if a!=0:         
                    i+=1
                if b!=0:
                    j+=1
                continue
            #여기서도 ab ab. 하면 두번째까진 얘가 되다가 3번쨰 .부터 해당됨 
            else: 
                if j<len(s)-1 and p[j+1]=='*':
                    if j<len(s)-2:
                        j+=1
                    j+=1
                    if a!=0:
                        i+=1
                    continue
                else:
                    return False
            
        
        return True if i==len(s) and j==len(p) else False
    
    
    
# class Solution:
#     def isMatch(self, s: str, p: str):
#         if len(s)==0 or len(p)==0:
#             return True if len(s)==len(p) else False

#         i,j=0,0
#         while i<len(s) and j<len(p):
#             if p[j]=='.':
#                 i+=1
#                 j+=1
#                 continue
            
#             if p[j]=='*':
#                 if p[j-1]=='.':
#                     while i<len(s)-1:
#                         if s[i]==s[i+1]: #맞을때만 넘어가니 괜찮
#                             i+=1
#                         else:break
#                     while j<len(p)-1:
#                         if p[j+1]==s[i]:
#                             j+=1
#                         else:break
#                 else:
#                     while i<len(s): #마지막애일떄까지 
#                         if s[i-1]==s[i]:
#                             i+=1
#                         else:
#                             break
#                     i-=1
#                     while j<len(p)-1:
#                         if p[j+1]==s[i-1]:
#                             j+=1
#                         else:break            
#                 i+=1
#                 j+=1
#                 continue
            
            
#             if s[i]==p[j]:
#                 i+=1
#                 j+=1
#                 continue
#             else: return False
            
#         return True if i==len(s) and j==len(p) else False