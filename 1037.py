#1037
Nc = int(input())
lst01 = list(map(int, input().split()))
Np = int(input())
lst02 = list(map(int, input().split()))
lst01.sort(reverse=True)
lst02.sort(reverse=True)
i = 0
sum = 0
while i < min(Nc, Np):
    if lst01[i] > 0 and lst02[i] > 0:
        sum += lst01[i] * lst02[i]
        i += 1
    else:
        break
if i < min(Nc, Np):
    index_j = -1
    while index_j >= i - min(Nc, Np):
        if lst01[index_j] < 0 and lst02[index_j] < 0:
            sum += lst01[index_j] * lst02[index_j]
            index_j -= 1
        else:
            break
print(sum)
