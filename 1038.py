#1038 Recover the Smallest Number (30分)
#DATE:202008
input = input().split()
N = int(input[0])
NUM = input[1:]
NUM.sort()
result = ""
i = 0
while (i <= N - 2):
    if (NUM[i] + NUM[i + 1] > NUM[i + 1] + NUM[i]):
        result = result + NUM[i + 1]
        NUM[i + 1] = NUM[i]
        i += 1
    else:
        result = result + NUM[i]
        i += 1
result = result + NUM[N - 1]
print(int(result))
