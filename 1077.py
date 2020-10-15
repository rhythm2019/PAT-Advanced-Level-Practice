# 1077
N = int(input())
lst01 = []
for _ in range(N):
    lst01.append(input())
i = -1
Flag = True
while Flag:
    if len(lst01[0]) < -i:
        break
    else:
        ch = lst01[0][i]
    index = 1
    while index < len(lst01):
        if len(lst01[index]) < -i or lst01[index][i] != ch:
            Flag = False
            break
        index += 1
    else:
        i -= 1
if i == -1:
    print('nai')
else:
    print(lst01[0][i + 1:])
