class Solution:
    def search(self, nums: list[int], target: int) -> int:

        # 분기점을 발견하고 그 뒤에 양쪽에 대해서 이진검색을 한다고 생각하자 
        # 분기점을 발견하지 못할 경우도 있으니 그 떄마다 해당 숫자가 있는지를 확인하고
        start = 0
        last = len(nums) - 1
        # 유일하게 두개일 때면 내림차순이 가능 
        if last == 1:
            if nums[0] == target:
                return 0
            elif nums[1] == target:
                return 1
            return -1

        # 먼저 피크를 찾는다 
        def find_peak(start, last):
            while start <= last:
                print(start, last)
                mid = (start + last) // 2
                # print(mid > 0 , nums[mid - 1] < nums[mid] , mid < last ,  nums[mid + 1] < nums[mid])


                if mid > 0 and nums[mid - 1] < nums[mid] and mid <  len(nums) - 1 and  nums[mid + 1] < nums[mid]:
                    print('피크에 도달')
                    return mid
  
                # left 보다 크다면 peak는 오른쪽에 있단거고
                # right보다 작으면 peak이 왼쪽에 있단 거다
                # 오름 차순일떄를 얘기하는건데 
                # 내림차순일때는 ?
                elif nums[mid] >= nums[start]:
                    start = mid + 1
                    
                elif nums[mid] < nums[last]:
                    last = mid - 1
            return -1
        
        def binary_search(start, last):
            
            while start <= last:
                print(start, last)
                mid = (start + last) // 2
                if nums[mid] == target:
                    return mid
                elif nums[mid] > target:
                    last = mid - 1
                else:
                    start = mid + 1
            return -1
        

        peak = find_peak(start, last)
        if peak != -1:
            if nums[peak] == target:
                return peak
            left = binary_search(start, peak - 1)
            right = binary_search(peak + 1, last)
            if left * right == 1:
                return -1
            else:
                return left if left > right else right
        else:
            print('못찾음')
            if nums[start] == target:
                return start
            elif nums[last] == target:
                return last
            return binary_search(start + 1, last - 1)

        
nums = [4,5,6,7,0,1,2]
target = 0
# nums = [1, 2, 3, 4, 5, 6]
nums = [3,4,5,6,7,1,2]
nums = [5,1,2,3,4]
nums = [7,1,2,3,4,5,6]
target = 3

a = Solution()
print(a.search(nums, target))

