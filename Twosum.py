class Solution:


    def __init__(self):
        self.hashmap={}

    def twoSum(self,valueset,target):
        
        for i in range(len(valueset)):
            
            key=max(valueset[i],target-valueset[i])
            
            if  key in self.hashmap:
                if self.hashmap[key][0][1]==valueset[i] and self.hashmap[key][0][1] != target//2:
                    continue
                self.hashmap[key].append([i,valueset[i]])
                return [self.hashmap[key][0][0],self.hashmap[key][1][0]]
            else: self.hashmap[key]=[[i,valueset[i]]]




a=Solution()
print(a.hashF([3,2,4],6))
nums = [2,7,11,15] 
target = 9
print(a.hashF(nums,target))