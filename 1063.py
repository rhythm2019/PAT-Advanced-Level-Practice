#1063
N = int(input())
lst01 = []
for _ in range(N):
    tmp = input().split()[1:]
    tmp = set(tmp)
    lst01.append(tmp)
M = int(input())
lst02 = []
for _ in range(M):
    x, y = input().split()
    x, y = int(x) - 1, int(y) - 1
    lst02.append((x, y))
for x in lst02:
    result = len(lst01[x[0]].intersection(lst01[x[1]]))
    result = 100 * result / (len(lst01[x[0]]) + len(lst01[x[1]]) - result)
    print('{0:.1f}%'.format(result))