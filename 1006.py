#1006
N = int(input())
lst01 = []
lst02 = []
for _ in range(N):
    lst01.append(input().split())
lst01.sort(key=lambda x: x[1])
lst02.append(lst01[0][0])
lst01.sort(key=lambda x: x[2])
lst02.append(lst01[-1][0])
print(*lst02)