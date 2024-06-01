'''

최소.

경우의 수를 안 따질 수가 있나

크기를 1부터 올리는데. 커지면 -1 리턴

구간합을해서 리스트를 구한다고 한다면  +  n + 1 개씩 반복됨 최대 n ^ 2 가 나옴
나쁘지 않은 수준이다.

반대로 가지치기 방식으로 한다면 2 ^ n인데 메모리제이션을 사용한 dfs를 사용하면 
비슷한 수준으로 이어질 것


'''

# 구간합 버전

class Solution:
    def minOperations(self, nums: list[int], x: int) -> int:        
        from itertools import accumulate    
        # 왼쪽 k개 부터 오른쪽 k개까지 이어지니 
        ac = list(accumulate(nums))
        # 왼쪽 끝을 a ( N - k ) 오른쪽 끝은 ( N - 1 ) 
        # 거기서 총 k번 만큼 오른쪽으로 움직인다
        # 계산하는 공식은 전체 합에서 왼쪽 바로 직전 요소를 빼주고 오른쪽 요소를 합하는 것
        # 그런데 맨 마지막에 있는 경우는 
        # n - 2 번 움직이게하고 처음과 끝은 따로 처리해 주는게 낫겠다
        k = 1
        length = len(nums)
        while k < length:
            if ac[k - 1] == x or ac[length - 1] - ac[length - 1 - k] == x:
                return k
            left = length - k + 1
            right = 0
            while left < length:
                tmp = ac[length - 1] - ac[left - 1] + ac[right]
                if tmp == x:
                    return k
                left += 1
                right += 1 
            k += 1
        
        return length if ac[-1] == x else - 1 
    
class Solution:
    def minOperations(self, nums: list[int], x: int) -> int:
        length = len(nums)
        if length == 1:
            return -1 if nums[0] != x else 1
        summ = nums[1]
        start = 1
        end = 2
        total = sum(nums)
        min_val = length + 1
        while start <= end < length:
            if total - summ == x:
                min_val = min(min_val, length - (end - start))
                summ -= nums[start]
                summ += nums[end]
                start += 1
                end += 1
            elif total - summ < x:
                summ -= nums[start]
                start += 1
            
            else:
                summ += nums[end]
                end += 1
        return min_val if min_val != length + 1 else -1
