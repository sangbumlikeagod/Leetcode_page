lst1=[1,2,3,4,5,6,8,7,8,7,8]
a=lst1[5:]
a.remove(7)
print(lst1)
#리스트 슬라이싱을 하면 객체가 아예 다른 리스트 주소를 받아온다 

# class Solution:
#     def totalCost(self, costs, k, candidates):
#         ans=0
#         size=len(costs)

#         def recur(i,j):
#             low_st=i
#             for i in range(i,j):
#                 if costs[low_st]>costs[i]:
#                     low_st=i
#             return low_st
    
#         for _ in range(k):
#             if 2*k>=size:
#                 ans+=costs[recur(0,size)]
#             else:
#                 left,right=recur(0,candidates),recur(size-candidates,size)
#                 if costs[left]>costs[right]:
#                     ans+=costs[right]
#                     costs.pop(right)
#                 else:
#                     ans+=costs[left]
#                     costs.pop(left)
#             size-=1         
#         return ans
                    
                    
                
                
                


# class Solution:
#     def totalCost(self, costs: List[int], k: int, candidates: int):
#         left=[]
#         right=[]
#         l,r=0,len(costs)-1
#         i=0
#         ans=0
#         while i<k:
#             heapq.heappush(left,costs[l])
#             heapq.heappush(right,costs[r])
#             l+=1
#             r-=1
#             i+=1
        
#         while k>0:
#             if left[0]>right[0]:
#                 ans+=heapq.heappop(right)
#                 r-=1
#                 heapq.heappush(right,costs[r])
#             else:
#                 ans+=heapq.heappop(left)
#                 l+=1
#                 heapq.heappush(left,costs[l])
#             k-=1
#         return ans
            
            
            
        
        
        


class Solution:
    def totalCost(self, costs: List[int], k: int, candidates: int):
        ans=0
        left,right=[],[]
        l,r=0,len(costs)-1
        
        while k>0:
            while l<=r and len(left)<candidates:
                heapq.heappush(left,costs[l])
                l+=1
            while l<r and len(right)<candidates:
                heapq.heappush(right,costs[r])
                r-=1
            
            if left[0]<=right[0]:
                ans+=heapq.heappop(left,0)
            else:
                ans+=heapq.heappop(right,0)                  
            
            k-=1
        return ans
    
    
