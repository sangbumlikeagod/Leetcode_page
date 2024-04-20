# class Solution:
#     def isPalindrome(self, x: int):
#         if x<0:
#             return False
#         n=0
#         x2=x
#         while x2>=10:
#             x2=x2//10
#             n+=1
#         while x>=10:
#             print(x//10**n,x%10)
#             if x//10**n!=x%10:
#                 print(x//10**n,x%10)
#                 return False
#             x=(x%10**n)//10
#             print(x)
#         return True
  
  
class Solution:
    def isPalindrome(self, x: int):
        if x<0:
            return False
        n=0
        x2=x
        a=0
        while x2>=10:
            x2=x2//10
            n+=1
        while n-a>=1:
            if (x%10**(n+1)-x%10**n)//10**n != (x%10**(a+1)-x%10**a)//10**a:
                return False
            n-=1
            a+=1
        return True  
    
a=Solution()
print(a.isPalindrome(10))
print(a.isPalindrome(121))

