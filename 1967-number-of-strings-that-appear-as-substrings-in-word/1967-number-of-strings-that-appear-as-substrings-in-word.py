class Solution:
    def numOfStrings(self, patterns: List[str], word: str) -> int:
        answer = 0
        for pattern in patterns:
            if pattern in word:
                answer += 1
        return answer