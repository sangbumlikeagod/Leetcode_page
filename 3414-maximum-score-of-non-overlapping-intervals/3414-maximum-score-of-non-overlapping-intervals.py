class Solution:
    def init(self, M, MM, DPKEY):
        #0, 1, 2, 3, 4를  다 다뤄야하나? 
        self.prefixSumDP = [[None] * 5 for i in range(MM)]
        self.dp_key = DPKEY


    def changeDPIdx(self, idx):
        return self.dp_key[idx]

    def sync_index(self, dp_idx, intervals_idx):
        # 초기화가 목적
        # dp_idx = 실제 값과 일치 
        # intervals_id, [intervals_idx][1] 이 진짜 인덱스 
        # main에서는 dp_idx < n만 걸고 return dp_idx, intervals_idx로간다. 

        if self.indexed_intervals[intervals_idx][1] < dp_idx:
            while self.indexed_intervals[intervals_idx][1] < dp_idx:
                intervals_idx += 1
        elif self.indexed_intervals[intervals_idx][1] == dp_idx:
            intervals_idx += 1
        elif self.indexed_intervals[intervals_idx][1] > dp_idx:
            dp_idx += 1
        return dp_idx, intervals_idx


    def collect_idxes(self, idx, cn):
        if cn == 0:
            return []

        nIdx = self.prefixSumDP[idx][cn][1]
        orig = self.prefixSumDP[idx][cn][2]
        arr = self.collect_idxes(nIdx, cn - 1)
        arr.append(orig)

        return arr

    def is_changable(self, challenger, challenger_value, champion, cn):
        # self.idx_to_sorted_indexes 을 활용할 수 있도록 
        # 끝까지 가본 뒤에 확인 가능
        # 정확히 확정일 떄만 
        # DP를 통해서 다음 놈들을 찾아야하는데? 
        # print(*self.prefixSumDP, sep='\n')
        # print(challenger, challenger_value, champion, cn)

        challenger_arr = self.collect_idxes(challenger, cn - 1)
        challenger_arr.append(challenger_value)
        champion_arr = self.collect_idxes(champion, cn)
        challenger_arr.sort()
        champion_arr.sort()

        for i in range(len(challenger_arr)):
            if challenger_arr[i] < champion_arr[i]:
                return True
            if challenger_arr[i] > champion_arr[i]:
                return False
        return False

        
    def _sync_index(self, dp_idx, intervals_idx):
        # 초기화가 목적
        # dp_idx = 실제 값과 일치 
        # intervals_id, [intervals_idx][1] 이 진짜 인덱스 
        # main에서는 dp_idx < n만 걸고 return dp_idx, intervals_idx로간다. 
        if dp_idx == -1:
            dp_idx += 1
        elif self.indexed_intervals[intervals_idx][1] < self.changeDPIdx(dp_idx):
            # while self.indexed_intervals[intervals_idx][1] < self.changeDPIdx(dp_idx):
            intervals_idx += 1
        elif self.indexed_intervals[intervals_idx][1] == self.changeDPIdx(dp_idx):
            intervals_idx += 1
        elif self.indexed_intervals[intervals_idx][1] > self.changeDPIdx(dp_idx):
            dp_idx += 1
        return dp_idx, intervals_idx

    def query(self, target):
        # target보다 1이라도 작은 인덱스를 찾는 것
        l = -1
        r = len(self.prefixSumDP) - 1
        # 지네끼리 경합을하니
        while l < r:
            m = (l + r) // 2 + (l + r) % 2
            if self.changeDPIdx(m) < target:
                l = m
            else:
                r = m - 1

        return l



    def _main(self):
        # 처음엔 무조건 dp_idx를 한칸 올리려는 트릭
        dp_idx = -1
        intervals_idx = 0

        while (
            dp_idx < len(self.prefixSumDP)
            and intervals_idx < len(self.indexed_intervals)
        ):
            dp_idx, intervals_idx = self._sync_index(
                dp_idx, intervals_idx
            )

            # print(dp_idx, intervals_idx)
            for i in range(1, 5):
                # 이전값을 그래도 이식
                if self.prefixSumDP[dp_idx - 1][i] is not None:
                    if self.prefixSumDP[dp_idx][i] is None: 
                        self.prefixSumDP[dp_idx][i] = self.prefixSumDP[dp_idx - 1][i]

                    elif self.prefixSumDP[dp_idx - 1][i][0] > self.prefixSumDP[dp_idx][i][0]:
                        self.prefixSumDP[dp_idx][i] = self.prefixSumDP[dp_idx - 1][i]

                if intervals_idx == len(self.indexed_intervals):
                    break
                if self.changeDPIdx(dp_idx) != self.indexed_intervals[intervals_idx][1]:
                    continue

                query_index = self.query(
                    self.indexed_intervals[intervals_idx][0]
                )
                # print(query_index)

                my_weight = self.indexed_intervals[intervals_idx][2]
                
                # 내 인덱스가 아니라 이전 인덱스 넣기다
                original_index = self.indexed_intervals[intervals_idx][3]
                
                # 0은 전부 None일거니 안전
                if i != 1 and query_index == -1:
                    continue

                if self.prefixSumDP[query_index][i - 1] is not None:
                    my_weight += self.prefixSumDP[query_index][i - 1][0]
                elif i != 1:
                    continue

                if self.prefixSumDP[dp_idx][i] is None:
                    self.prefixSumDP[dp_idx][i] = (
                        my_weight,
                        query_index,
                        original_index
                    )
                elif my_weight > self.prefixSumDP[dp_idx][i][0]:
                    self.prefixSumDP[dp_idx][i] = (
                        my_weight,
                        query_index,
                        original_index
                    )
                elif my_weight == self.prefixSumDP[dp_idx][i][0]:
                    # 둘의 인덱스 비교를 통하여.. 바꿀지 확인
                    if self.is_changable(
                        query_index,
                        original_index,
                        dp_idx,
                        i
                    ):
                        self.prefixSumDP[dp_idx][i] = (
                            my_weight,
                            query_index,
                            original_index
                        )



    def maximumWeight(self, intervals: List[List[int]]) -> List[int]:
        #일단 인덱스추가하기
        self.indexed_intervals = [
            [interval[0], interval[1], interval[2], idx] 
            for idx, interval in enumerate(intervals)
        ]
        # intervals의 인덱스를  indexed_intervals 인덱스로 바꿀 수 있는 자료구조 
        self.indexed_intervals.sort(key=lambda x : (x[1], x[0], x[3]))
        self.idx_to_sorted_indexes = [0] * len(self.indexed_intervals)
        keys = set([item[1] for item in self.indexed_intervals])

        M = self.indexed_intervals[-1][1]
        self.init(M, len(keys), sorted(list(keys)))
        for idx, interval in enumerate(self.indexed_intervals):
            self.idx_to_sorted_indexes[interval[3]] = idx


        # 내가 원하는 순서대로 도는지만 확인
        self._main()
        answer_v = 0
        answer = []
        # print(*self.prefixSumDP, sep='\n')
        for i in range(1, 5):
            if self.prefixSumDP[-1][i] is None:
                continue

            if self.prefixSumDP[-1][i][0] > answer_v:

                answer_v = self.prefixSumDP[-1][i][0]
                answer = sorted(self.collect_idxes(
                    len(self.prefixSumDP) - 1, i
                ))
            elif self.prefixSumDP[-1][i][0] == answer_v:
                t = sorted(self.collect_idxes(
                    len(self.prefixSumDP) - 1, i
                ))

                for i in range(len(answer)):
                    if answer[i] > t[i]:
                        answer = t

                    
        return answer

