# 1035
N = int(input())
result = []
dict01 = {'1': '@', 'l': 'L', '0': '%', 'O': 'o'}
for _ in range(N):
    str1 = input().split()
    nch = []
    Flag = False
    for c in str1[1]:
        if c in dict01:
            nch.append(dict01[c])
            Flag = True
        else:
            nch.append(c)
    if Flag:
        result.append([str1[0], ''.join(nch)])
if result:
    print(len(result))
    for ele in result:
        print(*ele)
else:
    if N == 1:
        print("There is {} account and no account is modified".format(N))
    else:
        print("There are {} accounts and no account is modified".format(N))