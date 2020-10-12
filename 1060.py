# 1060 Are They Equal
def get_num(num1: str, N: int):
    if '.' not in num1:
        num1 += '.0'
    integer, fraction = num1.split('.')
    integer = str(int(integer))
    fraction += '0' * N
    if integer != '0':
        exponent = len(integer)
        result = '0.' + (integer + fraction)[0:N]
    else:
        i = 0
        while i < len(fraction) and fraction[i] == '0':
            i += 1
        if i == len(fraction):
            result = '0.' + '0' * N
            exponent = 0
        else:
            result = '0.' + fraction[i:i + N]
            exponent = -i
    return '{}*10^{}'.format(result, exponent)


N, num1, num2 = input().split()
N = int(N)
s1 = get_num(num1, N)
s2 = get_num(num2, N)
if s1 == s2:
    print('YES', s1)
else:
    print('NO', s1, s2)
