
class Solution:
    def getAverages(self, nums, k: int) :
        if len(nums)-k<k:
            return [-1]*len(nums)
        lst=[]
        value=0
        for i in range(k,len(nums)-k):
            if i==k:
                for j in range(i-k,i+k+1): # i-k부터 i+k까지 더하려면 +1을 해줘야지
                    value+=nums[j]
            else:
                value+=nums[i+k]  
            lst.append(int(value/(2*k+1)))    
            value-=nums[i-k]
        return [-1]*k+lst+[-1]*k
        
        
            
                    
        