#1007
#1007 Maximum Subsequence Sum
N = int(input())
A = list(map(int, input().split()))
i = 0
v_max = A[0]
index = [0, 0]
sum = 0
begin = 0
while i < N:
    sum += A[i]
    if sum < 0:
        i += 1
        begin = i
        sum = 0
        continue
    elif sum > v_max:
        v_max = sum
        index = [begin, i]
    i += 1

if v_max < 0:
    print(0, A[0], A[-1])
else:
    # print(*index)
    print(v_max, A[index[0]], A[index[1]])
