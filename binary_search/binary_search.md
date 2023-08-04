# 이진 검색

---
이진 검색은 어떤 배열과 그 속에 비교 가능한 정보들이 주어질 때 그 정보들이 한가지 기준으로 정렬되어 있다면 예측한 정보가 주는 방향성을 새로운 정보로 받아들여 검색해야할 정보를 반으로 줄이는 알고리즘이다. 

이진검색에 대한 제대로된 이해를 위해 몇가지의 문제를 풀었다.


## 이진 검색의 필수 요소
 이진 검색에는 다음과 같은 요소들이 반드시 필요하다
 1. 찾아야하는 요소 조건
 2. 정렬된 공간
 3. 종료 조건
 
리트코드 69번 sqrt문제에서는 주어진 수의 제곱수의 정수 부분을 찾는 문제를 주었다. 
이 문제를 정수 ** (0.5) 로 해도 되지만 
이진 검색의 개념으로도 풀 수 있었는데.

주어진 수 이하의 수는 x이하의 정수로 정렬된 공간이고 또한 종료조건은 두 가지가 존재하는데 

* 어떤 수의 제곱이 타겟 수일 경우에
* 그 수를 찾는 양쪽 범위가 같거나 충분히 가까워 졌을때이다.



## 구현 방식
이진검색을 구현하는 방법으로는 배열의 처음과 끝을 설정하고 그 중간 배열의 값을 목표와 비교해 맞을경우 리턴하고 다를 경우 리턴하지 mid를 기준으로 왼쪽으로 이동하거나 오른쪽으로 이동하는 방식을 취한다.


```python

class Solution:
    def search(self, nums: List[int], target: int) -> int:
        left = 0
        right = len(nums) - 1

        while start <= end:
            middle = (start + end) // 2
            if a[middle] == key:
                return True
            elif a[middle] > key:
                end = middle - 1
            else:
                start = middle + 1
        return False

```


나는 a == b의 과정을 고려하지 않고 마지막에 a를 한번 더 계산하는 방법을 선택했었는데 경우에 따라서 유연하게 사용해야 할 것 같다. 


# 쉬운 문제들 


### 69번

```python
class Solution:
    def mySqrt(self, x: int) -> int:
        if x == 0 or x == 1:
            return x
        i = 1
        j = x
        while j > i and j - i >1:
            tmp = (i + j)//2
            tmp_2 = tmp ** 2
            if tmp_2 == x:
                return tmp
            elif tmp_2 < x:
                i = tmp
            else:
                j = tmp
        return i

```

입력값 : 정수.

사건 : 입력값이 주어졌을때 입력값의 정수 부분을 출력해라

출력값: 정수

정수연산이 편해보이는 문제에서 그렇지않고 다른 방식으로 문제를 푼게 만족스러웠다.

### 704번

```python
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        left = 0
        right = len(nums) - 1

        def recur(left, right):
            if right - left <= 0:
                return left if nums[left] == target else -1
            mid = (left + right) // 2 
            if nums[mid] == target:
                return mid
            elif nums[mid] < target:
                return recur(mid+1, right)
            else:
                return recur(left, mid-1)

    
        return recur(left, right)
```

입력값 : 정렬 배열, 정수 타겟

출력값: 정수

반복문이 아닌 재귀를 이용해서 풀어본 문제이다. 둘의 차이가 0보다 작아질때를 따로 구별하고 나머지 경우에 target과 비교해 재귀를 하였다.
