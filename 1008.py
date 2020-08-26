#1008
lst01 = list(map(int, input().split()))
lst01[0] = 0
sum = 0
for i in range(0, len(lst01) - 1):
    if lst01[i + 1] - lst01[i] > 0:
        sum += 6 * (lst01[i + 1] - lst01[i]) + 5
    elif lst01[i + 1] - lst01[i] < 0:
        sum += 4 * (lst01[i] - lst01[i + 1]) + 5
    else:
        sum += 5
print(sum)