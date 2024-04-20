print(8//(2*(2+2)))

def yamche(input):
    for _ in range(10):
        input=round(input*(3/5),4)
        print(input)


yamche(100)
                
        
number = 358

rem = rev = 0
while number >= 1:
    rem = number % 10
    rev = rev * 10 + rem
    number = number // 10

print(rev)