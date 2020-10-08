#1046
str1 = list(map(int, input().split()))
N = str1[0]
dict01 = {1: 0}
for i in range(N):
    dict01[i + 2] = dict01[i + 1] + str1[i + 1]

sum_distance = dict01[N + 1]
lst02 = []
for _ in range(int(input())):
    c1, c2 = map(int, input().split())
    d1 = abs(dict01[c2] - dict01[c1])
    d2 = sum_distance - d1
    lst02.append(min(d1, d2))
for element in lst02:
    print(element)
