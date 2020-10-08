#1048
N, M = map(int, input().split())
lst01 = list(map(int, input().split()))
lst01.sort()
dict01 = dict()
for ele in lst01[::-1]:
    if ele in dict01:
        dict01[ele] += 1
    elif ele >= M // 2:
        dict01[ele] = 1

for ele in lst01:
    if M - ele in dict01:
        if ele != M - ele or (ele == M - ele and dict01[ele] >= 2):
            print(ele, M - ele)
            break
    elif ele > M // 2:
        print("No Solution")
        break
else:
    print("No Solution")
