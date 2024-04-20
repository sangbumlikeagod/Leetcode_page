########################## 리스트를 소환후 힙큐로 데이터를 넣었을 때 리스트의 remove가 가능한지 ##############################
import heapq

lst1=[]

heapq.heappush(lst1,2)
heapq.heappush(lst1,3)
heapq.heappush(lst1,8)
heapq.heappush(lst1,22)
heapq.heappush(lst1,6)
heapq.heappush(lst1,3)

print(lst1)
lst1.remove(2)
heapq.heappop(lst1)
print(lst1)

heapq.heapify(lst1)
print(heapq.heappop(lst1))
print(heapq.heappop(lst1))
lst1.remove(22)
print(heapq.heappop(lst1))