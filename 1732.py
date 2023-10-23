class Solution:
    def largestAltitude(self, gain):
        ans=0
        re=0
        while gain:
            re+=gain.pop(0)
            ans=max(ans,re)
        return ans

b=[1,2,3,4,5,6,7]
a=Solution()
print(a.largestAltitude(b))