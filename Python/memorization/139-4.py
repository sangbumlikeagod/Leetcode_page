class Solution:
    def wordBreak(self, s: str, wordDict: list[str]) -> bool:

        table = {}
        overlap = {}
        for i in wordDict:
            table[i] = True
        
        def search(s):
            if not s or s in table:
                return True
            if s in overlap:
                return overlap[s]
            for i in wordDict:
                if s[:len(i)] == i:
                    if search(s[len(i):]):
                        overlap[s] = True
                        return True
            overlap[s] = False
            return False

            
        default = search(s)
        
        return default