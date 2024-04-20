# class Solution:
#     def maxProfit(self, prices, fee):
#         length=len(prices)
#         lst=[]
#         for i in range(length):
#             lst.append([0,0])
#         #(True,False)로?
#         def recur(have,i):
#             if i==length-1:
#                 if have:
#                     lst[i][0]=prices[i]-fee
#                     return lst[i][0]
#                 else:
#                     lst[i][1]=0
#                     return lst[i][1]
#             if have==True and lst[i][0] != 0:
#                 return lst[i][0]
#             elif have==False and lst[i][1] !=0:
#                 return lst[i][1]                
#             if have:
#                 ans1=prices[i]-fee+recur(False,i+1)
#                 ans2=recur(True,i+1)
#                 lst[i][0]=max(ans1,ans2)
#                 return lst[i][0]
#             else:
#                 ans1=recur(True,i+1)-prices[i]
#                 ans2=recur(False,i+1)
#                 lst[i][1]=max(ans1,ans2)
#                 return lst[i][1]
            
#         ans=recur(False,0)
#         print(lst)
#         return ans
    
    
class Solution:
    def maxProfit(self, prices, fee):
        sellorbuy=prices[0]+fee
        max_v=0
        for i in prices:
            if i>sellorbuy:
                max_v+=i - sellorbuy
                sellorbuy=i
            elif i+fee<sellorbuy:
                sellorbuy=i+fee
        



        return max_v
    
prices=[1,4,6,2,8,3,10,14]
fee=3

a=Solution()
print(a.maxProfit(prices,3))
