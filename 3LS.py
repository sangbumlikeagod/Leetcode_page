class Solution:
    def lengthOfLongestSubstring(self, s):
        dicc={}
        length=0
        l=0
        for r in range(len(s)):
            if s[r] not in dicc:
                dicc[s[r]]=r
                length=max(length,r-l+1)
            elif s[r] in dicc and dicc[s[r]]>l: 
                l=dicc[s[r]]+1
                
        return length
                