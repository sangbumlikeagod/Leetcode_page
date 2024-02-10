from itertools import permutations
import heapq
    

def solution(dice):
    answer = []
    max_win = 0 
    overlap = {}
    def dice_sum(arg : tuple | list, index : int, ans : int, ansList : list):
        if len(arg) == index:
            heapq.heappush(ansList, ans)
        for number in dices[arg[index]]:
            dice_sum(arg, index + 1, ans + number, ansList)
            
            
    for dices in permutations(range(len(dice)), len(dice) // 2):
        heaplist1 = []
        heaplist2 = []
        oppnent = []
        for i in range(len(dice)):
            if i not in dices:
                oppnent.append(i)
        dice_sum(dices, 0, 0, heaplist1)
        dice_sum(oppnent, 0, 0, heaplist2)
        win1 = 0
        win2 = 0
        while (heaplist1 and heaplist2):
            if (heaplist1[0] > heaplist2[0]):
                win1 += len(heaplist1)
                heapq.heappop(heaplist2)
            elif heaplist1[0] == heaplist2[0]:
                heapq.heappop(heaplist1)
                heapq.heappop(heaplist2)
            else:
                win2 += len(heaplist1)
                heapq.heappop(heaplist2)
            # 강한놈이 남는 시스템인거지 내 나머지 놈들이 얘 다이김이란 뜻에서 자기 크기 전부를 더해줘야함
        overlap[dices] = win1
        overlap[tuple(oppnent)] = win2
                
        
            
        
    return answer