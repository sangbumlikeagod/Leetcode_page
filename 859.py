class Solution:
    def buddyStrings(self, s: str, goal: str):
        i=0
        miss=0
        size=len(s)
        table={}
        table2={}
        
        while i<size:
            if s[i]==goal[i]:
                i+=1
                if s[i] not in table2:
                    table2[s[i]]=1
                else:
                    table2[s[i]]=2
            else:
                if miss>1:
                    return False
                elif miss==1:
                    if goal[i]==table.get(s[i],False):
                        miss+=1
                        i+=1
                    else:
                        return False
                else:
                    table[goal[i]]=s[i]
                    i+=1
                    miss+=1
        if miss==0:
            if 2 in table2.values():
                return True
            
            return False
        
        return True