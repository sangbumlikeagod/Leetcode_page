class Solution:
    def lengthOfLongestSubstring(self, s):
        lst1=[0]

        for count,char in enumerate(s):
            if len(s)-count>sorted(lst1,reverse=True)[0]:
                lst2=[]
                lst2.append(char)
                print(lst2)
                while count+1<len(s):
                    if s[count+1] in lst2:
                        print(len(lst2))
                        lst1.append(len(lst2)) 
                        break
                    else: 
                        lst2.append(s[count+1])
                        count+=1
            else: 
                a=len(s)-count
                b=sorted(lst1,reverse=True)[0]
                print('현재 {}칸 만큼 남았는데 이미 최대치가 {}이므로 이하부턴 스킵합니다'.format(a,b))
        
        return sorted(lst1,reverse=True)[0]
        
        
        
a=Solution()
s = "abcabcbb"
print(a.lengthOfLongestSubstring(s))

# a='123456789'
# ab=list(a)
# print(sorted(a,reverse=True)[0])
