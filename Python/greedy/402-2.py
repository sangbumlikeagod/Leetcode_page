class Solution:
    def removeKdigits(self, num: str, k: int) -> str:
        size = len(num)

        retu_lst = [num[0]]
        if size == k:
            return '0'
        # size 가  1이라면 어차피 k도 1이기 떄문에 상관 없음
        j = 1
        count = 0
        while count < k:
            # 생각해보면 k가 남은 상태로 맨 뒤로 포인터가 갔다면. 이미 주어진 수는 오름차순일 것이다
						# 그렇지 않다면 그 전에 이미 삭제가 일어났을 것이기 때문에
            if j == size:
                while count < k:
                    # print(count)
                    count += 1
                    retu_lst.pop()
                break
            # 비교해야하는 내용은 딱 두개밖에 없다. 이제까지 문자열중 가장 마지막값과
						# 남은 문자열들의 첫번째 값 따라서 그 두수중 오른쪽이 같거나 클경우 
						# 오른쪽 문자 왼쪽 문자열로 이동, 그 반대일경우 왼쪽문자열의 첫번째 값을 삭제
						# 그런데 왼쪽 문자열이 빈칸일경우 j를 자동으로 한칸 추가해주고 이동시킨다
						# 여기서 우려 인덱스 문제가 우려 됐는데 일단 count한번당 j한번이 이동한 것이고 내가 앞에서
						# 조건을 줬기 때문에 count는 무조건 size보다 작다. 따라서 j를 size까지 세기때문에 문제는 없을듯.
            
            if int(retu_lst[-1]) <= int(num[j]):
                retu_lst.append(num[j])
                j += 1
            else:
                # print('삭제 조건이 발견됨')
                count += 1
                retu_lst.pop()
                if not retu_lst:
                    retu_lst.append(num[j])
                    j += 1
                
            
        # k가 끝나면서 j뒤에 문자열이 남아있을 수 있으므로 그것들을 뺴줘야 한다. 
        ans = (''.join(retu_lst) + num[j:]).lstrip('0')
        return ans if ans else '0'
    
    
#이전 풀이

class Solution:
    def removeKdigits(self, num: str, k: int) -> str:
        pointer = 0
        size = len(num)
        new_lst = []
        new_llst = []
        while pointer < size:
            count = 1
            while pointer < size - 1 and num[pointer] == num[pointer + 1]:
                count += 1
                pointer += 1
            new_lst += [num[pointer]]
            new_llst += [count]
            pointer += 1
			# 반복을 줄이기 위해 [ 1, 1, 1, 1, 3, 4, 5, 5, 5, 5 ] 리스트를 [ 1 , 3 , 4, 5 ] 와
			# [ 4, 1, 1, 4 ] 두개의 리스트로 정리
        
        while new_lst and k > 0:
            size2 = len(new_lst)
            pointer = 0
            if new_lst[pointer] == '0':
                new_lst.pop(pointer)
                new_llst.pop(pointer)
                continue
            while pointer < size2:
                if pointer == size2 - 1:
                    new_llst[pointer] -= 1
                    if new_llst[pointer] == 0:
                        new_lst.pop(pointer)
                        new_llst.pop(pointer)
                    break
                elif new_lst[pointer] > new_lst[pointer + 1]:
                    new_llst[pointer] -= 1
                    if new_llst[pointer] == 0:
                        new_lst.pop(pointer)
                        new_llst.pop(pointer)                    
                    break
                else: pointer += 1
            k -= 1
        if new_lst and new_lst[0] == '0':
            new_lst.pop(0)
            new_llst.pop(0)
            
        ret_string = ''.join([new_lst[i] * new_llst[i] for i in range(len(new_lst))])
        return ret_string if ret_string else '0'