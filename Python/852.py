class Solution:
    def peakIndexInMountainArray(self, arr: List[int]) -> int:
        start = 1
        end = len(arr) - 2 

        while end - start > 1:

            mid = (end + start) // 2
            if arr[mid - 1] < arr[mid] < arr[mid + 1]:
                # print(mid)
                start = mid
            elif arr[mid - 1] > arr[mid] > arr[mid + 1]:
                # print('\t', mid)
                end = mid
            elif arr[mid - 1] < arr[mid] > arr[mid + 1]:
                # print('\t\t', mid)
                return mid
        return end if arr[end] > arr[start] else start
        