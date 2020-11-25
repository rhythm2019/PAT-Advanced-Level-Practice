#1124
N, fg, begin = map(int, input().split())
lst01 = []
lst02 = []
for _ in range(N):
    lst01.append(input())
i = begin - 1
while i < len(lst01):
    while i < len(lst01) and lst01[i] in lst02:
        i += 1
    if i < len(lst01):
        lst02.append(lst01[i])
        i += fg

if lst02:
    for x in lst02:
        print(x)
else:
    print('Keep going...')