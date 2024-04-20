import math
class Solution:
    def reverse(self, x: int) -> list:
        minInt = (-2) ** 31
        maxInt = (2 ** 31) -1
        output = 0
        while x:
            lastBit = int(math.fmod(x,10))
            x = int(x / 10)

            if (output > maxInt // 10) or (output == maxInt // 10 and lastBit >= maxInt % 10):
                return 0
            if (output < minInt // 10) or (output == minInt // 10 and lastBit <= minInt % 10):
                return 0
            output = (output * 10 ) + lastBit
        return output