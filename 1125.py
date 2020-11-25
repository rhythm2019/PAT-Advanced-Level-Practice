#1125 1125 Chain the Ropes (25分)
#DATE:20200820
N = int(input())
lst01 = list(map(int, input().split()))
lst01.sort()
for i in range(N - 1):
    lst01[i + 1] = 0.5 * (lst01[i] + lst01[i + 1])
print(int(lst01[-1]))