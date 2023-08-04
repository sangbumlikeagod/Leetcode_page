class Solution:
    def __init__(self):
        self.alphabet = {
            '2' : ['a','b','c'],
            '3' : ['d', 'e', 'f'],
            '4' : ['g', 'h', 'i'],
            '5' : ['j', 'k', 'l'],
            '6' : ['m', 'n', 'o'],
            '7' : ['p', 'q', 'r', 's'],
            '8' : ['t', 'u', 'v'],
            '9' : ['w','x','y','z']
        }
    def letterCombinations(self, digits: str):
        while digits:
            if len(digits) == 1:
                return self.alphabet[digits]
            else:
                return [ i + j for i in self.alphabet[digits[0]] for j in self.letterCombinations(digits[1:])]
        return digits
a = Solution()
print(a.letterCombinations(""))