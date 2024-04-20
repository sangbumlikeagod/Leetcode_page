from queue import Queue
class Solution:
    def canFinish(self, numCourses, prerequisites) -> bool:
        ans = []
        end = []        
        for _ in range(numCourses):
            end += [[]]
        pre = [0] * numCourses
        
        for i in prerequisites:
            end[i[0]].append(i[1])
            pre[i[1]] += 1
        
        q = Queue()
        
        for i in range(numCourses):
            if pre[i] == 0:
                q.put(i)
        # print(end, pre)
        # print(q.get())
        while q.empty() != True:
            t = q.get()
            print(t)
            ans.append(t)
            
            for arg in end[t]:
                pre[arg] -= 1
                if pre[arg] == 0:
                    q.put(arg)
        
        return len(ans) == numCourses
         
numCourses = 2
prerequisites = [[1,0]] 
ans = Solution()

print(ans.canFinish(numCourses,prerequisites))

