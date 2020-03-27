#1025
lst01 = []
N = int(input())
for x1 in range(N):
    M = int(input())
    lst02 = []
    for x2 in range(M):
        in01 = input().split()
        in01[1] = int(in01[1])
        in01.append(x1 + 1)
        in01.append(1)
        lst02.append(in01)
    lst02.sort(key=lambda x: (-x[1], x[0]))
    for i in range(1, M):
        if lst02[i][1] != lst02[i - 1][1]:
            lst02[i][-1] = i + 1
        else:
            lst02[i][-1] = lst02[i - 1][-1]
    lst01.extend(lst02)

lst01.sort(key=lambda x: (-x[1], x[0]))
print(len(lst01))
print("{x[0]} 1 {x[2]} {x[3]}".format(x=lst01[0]))
rank = 1
for i in range(1, len(lst01)):
    if lst01[i][1] != lst01[i - 1][1]:
        rank = i + 1
    print("{x[0]} {y} {x[2]} {x[3]}".format(x=lst01[i], y=rank))