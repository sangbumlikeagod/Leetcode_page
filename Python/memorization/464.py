class Solution:
    def __init__(self) -> None:
        self.masking = []
    def canIWin(self, maxChoosableInteger: int, desiredTotal: int) -> bool:
        if sum(range(maxChoosableInteger + 1)) < desiredTotal:
            return False
        self.masking = [True] * (maxChoosableInteger + 1) 
        self.size = len(self.masking)
# 이제부터 두쌍씩 묶겠다 
        def search(desiredTotal):
            if sum([ i  for i in range(1, self.size) if self.masking[i] ]) < desiredTotal:
                print('얘네 만으로 충분하지 않음')
                return False
                
            for i in range(self.size - 1, 0, -1):
                if self.masking[i]:
                    if i >= desiredTotal:
                        print('나의 승리')
                        return True
                    break
                    
            for j in range(1, self.size - 1):
                if self.masking[j]:
                    if j + i >= desiredTotal:
                        print('나의 패배')
                        return False
                    break
            # 적어도 이 단계에서는 판가름이 안난다는 소리 
            # 다음으로 갈 애들을 모두 고를거야 
                    
            for _ in range(self.size - 1, 0, -1):
                if self.masking[_]:
                    #어디에 어떻게 넣을 것인가 중복의 정보를
                    
                    # if _ >= desiredTotal:
                    #     return True
                    self.masking[_] = False

                    
                    
                    print(self.masking , f'내가 {_} 를 고른상황 ' , desiredTotal)
                    # 내가 골랐을때 무조건 높을 경우엔 트루만 리턴 
                    # 아닐경우엔 
                    
                    # is_brake = False
                    # copy2 = self.masking[:]
                    
                    for oppo in range(_ - 1, 0, -1):
                        # print(copy2)
                        if self.masking[oppo]: 
                            self.masking[oppo] = False
                            print( f'남은 값은 {desiredTotal - _}이며 ', f' 상대방은 {oppo}를 골랐다' , self.masking)
                            # if oppo >= desiredTotal - _:
                            #     # print('나의 패배')
                            #     break
                            # print(self.masking, copy2)
                            # print(self.masking, copy2)
                            next =  search(desiredTotal - _ - oppo)
                            # self.masking = copy2[:]
                            self.masking[oppo] = True
                            # print(next)
                            if not next:
                                break
                        
                    else:
                        # print('모든경우의 수 통과')
                        # self.masking[_] = True
                        return True
                    # self.masking[_] = True
            else:
                # 주어진 total을 마찬가지로 주어진 수들로 구현해낼 수 있는가 ? 바깥의 포문은 주어진
                # 수들중 하나만 맞아도 가능한 문제지만 안쪽의 포문은 모두 같지 않으면 틀리는 문제다
                return False
                
                # 지금 쟁점이 되는건 언제 마스킹을 원래대로 돌릴 것인가 지금은 두단계에 걸쳐서 하고있잖아
                # 내가 고른다 - 상대방이 고른다 - 이미 고른걸 못고르게 한 채로 재귀한다. 
                # 내가 처음 20을 골랐을 때 반드시 이길 수 없다면 19를 골랐을 때는 20말고 다른 숫자는 볼 필요가 없나?
                # 큰놈을 골랐을떈 두개로 끝나는데 그렇지 않을경우엔 3개가 걸리는 답이 있음?
                # 없지 않나 근데 일단 이론적으론 다 해봐야 할 것 같다.
                # 4 3 2 1  
                
            # 그냥 상대애가 내가 전에 골랐던걸 고르면 안된다는 룰임 그런데 다음 재귀로 넘어갈떄는 그 두개만 빼야됨 
            # 같은 반복에서 75 57은 안될일이지만 이미 10 9 를 했다고 75의 다음 재귀에서 10 9 를 선택하지 못한다? 
            
        return search(desiredTotal)
a = Solution()
maxChoosableInteger = 10
desiredTotal = 40
print(a.canIWin(maxChoosableInteger, desiredTotal))

# 얘를 쓰는 모든 애들이 통과하지 못했다는 뜻도 되지만 
# 역시 시간초과가. 지금 제대로 줄이지를 못하고 있어서 그래
