class Solution:
    def threeSumClosest(self, nums, target):
        size= len(nums)
        min_d=float('inf')
        i=0
        nums.sort()
        while i<size-2:
            if nums[i]>=target+min_d:
                break

            p,q=i+1,size-1   
            while p<q:
                print(i,p,q)
                sum_th=nums[i]+nums[q]+nums[p]
                if sum_th==target:
                    return target
                elif sum_th>target:
                    min_d=min_d if min(abs(min_d-target),abs(sum_th-target))== abs(min_d-target) else sum_th

                    q-=1
                else:
                    min_d=min_d if min(abs(min_d-target),abs(sum_th-target))== abs(min_d-target) else sum_th

                    p+=1
            i+=1  
        return min_d
   
nums=[-4,-1,1,2]    
a=Solution()
target=1
print(a.threeSumClosest(nums,target))