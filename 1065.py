#1065
lst01 = []
for i in range(int(input())):
    A, B, C = map(int, input().split())
    if A + B > C:
        lst01.append('Case #{}: true'.format(i + 1))
    else:
        lst01.append('Case #{}: false'.format(i + 1))
for ele in lst01:
    print(ele)