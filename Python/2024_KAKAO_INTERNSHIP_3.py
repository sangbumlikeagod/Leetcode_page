from itertools import combinations
import heapq
    

def solution(dice):
    answer = []
    max_win = 0
    overlap = {}
    def dice_sum(arg , index : int, ans : int, ansList : list):
        if len(arg) == index:
            heapq.heappush(ansList, ans)
            return 
        for number in dice[arg[index]]:
            dice_sum(arg, index + 1, ans + number, ansList)
        return 
            
    for dices in combinations(range(len(dice)), len(dice) // 2):
        heaplist1 = []
        heaplist2 = []
        oppnent = []
        
        if dices in overlap:
            continue
        for i in range(len(dice)):
            if i not in dices:
                oppnent.append(i)
        dice_sum(dices, 0, 0, heaplist1)
        dice_sum(oppnent, 0, 0, heaplist2)
        win1 = 0
        win2 = 0


        while (heaplist1 and heaplist2):
            # print(heaplist1[0] ,heaplist2[0])
            if (heaplist1[0] > heaplist2[0]):
                win1 += len(heaplist1)
                heapq.heappop(heaplist2)
            elif heaplist1[0] == heaplist2[0]:
                val = heaplist1[0]
                c1count = 0
                c2count = 0
                while (heaplist1 and heaplist1[0] == val):
                    heapq.heappop(heaplist1)
                    c1count += 1
                while (heaplist2 and heaplist2[0] == val):
                    heapq.heappop(heaplist2)
                    c2count += 1
                win1 += c2count * len(heaplist1)
                win2 += c1count * len(heaplist2)
            else:
                win2 += len(heaplist2)
                heapq.heappop(heaplist1)
            # print(win1, win2)

        overlap[dices] = win1
        overlap[tuple(oppnent)] = win2

        # print(dices, tuple(oppnent))
        if (max_win < win1):
            max_win = win1
            answer = list(dices)
        if (max_win < win2):
            max_win = win2
            answer = oppnent
        
            
    for i in range(len(answer)):
        answer[i] += 1
    return answer