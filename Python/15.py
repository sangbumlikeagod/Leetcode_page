import heapq
class Solution:
    def threeSum(self, nums):
        ans=[]
        size=len(nums)
        table={}
        
        for i in range(1,size):
            if nums[i]*-1 in table:
                for _ in table[nums[i]*-1]:
                    inner=[]
                    heapq.heappush(inner,_[0])
                    heapq.heappush(inner,_[1])
                    heapq.heappush(inner,nums[i])
                    ans.append(inner)
            
            j=i-1
            while j>=0:
                a,b=nums[i],nums[j] 
                if nums[i]>nums[j]:
                    a,b=b,a 
                if a+b not in table:
                    table[a+b]=[(a,b)]
                else: 
                    if (a,b) not in table[a+b]:
                        table[a+b].append((a,b))
                j-=1   
            
        print(table)
        return ans
nums=[-1,0,1,2,-1,-4]
a=Solution()
print(a.threeSum(nums))