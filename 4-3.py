class Solution:
    def findMedianSortedArrays(self, nums1, nums2):
        l=len(nums1)+len(nums2)
        return self.findmed(nums1,nums2,l//2) if l%2 ==1 else (self.findmed(nums1,nums2,l//2)+self.findmed(nums1,nums2,l//2-1))/2
    def findmed(self,nums1,nums2,target):
        print(nums1,nums2)
        if not nums1:
            return nums2[target]
        if not nums2:
            return nums1[target]
        
        na=len(nums1)//2
        nb=len(nums2)//2
        
        ma=nums1[na]
        mb=nums2[nb]
        
        if ma>mb:
            nums1,nums2=nums2,nums1
            na,nb=nb,na
            ma,mb=mb,ma
        
        where_ma=len(nums1)//2+len(nums2)//2
        if where_ma<target:
            return self.findmed(nums1[na+1:],nums2,target-(na+1))
        else:
            return self.findmed(nums1,nums2[:nb],target)

a=Solution()
l1=[1,1,2,3,4,10,25,95]
l2=[3,4,4,5,6,6,6]
print(a.findMedianSortedArrays(l1,l2))