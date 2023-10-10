class Solution:
    def findMedianSortedArrays(self, nums1, nums2):
        ############타겟 순서 정하기#############
        target=len(nums1)+len(nums2)
        target2=[target//2-1,target//2] if target%2==0 else [target//2]
        print('타겟의 순서 값은',target2)
        #타겟보다 작은값이 1개있어야 한다는 뜻이다 
        r1=0
        r2=0
        ########### 타겟 순서 값이 ########
        p1=len(nums1)//2
        p2=len(nums2)//2
        print('바뀌기전 ',p1,p2)
        while True:
            print('-----------try--------')
            print(p1,p2)
            if nums1[p1]>nums2[p2]:
                if p1+p2+1 in target2:
                    print(p1,p2 ,'얘들이 해당')
                    if len(target2)==1:
                        r2=nums1[p1]
                        break
                    else:
                        print(p1)
                        nums1[p1]=r1
                        target2.remove(p2+p1+1)
                        continue
                else:            
                    if len(nums1)>=len(nums2):
                        p1-=(p2+1) 

                        continue

                    else: pass
                    if len(nums1)<len(nums2):    
                        p2+=(p1+1) 
                        continue
                    else:pass
    
                # p1이 작아졌으니
            else: #p2가 더 커
                if p1+p2+1 in target2:
                    print(p1,p2 ,'얘들이 해당')

                    if len(target2)==1:
                        r2=nums2[p2]
                        break
                    else:
                        nums2[p2]=r1
                        target2.remove(p2+p1+1)
                        continue

                
                
                if len(nums1)>=len(nums2):
                    p1+=(p2+1) 
                    continue

                else: pass
                if len(nums1)<len(nums2):    
                    p2-=(p1+1) 
                    continue
                else: pass
            print('바뀐 후 ',p1,p2,nums1[p1],nums2[p2] )
        # 3이 2보다 1개 크단 뜻 
        print(r1,r2)
        return float(r1+r2)  if r1 ==0 or r2 == 0 else float(r1 + r2)/2
    


a=Solution()

nums1=[1,2,3]
nums2=[3,4,5]
print(a.findMedianSortedArrays(nums1,nums2))