#1149
N, M = map(int, input().split())
dict01 = dict()
for _ in range(N):
    x1, x2 = input().split()
    if x1 not in dict01:
        dict01[x1] = [x2]
    else:
        dict01[x1].append(x2)
    if x2 not in dict01:
        dict01[x2] = [x1]
    else:
        dict01[x2].append(x1)
for _ in range(M):
    Flag = True
    lst01 = input().split()
    N1 = int(lst01[0])
    for i in range(1, N1):
        if lst01[i] in dict01:
            for ele in lst01[i + 1:]:
                if ele in dict01[lst01[i]]:
                    print('No')
                    Flag = False
                    break
        if Flag == False:
            break
    else:
        print('Yes')