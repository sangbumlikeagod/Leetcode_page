class Flatten:
    def __init__(
        self,
        n
    ):
        self.n = n
        self.flatten_list = []



    def append(self, point):
        # 반시계 방향으로 돌기때문에 yis0, xisn은 + 나머지는 n - 로 로 저장
        if point[1] == 0:
            self.flatten_list.append(point[0])
        elif point[0] == self.n:
            self.flatten_list.append(point[1] + self.n)
        elif point[1] == self.n:
            self.flatten_list.append(self.n - point[0] + self.n * 2)
        elif point[0] == 0:
            self.flatten_list.append(self.n - point[1] + self.n * 3)


    def circular_binary_search(self, q):
        cnt = 1
        limit = len(self.flatten_list)

        possible_first_query = min(self.query(q, 0), limit - 1)

        for i in range(0, possible_first_query + 1):
            idx = i
            lim_val = self.n * 4 - (q - self.flatten_list[idx])

            tcnt = 1
            while True:
                qr = self.query(q, self.flatten_list[idx])
                if qr == limit:
                    break

                if self.flatten_list[qr] > lim_val:
                    break
                tcnt += 1
                idx = qr
            cnt = max(cnt, tcnt)
        return cnt


    def query(self, q, x):
        l = 0
        r = len(self.flatten_list)
        query_val = x + q

        while l < r:
            m = (l + r) // 2
            if self.flatten_list[m] < query_val:
                l = m + 1
            else:
                r = m

        return l
        ...

class Solution:
    def maxDistance(self, side: int, points: List[List[int]], k: int) -> int:
        l = 1
        r = side + 1

        flatten = Flatten(side)
        for point in points:
            flatten.append(point)
        flatten.flatten_list.sort()

        while l < r:
            m = (l + r) // 2 + (l + r) % 2
            cnt = flatten.circular_binary_search(m)
            if cnt >= k:
                l = m
            else:
                r = m - 1

        return l

