
class Solution:
    def myAtoi(self, s: str) -> int:


        maxInt, minInt = 2**31 - 1 , -2**31
        result, startIdx, sign = 0,0,1
        cleanStr = s.lstrip()
        
        if not cleanStr: return result

        if cleanStr[startIdx] in ("-", "+"):
            sign = -1 if cleanStr[startIdx] == "-" else 1 
            startIdx += 1
        
        for i in range(startIdx, len(cleanStr)):
            char = cleanStr[i]
            if not char.isdigit():
                break
            else:
                # read note at the end, if confusing
                result = (result * 10) + int(char)

        if result * sign > maxInt:
            return maxInt
        elif result * sign <= minInt:
            return minInt
        
        return result * sign
    
    
a="words and 987"
b=Solution()
print(b.myAtoi(a))