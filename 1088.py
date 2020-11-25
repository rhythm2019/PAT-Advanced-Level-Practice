# -*- coding: utf-8 -*-
#1088
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


def calSimple(n1: int, m1: int, n2: int, m2: int, ope: str) -> tuple:
    if ope == '+':
        return (n1 * m2 + n2 * m1, m1 * m2)
    elif ope == '-':
        return (n1 * m2 - n2 * m1, m1 * m2)
    elif ope == '*':
        return (n1 * n2, m1 * m2)
    elif ope == '/':
        if n2 >= 0:
            return (n1 * m2, m1 * n2)
        else:
            return (-n1 * m2, -m1 * n2)


num1, num2 = input().split()
a1, b1 = map(int, num1.split('/'))
a2, b2 = map(int, num2.split('/'))
for ch in '+-*/':
    result = calSimple(a1, b1, a2, b2, ch)
    print('{0} {1} {2} = {3}'.format(getSimple(a1, b1), ch, getSimple(a2, b2),
                                     getSimple(result[0], result[1])))
