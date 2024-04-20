class Solution:
    def longestPalindrome(self, s):
        letter=""
        for i in range(len(s)):
            if i+1<len(s) and i-1>=0:
            
                if  s[i+1]==s[i]==s[i-1]:
                    pa=self.ispalin(i,s)
                    pb=self.ispalin(i,i+1,s)
                    if len(pb)>len(pa):
                        pa=pb
                    
                elif s[i+1]==s[i] and s[i]!=s[i-1]:   
                    pa=self.ispalin(i,i+1,s)
                elif s[i]!=s[i+1]:
                    pa=self.ispalin(i,i,s)
                    
            if i+1>len(s) and i-1<0:
                pa=s[i]
            elif i+1>len(s):
                pa= s[i-1:i+1]if s[i-1]==s[i] else s[i]
            elif i-1<0:
                pa= s[i:i+2]if s[i+1]==s[i] else s[i]

                
            letter=letter if len(letter)>len(pa) else pa

        
        return letter
    def ispalin(self,i1,i2,s):
            if i1==i2:
                if i1-1<=0 or i2+1>=len(s):
                    return s[i1]
            else:
                if i1<=0 or i2>=len(s)-1:
                    return s[i1:i2+1]
            return self.ispalin(i1-1,i2+1,s) if s[i1-1]==s[i2+1] else s[i1:i2+1]
        
s='bb'
a=Solution()
print(a.longestPalindrome(s))
