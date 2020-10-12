# 1070
N, D = map(int, input().split())
inventory = map(float, input().split())
price = map(float, input().split())
lst01 = list(zip(inventory, price))
lst01.sort(key=lambda x: x[1] / x[0], reverse=True)
i = 0
sum = 0
while D > 0 and i < N:
    if lst01[i][0] >= D:
        sum += lst01[i][1] * D / lst01[i][0]
        break
    else:
        sum += lst01[i][1]
        D = D - lst01[i][0]
        i += 1
print('{:.2f}'.format(sum))