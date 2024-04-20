class Solution:
    def threeSum(self, nums):
        nums.sort()
        size=len(nums)
        ans=[]
        print(nums)
        for i in range(size-2):
            while size-2>i>0 and nums[i]==nums[i-1]:
                i+=1
            p,q=i+1,size-1
            while p<q:
                print(i,p,q)
                if nums[i]+nums[p]+nums[q]==0:
                    ans.append([nums[i],nums[p],nums[q]])
                    while  nums[p]==nums[p+1]:
                        p+=1
                    while nums[q]==nums[q-1] :
                        q-=1
                    p+=1
                    q-=1
                elif nums[i]+nums[p]>-nums[q]:
                    while nums[q]==nums[q-1] :
                        q-=1   
                    q-=1
                else:
                    while nums[p]==nums[p+1]:
                        p+=1
                    p+=1


        
        return ans

nums=[-1,0,1,2,-1,-4]
a=Solution()
print(a.threeSum(nums))
