# 1107 Social Clusters (30分)
'''
Hobby[1001]
Father[N+1]
'''


def find_father(p1: int, Father: list) -> int:
    while Father[p1] != p1:
        p1 = Father[p1]
    return p1


def union(p1: int, p2: int, Father: list):
    r1 = find_father(p1, Father)
    r2 = find_father(p2, Father)
    if r1 != r2:
        Father[r1] = r2
    return


N = int(input())
Father = [i for i in range(N + 1)]
Hobby = [[] for _ in range(1001)]
#input
for i in range(N):
    # 3: 2 7 10
    s = input()
    for ele in s.split()[1:]:
        ele = int(ele)
        if Hobby[ele]:
            union(i + 1, Hobby[ele][0], Father)
        Hobby[ele].append(i + 1)

result = dict()
for i in range(1, N + 1):
    r1 = find_father(i, Father)
    if r1 in result:
        result[r1] += 1
    else:
        result[r1] = 1
result = list(result.values())
result.sort(reverse=True)
print(len(result))
print(*result)