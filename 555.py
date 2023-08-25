
N, M = 10 , 40

omega = M % (N + 1) if M % (N + 1) else N + 1
print(N - omega + 1 ,  M // (N + 1))
print(N - omega + 1 >= M // (N + 1))

# 33 - 7 인 상황 
# 10 9 8 7 4개를 없애야 하는거 아님?
# 