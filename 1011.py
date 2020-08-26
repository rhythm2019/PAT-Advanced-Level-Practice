#1011
value = 1.0
lst01 = []
for _ in range(3):
    W, T, L = map(float, input().split())
    if W >= T and W >= L:
        lst01.append('W')
        value *= W
    elif T >= W and T >= L:
        lst01.append('T')
        value *= T
    else:
        lst01.append('L')
        value *= L
lst01.append('{0:.2f}'.format((value * 0.65 - 1) * 2 + 0.0001))
print(*lst01)