class Solution:
    def canBeTypedWords(self, text: str, brokenLetters: str) -> int:
        words = text.split()
        lst = list(brokenLetters)
        answer = 0
        for word in words:
            flag = True
            for char in lst:
                if char in word:
                    flag = False
            if flag:
                answer += 1
        return answer