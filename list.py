""" 
    리스트에 더하기 연산 어떻게 작동하는지좀 확인
    """
    
i = [] 
for j in range(10):
    i += [j]
    
print(i)

"""

list + list 형식만 지원하는 것 같다 
iterable하네 마네로 싸웠음
Keyword arguments:
argument -- description
Return: return_description
"""
# print([] + range(4))

'''
concatenate 하지 않다 
'''

i = [] 
for j in range(10):
    i += [ j ]
    
print(i)
'''
list 명시적 형변환할때 iterable한 애들만 가능한 것 같다 
'''
b = []
for i in [ 1, 3, 5, 6]:
    b += [i]
    
'''
concatenate 할수있는건 같은 시퀀스 뿐인듯  
'''

print(b)
