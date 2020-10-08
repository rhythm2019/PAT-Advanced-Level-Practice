# 1042
lst01 = []
for C1 in 'SHCD':
    for C2 in range(1, 14):
        ch = C1 + str(C2)
        lst01.append(ch)
lst01.append('J1')
lst01.append('J2')
lst02 = lst01[:]
rep = int(input())
shuffle_lst = list(map(int, input().split()))
Flag = 0
for i in range(rep):
    if Flag == 0:
        for index_j in range(54):
            lst02[shuffle_lst[index_j] - 1] = lst01[index_j]
        Flag = 1
    else:
        for index_j in range(54):
            lst01[shuffle_lst[index_j] - 1] = lst02[index_j]
        Flag = 0
if Flag:
    print(*lst02)
else:
    print(*lst01)