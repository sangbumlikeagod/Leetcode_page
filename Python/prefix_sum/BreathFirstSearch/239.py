from collections import deque

class Solution:
    def maxSlidingWindow(self, nums, k):   
        size = len(nums)
        dq = deque()
        if k == size:
            return nums
        ans = []
        left = right = 0
        k2 = k
        while k2 > 0:
                
                
                while dq and dq[-1][0] < nums[right]:
                    dq.pop()
                dq.append((nums[right], right + k - 1))
                right += 1
                k2 -= 1
        else:
                ans.append(dq[0][0])
                left += 1
                pass
        
        print('중간 체크', ans, left, right)
        while right < size:
            
            print(dq)
            if dq[0][1] < right:
                dq.popleft()
            
            while dq and dq[-1][0] < nums[right]:
                    dq.pop()
            print('\t',dq)
            dq.append((nums[right], right + k - 1))
            print('\t\t',dq)
            left += 1
            right += 1
            ans.append(dq[0][0])
        
        return ans
    
nums = [1,3,-1,-3,5,3,6,7]
k = 3
# nums = [1,3,1,2,0,5]
# k = 3
# nums = [7, 2, 4]
# k = 2
a = Solution()
print(a.maxSlidingWindow(nums, k))