class Solution:
    def convert(self, s: str, numRows: int):
        chainkey=1
        exchainkey=0
        result=""
        hash={}
        
        for i,j in enumerate(list(s)):
            
            if chainkey in hash:
                hash[chainkey].append(j)
            else:
                hash[chainkey]=[j]
                
            if chainkey<exchainkey:
                if chainkey>1:
                    exchainkey=chainkey
                    chainkey-=1
                else:
                    exchainkey=chainkey
                    chainkey+=1
            else:
                if chainkey<numRows:
                    exchainkey=chainkey
                    chainkey+=1
                else:
                    exchainkey=chainkey
                    chainkey-=1
        for i in range(1,numRows+1):
            result+=''.join(hash[i])
        return result
help(list)