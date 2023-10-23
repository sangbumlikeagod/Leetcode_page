# class Solution:
#     def minCost(self, nums , cost):
#         length=len(nums)
#         nums_cost=sorted((nums[i],cost[i]) for i in range(length))
#         lf=0
#         rg=length-1
        
#         lf_move=nums_cost[lf][1]
#         rg_move=nums_cost[rg][1]
        
#         lf_total=0
#         rg_total=0
#         while lf<rg:
#             print(lf,rg)
#             if lf_move>rg_move:
#                 rg-=1
#                 rg_total+=(nums_cost[rg+1][0]-nums_cost[rg][0])*rg_move
#                 rg_move+=nums_cost[rg][1]
                
#                 print(rg,rg_move,rg_total)
#             else:
#                 lf+=1
#                 lf_total+=(nums_cost[lf][0]-nums_cost[lf-1][0])*lf_move
#                 lf_move+=nums_cost[lf][1]
#                 print(lf,lf_move,lf_total)

#         return lf_total+rg_total
    
class Solution:
    def minCost(self, nums , cost):
        mm=max(nums)
        m=min(nums)
        
        while mm>m:
            mmcost,mcost=0,0
            mid=(mm+m)//2
            print(mm,m)
            for i in range(len(nums)):
                mcost+=abs(mid-nums[i])*cost[i]
                mmcost+=abs(mid+1-nums[i])*cost[i]
            print(mmcost,mcost)
            if mmcost>mcost:
                mm=mid
            else:
                m=mid+1

        ans=0
        for i in range(len(nums)):
            ans+=abs(mm-nums[i])*cost[i]
        return ans
        

            
nums=[1,3,5,2]
cost=[2,3,1,14]

a=Solution()
print(a.minCost(nums,cost))


            
            
        
        
