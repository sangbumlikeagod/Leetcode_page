# class Solution:
#     def eraseOverlapIntervals(self, intervals) -> int:
#         intervals.sort(key=lambda x: x[1])
#         size = len(intervals)
#         i = 0
#         ok = 1
#         for i in range(size-1):
#             nex = i + 1 
#             if intervals[i][1] <= intervals[nex][0]:
#                 ok += 1
#         return size - ok
                
                
                
class Solution:
    def eraseOverlapIntervals(self, intervals) -> int:
        intervals.sort(key=lambda x: x[1])
        size = len(intervals)
        i = 1
        prev = 0
        ok = 1
        print(intervals)
        for i in range(size):
            if intervals[i][0] >= intervals[prev][1]:
                ok += 1
                prev = i    
        return size - ok
                
                
intervals = [[-52,31],[-73,-26],[82,97],[-65,-11],[-62,-49],[95,99],[58,95],[-31,49],[66,98],[-63,2],[30,47],[-40,-26]]
a = Solution()
print(a.eraseOverlapIntervals(intervals))            

# class Solution:
#     def eraseOverlapIntervals(self, intervals) -> int:
#         intervals.sort(key=lambda x: x[0], reversed == True)
#         size = len(intervals)
#         i = 1
#         prev = 0
#         ok = 1
#         for i in range(size-1):
#             if intervals[i][0] >= intervals[prev][1]:
#                 ok += 1
#                 prev = i
#         return size - ok
                