class Solution:
    def findTheDifference(self, s: str, t: str) -> str:
        dic = {}
        for i in t:
            dic[i] = dic.get(i, 0) + 1

        for i in s:
            dic[i] -= 1
            if not dic[i]:
                dic.pop(i)
        for i in dic:
            return i

        