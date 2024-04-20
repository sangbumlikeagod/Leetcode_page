class Solution:
    def findMedianSortedArrays(self, nums1, nums2):
        i=0
        l1=0
        l2=0
        a=(len(nums1)+len(nums2))
        while float(i)<=a*0.5:
            if len(nums1) == 0:
                l2 = l1
                l1 = nums2.pop(0)
                i+=1
                print(l1,l2,i)
                continue
            else:
                pass

            if len(nums2) == 0:
                l2 = l1
                l1 = nums1.pop(0)
                i+=1
                print(l1,l2,i)
                continue
            else:
                pass
            l2=l1
            l1=nums2.pop(0) if nums2[0]<=nums1[0] else nums1.pop(0)
            i+=1
            print(l1,l2,i)
        
        return float((l1+l2)/2) if a%2==0 else float(l1)
    
    
p=Solution()
nums1=[1,2]
nums2=[3,4]
print(p.findMedianSortedArrays(nums1,nums2))


#### 1차 결과 풀이방식 #### 
#class Solution:
#     def findMedianSortedArrays(self, nums1, nums2):
#         i=0
#         l1=0
#         l2=0
#         a=(len(nums1)+len(nums2))
#         while float(i)<=a*0.5:
#             if len(nums1) == 0:
#                 l2 = l1
#                 l1 = nums2.pop(0)
#                 i+=1

#                 continue
#             else:
#                 pass

#             if len(nums2) == 0:
#                 l2 = l1
#                 l1 = nums1.pop(0)
#                 i+=1

#                 continue
#             else:
#                 pass
#             l2=l1
#             l1=nums2.pop(0) if nums2[0]<=nums1[0] else nums1.pop(0)
#             i+=1

        
#         return float((l1+l2)/2) if a%2==0 else float(l1)
    