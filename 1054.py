#1054
M, N = input().split()
lst01 = []
dict01 = dict()
v = 0
index = -1
for _ in range(int(N)):
    lst01 = input().split()
    for color in lst01:
        if color in dict01:
            dict01[color] += 1
        else:
            dict01[color] = 1
        if dict01[color] > v:
            v = dict01[color]
            index = color
print(index)