class Solution:
    def longestPalindrome(self, s):
        if len(s)<2:
            return s
        letter=""
        for i in range(len(s)):
            r=len(s)-1
            while i<r:
                print(i)
                
                if s[i] == s[r] and self.ispalin(s[i:r+1]):
                    letter=max(letter,self.ispalin(s[i:r+1]))
                    print(letter)
                    break
                else: 
                    r-=1
        return letter
            

    def ispalin(self,s):
        print('ispalin입니다',s)
        if len(s)<2:
            return s
        if s[1]==s[-2]:
            return None if self.ispalin(s[1:-1]) is None else s
        else: return None
        
# 아무리 많이 s[l+1]==s[r-1]이었다고 할지라도 마지막에 틀리면 그냥 무의미다 그럼 

a=Solution()
s="babad"
print('sex',a.longestPalindrome(s))




class Solution:
    def longestPalindrome(self, s):
        if len(s)<2:
            return s
        letter=""
        for i in range(len(s)):
            r=len(s)-1
            letter=s[i] if len(s[i])>len(letter) else letter
            while i<r:
                std=self.ispalin(s[i:r+1])
                if s[i] == s[r] and std is not None:
                    letter=letter if len(letter)>len(std) else std
                    break
                else:
                    r-=1
        return letter
    
    
    
    def ispalin(self,s):

        if len(s)<2:
            return s
        if s[1]==s[-2]:
            return None if self.ispalin(s[1:-1]) is None else s
        else: return None
    
        
