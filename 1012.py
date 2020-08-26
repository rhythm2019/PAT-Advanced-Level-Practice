#1012
def get_rank(lst01: list) -> list:
    index = ['A', 'C', 'M', 'E']
    lst02 = lst01[:]
    lst02.sort()
    return [lst02[0], index[lst01.index(lst02[0])]]


N, M = map(int, input().split())
#input
lst01 = []
dict01 = dict()
# student
lst02 = []
rank_lst = []
for _ in range(N):
    tmp = input().split()
    tmp[1:] = list(map(int, tmp[1:]))
    lst01.append(tmp)
    dict01[tmp[0]] = list()
for _ in range(M):
    lst02.append(input())

lst01.sort(key=lambda x: x[1] + x[2] + x[3], reverse=True)
rank = 1
for i in range(len(lst01)):
    if i-1>=0 and (lst01[i][1]+lst01[i][2]+lst01[i][3])== \
        (lst01[i-1][1]+lst01[i-1][2]+lst01[i-1][3]):
        dict01[lst01[i][0]] = [rank]
    else:
        dict01[lst01[i][0]] = [i + 1]
        rank = i + 1

lst01.sort(key=lambda x: x[1], reverse=True)
for i in range(len(lst01)):
    if i - 1 >= 0 and (lst01[i][1] == lst01[i - 1][1]):
        dict01[lst01[i][0]] = dict01[lst01[i][0]] + [rank]
    else:
        dict01[lst01[i][0]] = dict01[lst01[i][0]] + [i + 1]
        rank = i + 1

lst01.sort(key=lambda x: x[2], reverse=True)
for i in range(len(lst01)):
    if i - 1 >= 0 and (lst01[i][2] == lst01[i - 1][2]):
        dict01[lst01[i][0]] = dict01[lst01[i][0]] + [rank]
    else:
        dict01[lst01[i][0]] = dict01[lst01[i][0]] + [i + 1]
        rank = i + 1

lst01.sort(key=lambda x: x[3], reverse=True)
for i in range(len(lst01)):
    if i - 1 >= 0 and (lst01[i][3] == lst01[i - 1][3]):
        dict01[lst01[i][0]] = dict01[lst01[i][0]] + [rank]
    else:
        dict01[lst01[i][0]] = dict01[lst01[i][0]] + [i + 1]
        rank = i + 1

for x in lst02:
    if x in dict01:
        print(*get_rank(dict01[x]))
    else:
        print('N/A')