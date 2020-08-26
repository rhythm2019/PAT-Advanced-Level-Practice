# 1004
N, M = map(int, input().split())
dict01 = dict()
for i in range(M):
    tmp = input().split()
    dict01[tmp[0]] = tmp[2:]

# 广度遍历
lst01 = ['01']
lst02 = [0]
tmp1 = lst01[:]
tmp2 = []
while lst01:
    node = lst01.pop(0)
    if node in tmp1:
        if node in dict01:
            lst01.extend(dict01[node])
            tmp2.extend(dict01[node])
        else:
            lst02[-1] += 1
    else:
        # 新的layer
        tmp1 = tmp2[:]
        tmp2 = []
        lst01.insert(0, node)
        lst02.append(0)
print(*lst02)