# 1101 Quick Sort (25分)
N = input()
lst01 = list(map(int, input().split()))

# method 1
########
dict01 = set()
result = []
maxV = 0
minV = float('inf')
for i in range(int(N)):
    if lst01[i] > maxV:
        maxV = lst01[i]
        dict01.add(i)
for i in range(int(N) - 1, -1, -1):
    if lst01[i] < minV:
        minV = lst01[i]
        if i in dict01:
            result.append(lst01[i])
result = list(reversed(result))
print(len(result))
print(*result)
########

# method 2
########
lst02 = lst01.copy()
lst02.sort()
result = []
maxV = 0
for i in range(int(N)):
    if lst01[i] > maxV:
        maxV = lst01[i]
        if lst01[i] == lst02[i]:
            result.append(lst01[i])
print(len(result))
print(*result)
########
