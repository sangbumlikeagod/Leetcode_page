
'''
1 번째 아이디어 시도 
'''
# class Solution:
#     def eraseOverlapIntervals(self, intervals) -> int:
#         ans = 0
#         intervals.sort(key = lambda x : x[0])
#         size = len( intervals )
#         for idx in range(size-1):
            
#             if intervals[idx][1] > intervals[idx+1][0]:
#                 if  (intervals[idx][1] - intervals[idx][0]) > (intervals[idx+1][1] - intervals[idx+1][0]):
#                     intervals.pop(idx)
#                 elif (intervals[idx][1] - intervals[idx][0]) < (intervals[idx+1][1] - intervals[idx+1][0]):
#                     intervals.pop(idx+1)
#                 else: 
#                     if idx != size - 2:
#                         continue
#                     else : 
#                         if intervals[idx+1][1] > intervals[idx+2][0] :
#                             intervals.pop(idx+1)
                        
#                         else : 
#                             intervals.pop(idx)
#                 continue
#             else:
#                 pass
#         return ans
# intervals = [[1,2],[2,3],[3,4],[1,3]]
# a = Solution()
# print(a.eraseOverlapIntervals(intervals))            
                       
'''
아니 pop하면 안된다는 사실을 왜 몰랐지

'''
    
    
class Solution:
    def eraseOverlapIntervals(self, intervals) -> int:
        ans = idx = 0
        intervals.sort(key = lambda x : x[0])
        print(intervals)
        size = len( intervals )
        j = idx + 1            
        while idx < size-1 and j < size :
            print( 'idx = ', idx , 'ans = ' ,ans) 
            if intervals[idx][1] > intervals[j][0]:
                if  (intervals[idx][1] - intervals[idx][0]) > (intervals[j][1] - intervals[j][0]):
                    idx = j 
                    j += 1
                elif (intervals[idx][1] - intervals[idx][0]) < (intervals[j][1] - intervals[j][0]):
                    j += 1
                else: 
                    if idx > size - 2 or j == size-1:
                        idx = j
                        j += 1
                        
                    else : 
                        if intervals[j][1] > intervals[j+1][0] :
                            j += 1
                        else : 
                            idx = j
                            j += 1
                            
                ans += 1 
            else:
                idx = j
                j += 1

        return ans

# intervals = [[1,2],[2,3],[3,4],[1,3]]
# intervals = [[1,2],[2,3]]
# intervals = [[1,2],[1,2],[1,2]]
# intervals = [[0,2],[1,3],[2,4],[3,5],[4,6]]
intervals = [[-52,31],[-73,-26],[82,97],[-65,-11],[-62,-49],[95,99],[58,95],[-31,49],[66,98],[-63,2],[30,47],[-40,-26]]
a = Solution()
print(a.eraseOverlapIntervals(intervals))            
