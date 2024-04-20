from itertools import combinations
import heapq
def solution(dice):# -> Any:
    select = len(dice) // 2

    answer = []
    dic = {}
    max_val = 0     
    comb = list(combinations(range(len(dice)), select))
    # print(comb)
    def getsum(now, val, listid, takenlist):
        if now == select:
            return heapq.heappush(listid, -val)
        for i in range(6):
            getsum(now + 1, takenlist[now][i] + val, listid, takenlist)

            
    for i in comb:
        if i in dic:
            continue
        win = loose = 0
        draw = 0
        dic[i] = 1
        dic[(tuple([j for j in range(select * 2) if j not in i]))] = 1
        
        # 지금부터 조합에따른 승리결과 구하기
        # heap
        heap1 = []
        heap2 = []
        #모든 경우의 수 다 더하기
        for_lose = [dice[j] for j in range(select * 2) if j not in i]
        for_win = [dice[j] for j in range(select * 2) if j in i]
        getsum(0, 0, heap2, for_lose)
        getsum(0, 0, heap1, for_win)

        while heap1 and heap2:
            if -heap1[0] > -heap2[0]:
                win += len(heap2)
                heapq.heappop(heap1)
            elif -heap1[0] < -heap2[0]:
                loose += len(heap1)
                heapq.heappop(heap2)
            else:
                count1 = count2 = 0
                val1 = -heap1[0]
                val2 = -heap2[0]
                while heap1 and -heap1[0] == val1: 
                    count1 += 1
                    heapq.heappop(heap1)
                while heap2 and -heap2[0] == val2: 
                    count2 += 1
                    heapq.heappop(heap2)
                win += len(heap2) * count1
                loose += len(heap1) * count2
                draw += count1 * count2

        if win > max_val:
            max_val = win
            answer = list(i)
        if loose > max_val:
            max_val = loose
            answer = [j for j in range(select * 2) if j not in i]
        max_val = max(max_val, win, loose)
        
    return list(map(lambda x : x + 1, answer))







dices = [
[[1, 2, 3, 4, 5, 6], [3, 3, 3, 3, 4,
4], [1,3,3,4,4, 4], [1,1,4,4,5,
5]],
[[1, 2, 3, 4, 5, 6], [2, 2, 4, 4, 6,
6]],
[[40, 41,42, 43, 44, 45], [43,
43, 42, 42, 41, 41], [1, 1, 80, 80,
80, 80], [70, 70, 1, 1, 70, 70]]
]
for dice in dices:
    print(solution(dice))