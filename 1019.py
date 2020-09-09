# 1019
def trans_base(num: int, b: int) -> list:
    result = []
    while num // b:
        result.insert(0, num % b)
        num = num // b
    result.insert(0, num % b)
    return result


N, b = map(int, input().split())
r1 = trans_base(N, b)
r2 = r1[:]
r2.reverse()
if r1 == r2:
    print('Yes')
else:
    print('No')
print(*r1)