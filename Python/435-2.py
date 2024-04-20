class Solution:
    def eraseOverlapIntervals(self, intervals) -> int:
        size = len(intervals)
        intervals2 = set(map(tuple,intervals))

        intervals = list(intervals2)
        ans = 0 
        ans += size - len(intervals)
        print

        size = len(intervals)
        table = [{} for _ in range(size)]
        intervals.sort( key = lambda x : x[0])
        
        i = 0 
        for i in range(size-1):
            j = i + 1 
            while j < size:
                if intervals[i][1] > intervals[j][0]:
                        table[i][tuple(intervals[j])] = j
                        table[j][tuple(intervals[i])] = i
                        j += 1

                else:
                    j += 1
        
        
        while sum([len(x) for x in table]):
            idx ,max_it = max(enumerate(table), key = lambda x : len(x[1]))
            print(len(max_it))
            for i in max_it.keys():
                a = table[max_it.get(i)].pop(tuple(intervals[idx]))
            table[idx] = {}
            ans += 1
        return ans
    
### 2차 시도 ###