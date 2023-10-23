class Solution:
    def isMatch(self, s: str, p: str):
        if len(s)==0 or len(p)==0:
            return True if len(s)==len(p) else False

        sdic={}
        pdic={}
        sp=1
        pp=1
        s=list(s)
        p=list(p)
        
        p1=[]
        p2=p[::]
        

        while p2:
            a=p2.pop(0)
            
            if a=='*':
                b=p1.pop(-1)
                pdic[pp]=b
                pp+=1
                while len(p1)>=1 and p1[-1]==b:
                    print('text',b,p1[-1])
                    p1.pop(-1)
                p1.append(pp-1)
                
            else:p1.append(a)    
            print(p1,p2)
            
        while p1 and s:
            a=p1.pop(0)
            b=s.pop(0)
            print('\n',s,p1)
            if a==b or b=='.':
                continue
            else:
                sdic[sp]=b
                while len(s)>=1 and b==s[0]:
                    s.pop(0)
            
         # 빈 리스트 객체는 안에 내용물과 상관없이 TRue , false ,none등의 불형으로 말할수 없다
        if len(p1) or len(s) is True:
            print(p1,s)
            return False
        
        if len(pdic)<len(sdic):
            return False
        else:
            chance=len(pdic)-len(sdic)
            k=0
            for i in range(1,len(sdic)+1):
                print(i+k , i)
                if pdic[i+k]==sdic[i]:
                    continue
                else:
                    
                    while chance>0:
                        chance-=1
                        k+=1
                        if pdic[i+k]==sdic[i]:
                            break
                    if chance==0:
                        return False
                    continue
                        
                        
                        
                    
        
        
                # if i<len(p)-1:
                #     j=i
                #     a=p.pop(j-1)
                #     j-=1
                #     while p[j-1]==a and i<len(p)-1:
                        
                #         p.pop(j-1)
                #         j-=1
        return  True
    
        
        # while s and p is True:
        #     s0=s.pop(-1)
        #     p0=p.pop(-1)
        #     if s0!=p0:
        #         sdic[sp]=s0
        #         sp+=1
s = "aaa"
p="ab*a*c*a"


a=Solution()
print(a.isMatch(s,p))


