class Solution:
    def findMedianSortedArrays(self, nums1, nums2):
        import heapq
        heap = []
        total = len(nums1) + len(nums2)
        ans = 0
        for i in range(total // 2):
            if not nums2:
                heapq.heappush(heap, -nums1.pop())
            elif not nums1:
                heapq.heappush(heap, -nums2.pop())
            elif nums1[-1] > nums2[-1]:
                heapq.heappush(heap, -nums1.pop())
            else:
                heapq.heappush(heap, -nums2.pop())
                
        if not total % 2:
            if not nums2:
                heapq.heappush(heap, -nums1.pop())
            elif not nums1:
                heapq.heappush(heap, -nums2.pop())
            elif nums1[-1] > nums2[-1]:
                heapq.heappush(heap, -nums1.pop())
            else:
                heapq.heappush(heap, -nums2.pop())
            ans += (-heapq.heappop(heap) + -heapq.heappop(heap)) / 2
        else:
            ans += -heapq.heappop(heap) 
        return ans
        
            
        