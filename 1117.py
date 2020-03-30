#1117 Eddington Number (25分)
N = int(input())
lst01 = list(map(int, input().split()))
lst01.sort(reverse=True)
for i in range(N):
    if lst01[i] <= i + 1:
        print(i)
        break
else:
    print(N)
