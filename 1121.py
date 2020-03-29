#1121 Damn Single (25分)
ID = [-1] * 100000
N = int(input())
for _ in range(N):
    g1, g2 = map(int, input().split())
    ID[g1] = g2
    ID[g2] = g1
N = int(input())
set01 = set(input().split())
lst01 = []
for ele in set01:
    if ID[int(ele)] == -1:
        lst01.append(ele)
    elif "{:0>5d}".format(ID[int(ele)]) not in set01:
        lst01.append(ele)
lst01.sort()
print(len(lst01))
if lst01:
    print(*lst01)