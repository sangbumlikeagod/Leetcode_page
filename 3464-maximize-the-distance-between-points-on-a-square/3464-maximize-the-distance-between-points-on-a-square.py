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
        # 나온 값
        limit = len(self.flatten_list)
        # idx = 0
        
        # 일단 얘보다 크면 안됨
        first_query_result = -1

        possible_first_query = min(self.query(q, 0), limit - 1)

        for i in range(0, possible_first_query + 1):
            idx = i
            lim_val = self.n * 4 - (q - self.flatten_list[idx])

            tcnt = 1
            while True:
                qr = self.query(q, self.flatten_list[idx])
                if qr == limit:
                    break
                # if idx == 0:
                #     first_query_result = qr

                # print(idx, qr)
                # print(qr, self.flatten_list[qr], lim_val)

                if self.flatten_list[qr] > lim_val:
                    break
                #     # 시작인덱스를 지좆대로로 했기 때문에 이런 에러에 걸린다.
                #     last_query = -(self.n * 4 - self.flatten_list[qr])
                #     # 마지막 인덱스 넘의 쿼리와 맞는 인덱스
                #     last_query_val = self.query(q, last_query)
                #     print("last_query:", last_query, "last_query_val", last_query_val)
                #     if self.flatten_list[last_query_val] + q <= self.flatten_list[first_query_result]:
                #         #얘로 바꾼다치고 이후엔 변환없음
                #         cnt += 1
                #     break
                tcnt += 1
                idx = qr
            cnt = max(cnt, tcnt)
            
            # print(f"interval: {q}, cnt: {cnt}")
        return cnt


    def query(self, q, x):
        # 현재지점 x보다 q이상 큰점중 가장 작은 점을 구해라, 
        # x인덱스

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
        # print(flatten.flatten_list)

        while l < r:
            m = (l + r) // 2 + (l + r) % 2
            cnt = flatten.circular_binary_search(m)
            if cnt >= k:
                l = m
            else:
                r = m - 1

        return l

