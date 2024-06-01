class Solution:
    def getKth(self, lo: int, hi: int, k: int) -> int:

        dic = {1 : 0}
        def colazt(num):
            if dic.get(num, -1) != -1:
                return dic[num]
            else:
                if num % 2:
                    dic[num] = colazt(3 * num + 1) + 1
                else:
                    dic[num] = colazt(num // 2) + 1
                return dic[num]
        ans = []
        for i in range(lo, hi + 1):
            ans.append((colazt(i), i))
        # print(dic)
        ans.sort()
        # print(ans)
        return ans[k - 1][1]