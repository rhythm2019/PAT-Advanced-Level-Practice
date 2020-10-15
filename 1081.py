# 1081
def getSimple(a: int, b: int) -> str:
    if b == 0:
        return 'Inf'
    elif a == 0:
        return ('0')
    elif a % b == 0:
        return str(a // b) if a > 0 else '(' + str(a // b) + ')'
    else:
        sign = 1 if a > 0 else -1
        a = abs(a)
        k = a // b
        a = a % b

        x = a
        y = b
        r = x % y
        while r:
            x = y
            y = r
            r = x % y
        a = a // y
        b = b // y

        if k:
            if sign == 1:
                return '{} {}/{}'.format(k, a, b)
            elif sign == -1:
                return '(-{} {}/{})'.format(k, a, b)
        else:
            if sign == 1:
                return '{}/{}'.format(a, b)
            elif sign == -1:
                return '(-{}/{})'.format(a, b)


N = int(input())
lst01 = input().split()
sum = (0, 1)
for ele in lst01:
    tmp = ele.split('/')
    n1 = int(tmp[0])
    m1 = int(tmp[1])
    n2 = sum[0]
    m2 = sum[1]
    sum = (n1 * m2 + n2 * m1, m1 * m2)
print(getSimple(sum[0], sum[1]))
