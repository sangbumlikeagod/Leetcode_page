# class Solution:
#     def longestArithSeqLength(self, nums) -> int:
#         ans=1
#         sort_nums=sorted(nums)
#         size=len(nums)
#         def dfs(num,diff):
#             if num==size-1:
#                 return 1
#             i=1
#             while num+i<size and sort_nums[num]+diff>=sort_nums[num+i]:
#                 if sort_nums[num+i]==sort_nums[num]+diff:
#                     return dfs(num+i,diff)+1
#                 i+=1
#             return 1
                
            
#         for i in range(size):
#             inner=1
#             for j in range(i+1,size):
#                 diff=sort_nums[j]-sort_nums[i]
#                 inner=max(inner,dfs(j,diff)+1)
                
#             ans=max(ans,inner)


class Solution:
    def longestArithSeqLength(self, nums) -> int:
        ans=0
        table={}
        size=len(nums)
        # for _ in range(size):
        #     table.append([0]*size)

        for i in range(size):
            for j in range(i+1,size):
                print(i,j)
                if nums[j]-nums[i] not in table:
                    table[nums[j]-nums[i]]=[i]
                else: table[nums[j]-nums[i]].append(i)
        for i in table:
            ans=max(len(table[i]),ans)

        print(table)
        return ans
    
    

class Solution:
    def longestArithSeqLength(self, nums) -> int:
        ans=0
        size=len(nums)
        table=[0]*size
        # for _ in range(size):
        #     table.append([0]*size)

        for i in range(size-1):
            table[i]=nums[i+1]-nums[i]



        print(table)
        return ans

class Solution:
    def longestArithSeqLength(self, sort_nums) -> int:
        ans=1
        table={}
        # sort_nums=sorted(nums)
        size=len(sort_nums)
        def dfs(num,diff):
            if (num,diff) in table:
                return table[(num,diff)]
                
            if num==size-1:
                table[(num,diff)]=1
                return 1
            i=1
            while num+i<size:
                if sort_nums[num+i]==sort_nums[num]+diff:
                    table[(num,diff)]=dfs(num+i,diff)+1
                    return table[(num,diff)]
                i+=1
            table[(num,diff)]=1
            return 1
                
            
        for i in range(size):
            inner=1
            for j in range(i+1,size):
                diff=sort_nums[j]-sort_nums[i]
                inner=max(inner,dfs(j,diff)+1)   
            ans=max(ans,inner)        
        return ans


lst=[9,4,7,2,10]
a=Solution()
print(a.longestArithSeqLength(lst))

n=10
dp = [{} for _ in range(n)]
print(dp)