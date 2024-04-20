import os
from collections import deque
path=os.getcwd()
os.chdir(f'{path}/virtcloud/Leetcode')
os.listdir()
f=open('input.txt','r',encoding='UTF8')
line = f.readline()
line2= f.readline()
print(line,line2)
line2=line2.rstrip('\n ')
a=line2.split(' ')
size=int(line)
import heapq
dq=deque([])
ans = 0 

for i in range(size+2):
    
    if i<2:
        dq.append(int(a[i]))
    elif 2<=i<=4:
        t=i-2
        dq.append(int(a[i]))
        big_chunk=[]
        for i in dq:
            heapq.heappush(big_chunk,i)
        if int(a[t])==heapq.heappop(big_chunk):
            ans+=int(a[t])-heapq.heappop(big_chunk)
    elif 5<=i<size:
        t=i-2
        dq.append(int(a[i]))
        dq.popleft()
        big_chunk=[]
        for i in dq:
            heapq.heappush(big_chunk,i)
        if int(a[t])==heapq.heappop(big_chunk):
            ans+=int(a[t])-heapq.heappop(big_chunk)
    elif size<=i:
        t=i-2
        dq.popleft()
        big_chunk=[]
        for i in dq:
            heapq.heappush(big_chunk,i)
        if int(a[t])==heapq.heappop(big_chunk):
            ans+=int(a[t])-heapq.heappop(big_chunk)
        
    print(dq)
    

print(ans)


f.close()
