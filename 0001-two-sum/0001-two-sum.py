class Solution:
    def twoSum(self, nums, target):
        table={}
        for i,j in enumerate(nums):

            if target-j in table:
                return [i,table[target-j]]
            if j not in table:

                table[j]=i
