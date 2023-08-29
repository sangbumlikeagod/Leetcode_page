class Solution:
    def __init__(self) -> None:
        self.masking = []
    def canIWin(self, maxChoosableInteger: int, desiredTotal: int) -> bool:
        if sum(range(maxChoosableInteger + 1)) < desiredTotal:
            return False
        self.masking = [True] * (maxChoosableInteger + 1) 
        self.size = len(self.masking)
        def search(desiredTotal):
            is_possible = False
            copy = self.masking[:]
            for _ in range(self.size - 1, 0, -1):
                if self.masking[_]:
                    # print('------------------')
                    if _ >= desiredTotal:
                        return True
                    
                    
                    self.masking[_] = False
                    # copy = self.masking[:]
                    
                    
                    print(self.masking , f'내가 {_} 를 고른상황 ' , desiredTotal, copy)
                    # 내가 골랐을때 무조건 높을 경우엔 트루만 리턴 
                    # 아닐경우엔 
                    
                    # is_brake = False
                    copy2 = self.masking[:]
                    
                    for oppo in range(self.size - 1, 0, -1):
                        # print(copy2)
                        if self.masking[oppo]: 
                            print( f'남은 값은 {desiredTotal - _}이며 ', f' 상대방은 {oppo}를 골랐다' , self.masking)
                            if oppo >= desiredTotal - _:
                                # print('나의 패배')
                                break
                            # print(self.masking, copy2)
                            self.masking[oppo] = False
                            # print(self.masking, copy2)s
                            next =  search(desiredTotal - _ - oppo)
                            # self.masking = copy2[:]
                            # self.masking[oppo] = True
                            # print(next)
                            if not next:
                                break
                        
                    else:
                        # print('모든경우의 수 통과')
                        # self.masking[_] = True
                        self.masking = copy[:]
                        return True
                    # self.masking[_] = True
                else:
                    continue
            
            else:
                # 주어진 total을 마찬가지로 주어진 수들로 구현해낼 수 있는가 ? 바깥의 포문은 주어진
                # 수들중 하나만 맞아도 가능한 문제지만 안쪽의 포문은 모두 같지 않으면 틀리는 문제다
                self.masking = copy[:]
                return False
                
                # 지금 쟁점이 되는건 언제 마스킹을 원래대로 돌릴 것인가 지금은 두단계에 걸쳐서 하고있잖아
                # 내가 고른다 - 상대방이 고른다 - 이미 고른걸 못고르게 한 채로 재귀한다. 
                # 내가 처음 20을 골랐을 때 반드시 이길 수 없다면 19를 골랐을 때는 20말고 다른 숫자는 볼 필요가 없나?
                # 큰놈을 골랐을떈 두개로 끝나는데 그렇지 않을경우엔 3개가 걸리는 답이 있음?
                # 없지 않나 근데 일단 이론적으론 다 해봐야 할 것 같다.
                # 4 3 2 1  

        return search(desiredTotal)
    
maxChoosableInteger = 10
desiredTotal = 40
a = Solution()
print(a.canIWin(maxChoosableInteger, desiredTotal))

