# class Solution:
#     def longestCommonPrefix(self, strs):
#         self.lp="" 
#         self.table={}
        
#         if len(strs)<2:
#             return "" if len(strs)==0 else strs[0]
        
#         p,q=strs.pop(0),strs.pop(0)
        
#         if len(p)>len(q):
#             for i,j in enumerate(q):
#                 self.table[j]==i
#             determ(p)
            
#         else:
#             for i,j in enumerate(p):
#                 self.table[j]==i
#             determ(q)

            
#         def determ(str):
#             lp_in=""
#             for i in range(str):
#                 if str[i] in self.table:
#                     k=1
#                     lp_in2=str[i]
#                     while i+k<len(str) and str[i+k] in self.table and self.table[i+k]==self.table[i]+1:
#                         k+=1
#                         lp_in2+=str[i+k]
#                     lp_in= lp_in if max(len(lp_in2),len(lp_in2))==len(lp_in) else lp_in2
#                 else:
#                     continue
#             self.lp=self.lp if min(len(lp_in),len(self.lp))==len(self.lp) else lp_in
#             return
#         for i in strs:
#             determ(i)
#         return self.lp

lp1='aaaa'
lp2='bbb'
print(max(lp1,lp2))


class Solution:
    def longestCommonPrefix(self, strs):
        if len(strs)<2:
            return "" if len(strs)==0 else strs[0]
        
        self.lp="" 

        def determ(p,q):
            #p가 큰문자열로 가정 
            if q>p:
                p,q=q,p
            k=0
            for i in range(len(q)):
                if p[i]==q[i]:
                    k+=1
                else:
                    break
            self.lp=q[0:k]

        determ(strs.pop(0),strs.pop(0))
        for i in strs:
            determ(i,self.lp)
        return self.lp



# class Solution:
#     def longestCommonPrefix(self, strs):
#         self.lp=strs[0] 
#         self.table={}
        
#         def determ(str):
#             lp_in=""
#             for i in range(len(str)):
#                 if str[i] in self.table:
#                     k=1
#                     lp_in2=str[i]
                    
#                     while i+k<len(str) and str[i+k] in self.table and self.table[str[i+k]]==self.table[str[i]]+k:
                        
#                         lp_in2+=str[i+k]
#                         k+=1
#                         print(k,lp_in,lp_in2)
#                     lp_in= lp_in if max(len(lp_in2),len(lp_in))==len(lp_in) else lp_in2
#                 else:
#                     continue

#             print(self.lp,'vs',lp_in)
#             self.lp=self.lp if min(len(lp_in),len(self.lp))==len(self.lp) else lp_in
            
#             return



#         if len(strs)<2:
#             return "" if len(strs)==0 else strs[0]
        
#         p,q=strs.pop(0),strs.pop(0)
#         print(p,q)
#         if len(p)>len(q):
#             for i,j in enumerate(q):
#                 self.table[j]=i
#             print(self.table)
#             determ(p)
            
#         else:
#             for i,j in enumerate(p):
#                 self.table[j]=i
#             print(self.table)
#             determ(q)

            
#         for i in strs:
#             determ(i)
#         return self.lp