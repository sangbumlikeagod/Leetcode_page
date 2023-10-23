class Solution:
    def maxConsecutiveAnswers(self, answerKey: str, k: int) -> int:
        table={
            'T':0,
            'F':0
        }
        ans=0
        size=len(answerKey)
        i,j=0,1
        table[answerKey[i]]+=1
        while j<size:
            if answerKey[j]!=answerKey[j-1]:
                ans = max( j - i , ans)
                table[answerKey[j]]=table.get(answerKey[j])+1
                j+=1
                
            while answerKey[j]==answerKey[j-1]:
                table[answerKey[j]]=table.get(answerKey[j])+1
                j+=1                
                
            while min(table.get('T'),table.get('F')) < k:
                table[answerKey[i]]-=1
                i+=1
        return ans          