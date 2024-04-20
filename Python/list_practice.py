table_hash = {}

import random
print([x for x in range(10)])

lst1 = {x : y if random.randint(0,10) == x else random.randint(1,10) for x in range(10) for y in range(10).__reversed__() }
print(lst1)


print(table_hash)
## 테이블 아이템 
for x, y in table_hash.items():
    print ((x, y))


#리스트 컴프리 헨션은 
# lst2 = [[0,0] if _ < k  else   for _ in range(10) for k in range(10) ]
# print(lst2)


print(lst1.items())
print(sorted(list(lst1.items()),key = lambda x : x[1] ))
# 람드를 쓰면 돼용 시발 

# print(sorted(list(table_hash.items()), key=tuple[0], reverse=True))


### 이것의 목적 정렬이 되나 보기 