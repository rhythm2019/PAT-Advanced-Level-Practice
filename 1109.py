#1109 Group Photo
from functools import cmp_to_key


def GT(p1: list, p2: list):
    if int(p1[1]) > int(p2[1]):
        return 1
    elif int(p1[1]) < int(p2[1]):
        return -1
    else:
        if p1[0] < p2[0]:
            return 1
        elif p1[0] > p2[0]:
            return -1
        else:
            return 0


N, row = map(int, input().split())
Group = []
for _ in range(N):
    Group.append(input().split())
Group.sort(key=cmp_to_key(GT), reverse=True)
result = []
index_i = 0
for i in range(row, 0, -1):
    if i == row:
        M = N - N // row * (row - 1)
    else:
        M = N // row
    lst01 = [None] * M
    # M为奇数
    if M % 2:
        for j in range(M):
            lst01[M // 2 + (-1)**j * (j + 1) // 2] = Group[index_i][0]
            index_i += 1
    # M为偶数
    else:
        for j in range(M - 1):
            lst01[M // 2 + (-1)**j * (j + 1) // 2] = Group[index_i][0]
            index_i += 1
        lst01[0] = Group[index_i][0]
        index_i += 1       
    print(*lst01)
    result.append(lst01)