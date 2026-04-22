class Solution:
    def twoEditWords(self, queries: List[str], dictionary: List[str]) -> List[str]:
        answer = []
        for idx, query in enumerate(queries):
            for dic in dictionary:
                if len(query) != len(dic):
                    continue
                tmp = 0
                for i in range(len(query)):
                    if query[i] != dic[i]:
                        tmp += 1
                    if tmp > 2:
                        break

                if tmp <= 2:
                    answer.append(query)
                    break
        return answer