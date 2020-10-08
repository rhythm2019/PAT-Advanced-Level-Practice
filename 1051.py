# 1051
M, N, K = map(int, input().split())
result = []
for _ in range(K):
    lst01 = list(map(int, input().split()))
    stack = []
    begin = 1
    while lst01:
        if stack == [] or (stack[-1] < lst01[0] and len(stack) < M):
            stack.append(begin)
            begin += 1
        elif stack[-1] == lst01[0] and len(stack) <= M:
            stack.pop()
            lst01.pop(0)
        else:
            result.append('NO')
            break
    else:
        result.append('YES')
for ele in result:
    print(ele)