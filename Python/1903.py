class Solution:
    def largestOddNumber(self, num: str) -> str:
        lenOfNum = len(num) - 1
        while lenOfNum >= 0:
            if int(num[lenOfNum]) % 2:
                return num[:lenOfNum + 1]
            lenOfNum -= 1
        return ''
        