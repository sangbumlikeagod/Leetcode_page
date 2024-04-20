class Solution:
    def romanToInt(self, s: str):
        table={}
        table['I'],table['V'],table['X'],table['L'],table['C'],table['D'],table['M']=1,5,10,50,100,500,1000
        ans=0
        for i in range(len(s)):
            
            if i+1!=len(s) and s[i]=='I':
                if s[i+1]=='V':
                    ans+=table['V']-table['I']
                    continue
                elif s[i+1]=='X':
                    ans+=table['X']-table['I']
                    continue
            if i+1!=len(s) and s[i]=='X':
                if s[i+1]=='L':
                    ans+=table['L']-table['X']
                    continue
                elif s[i+1]=='C':
                    ans+=table['C']-table['X']
                    continue
            if i+1!=len(s) and s[i]=='C':
                if s[i+1]=='D':
                    ans+=table['D']-table['C']
                    continue
                elif s[i+1]=='M':
                    ans+=table['M']-table['C']
                    continue
                
            
            ans+=table[s[i]]


        return ans
